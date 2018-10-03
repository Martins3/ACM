//
// Created by Martin on 2018/1/31.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;
#define VSCODE_READ freopen("../../../input.txt", "r", stdin);
#define C_READ freopen("input.txt", "r", stdin);

# define VERTEX_NUM (100 * 100)
# define EDGE_NUM (100 * 100 * 8)

class Edge{
   public:
       int y;
       int head;
       int weight;
       Edge(){};
       Edge(int y, int head):y(y), head(head){}
       Edge(int y, int head, int weight):y(y), head(head), weight(weight){}

   };
int nodeHead[VERTEX_NUM];
int nodePointer;
Edge graph[EDGE_NUM];

void addWeightedEdge(int x, int y, int weight){
       graph[nodePointer] = Edge(y, nodeHead[x], weight);
       nodeHead[x] = nodePointer;
       nodePointer ++;
   }

void addEdge(int x, int y){
       graph[nodePointer] = Edge(y, nodeHead[x]);
       nodeHead[x] = nodePointer;
       nodePointer ++;
   }

void initGraph() {
    memset(nodeHead, -1, sizeof(nodeHead));
    nodePointer = 0;
}

// make the edge can not a zero
# define LEN 102
int nodes[LEN][LEN];

void makeGraph(int depth, int width){
    for (int i = 1; i < depth + 1; ++i) {
        for (int j = 1; j < width + 1; ++j) {
            if(!nodes[i][j]) continue;

            if(nodes[i - 1][j + 1]) addEdge(i * width + j, (i - 1) * width + (j + 1));
            if(nodes[i - 1][j - 1]) addEdge(i * width + j, (i - 1) * width + (j - 1));
            if(nodes[i - 1][j    ]) addEdge(i * width + j, (i - 1) * width + (j    ));

            if(nodes[i + 1][j + 1]) addEdge(i * width + j, (i + 1) * width + (j + 1));
            if(nodes[i + 1][j - 1]) addEdge(i * width + j, (i + 1) * width + (j - 1));
            if(nodes[i + 1][j    ]) addEdge(i * width + j, (i + 1) * width + (j    ));

            if(nodes[i    ][j - 1]) addEdge(i * width + j, (i    ) * width + (j - 1));
            if(nodes[i    ][j + 1]) addEdge(i * width + j, (i    ) * width + (j + 1));
        }
    }
}

int visited[VERTEX_NUM];


/**
 * for every node, make a dfs
 * make sure it's not visited
 */
void dfs(int start){
    visited[start] = 1;
    for (int i = nodeHead[start]; i != -1 ; i = graph[i].head) {
        int y = graph[i].y;
        if(!visited[y]) dfs(y);
    }
}


int main(){
    C_READ
    int N, M;
    while(true){
        scanf("%d %d", &N, &M);
        if(M || N) break;


        for (int i = 1; i < N + 1; ++i) {
            for (int j = 1; j < M + 1; ++j) {
                int c = getchar();
                if (c == '*') {
                    nodes[i][j] = 0;
                } else {
                    nodes[i][j] = 1;
                }
            }
            getchar();
        }
        makeGraph(N, M);
        int ans = 0;
        for (int i = 1; i < N + 1; ++i) {
            for (int j = 1; j < M + 1; ++j) {
                int start = i * M + j;
                if(!visited[start]){
                    ans ++;
                    dfs(start);
                }
            }
        }

        initGraph();
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}