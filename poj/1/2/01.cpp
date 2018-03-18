#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>

using namespace std;
#define Interval 50000
long long vertexDis[Interval + 2];
bool inQueue[Interval + 2];

struct Edge{
    int v, w, next;
    Edge(){};
    Edge(int v, int w, int next):v(v), w(w), next(next){}
};

Edge graph[(Interval + 2) * 3];

int EdgeCount;
int head[Interval + 2];

void addEdge(int x, int y, int w){
    graph[EdgeCount] = Edge(y, w, head[x]);
    head[x] = EdgeCount;
    EdgeCount ++;
}




queue<int> relax;



long long minPath() {

    // init the queue
    relax.push(0);
    vertexDis[0] = 1;
    inQueue[0] = true;

    // loop
    while (relax.size() != 0){
        int X = relax.front();
        relax.pop();
        inQueue[X] = false;
        for (int i = head[X]; i != -1; i = graph[i].next) {
            int Y = graph[i].v;
            long long weight = graph[i].w;
            if(vertexDis[Y] < vertexDis[X] + weight){
                if(!inQueue[Y]) {
                    inQueue[Y] = true;
                    relax.push(Y);
                }
                vertexDis[Y] = vertexDis[X] + weight;
            }
        }
    }
    return vertexDis[Interval + 1];
}

// minimal value
int main() {

    freopen("input.txt", "r", stdin);
    memset(head, -1, sizeof(head));
    int N;
    scanf("%d", &N);

    // 节点含义: including

    // 序号up,  size = N + 2
    for (int i = 0; i < N; ++i) {
        int x, y, num;
        scanf("%d%d%d", &x, &y, &num);
        y++;
        addEdge(x, y, num);
    }


    // at most one
    for (int k = 0; k <= Interval; ++k) {
        addEdge(k + 1, k, -1);
    }

    for (int l = 0; l <= Interval ; ++l) {
        addEdge(l, l + 1, 0);
    }


    printf("%lld\n", minPath() - 1);

}
