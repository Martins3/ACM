//
// Created by martin on 17-12-25.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <climits>
#include <queue>
#include <set>

using namespace std;
class Edge{
public:
    int x;
    int y;
    long long weight;
    Edge(int x, int y, int weight):x(x), y(y), weight(weight){};
};


class MinPath{
public:
    vector<vector<Edge> > & graph;
    int N;
    vector<long long> distance;
    set<int> inQueue;
    queue<int> relax;


    long long  minPath();
    MinPath(vector<vector<Edge> >& graph): graph(graph){
        N = graph.size();
        for (int i = 0; i < N; ++i) {
            distance.push_back(INT_MAX / 2);
        }
        distance[1] = 0;
    };
};


long long  MinPath::minPath() {
    // init the queue
    relax.push(1);
    inQueue.insert(1);

    // loop
    int lastVertex = -1;
    while (relax.size() != 0){
        int X = relax.front();
        relax.pop();
        inQueue.erase(X);
        for (int i = 0; i < graph[X].size(); ++i) {
            int Y = graph[X][i].y;
            if(Y == lastVertex) continue; // 对于正数, 没有意义, 对于负数, 造成错误
            long long weight = graph[X][i].weight;
            if(distance[Y] > distance[X] + weight){
                if(inQueue.find(Y) == inQueue.end()){
                    inQueue.insert(Y);
                }
                distance[Y] = distance[X] + weight;
                relax.push(Y);
            }
        }

        lastVertex = X;
        // negative cycle
        if(distance[N - 1] < 0){
            return -1;
        }
    }

    return distance[N - 1];
}

int main() {
    freopen("input.txt", "r", stdin);
    int N, ML, MD;
    scanf("%d%d%d", &N, &ML, &MD);

    vector<vector<Edge> > graph(N + 1);

    // <=
    for (int i = 0; i < ML; ++i) {
        int X, Y, LEN;
        scanf("%d%d%d", &X, &Y, &LEN);
        graph[X].push_back(Edge(X, Y, LEN));
    }


    // >=
    for (int j = 0; j < MD; ++j) {
        int X, Y, LEN;
        scanf("%d%d%d", &X, &Y, &LEN);
        graph[Y].push_back(Edge(Y, X, -LEN));
    }

    // a[i] < a[j]
    for (int k = 1; k < N; ++k) {
        graph[k + 1].push_back(Edge(k + 1, k, 0));
    }

    MinPath minPath(graph);
    long long dis = minPath.minPath();
    if(dis == -1) {
        printf("%d\n", -1);
    } else if(dis == INT_MAX / 2){
        printf("%d\n", -2);
    }else{
        printf("%lld\n", dis);
    }

}

