//
// Created by martin on 17-12-26.
// 使用Stack ???
//


// 最短路径 Dij
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
#define Students 30010
#define Relations 150010
#define INF 10000000
int vertexDis[Students];
bool inQueue[Students];

struct Edge{
    int v, w, next;
    Edge(){};
    Edge(int v, int w, int next):v(v), w(w), next(next){}
};

Edge graph[Relations];

int EdgeCount;
int head[Students];

int top;
int relax[Students];

void addEdge(int x, int y, int w){
    graph[EdgeCount] = Edge(y, w, head[x]);
    head[x] = EdgeCount;
    EdgeCount ++;
}






long long minPath(int N) {

    // init the queue
    relax[top ++] = 1;
    vertexDis[1] = 0;
    inQueue[1] = true;

    // loop
    while (top != 0){
        // out
        int X = relax[--top];

        inQueue[X] = false;
        for (int i = head[X]; i != -1; i = graph[i].next) {
            int Y = graph[i].v;
            int weight = graph[i].w;
            if(vertexDis[Y] > vertexDis[X] + weight){
                if(!inQueue[Y]) {
                    inQueue[Y] = true;
                    // into
                    relax[top ++] = Y;
                }
                vertexDis[Y] = vertexDis[X] + weight;
            }
        }
    }
    return vertexDis[N];
}

// minimal value
int main() {

    freopen("input.txt", "r", stdin);
    memset(head, -1, sizeof(head));
    for (int j = 0; j < Students; ++j) {
        vertexDis[j] = INF;
    }

    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int A, B, num;
        scanf("%d%d%d", &A, &B, &num);
        // B - A <= num
        addEdge(A, B, num);
    }

    printf("%lld\n",minPath(N));

}

