#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;
#define VSCODE_READ freopen("../../../input.txt", "r", stdin);
#define C_READ freopen("input.txt", "r", stdin);

# define VERTEX_NUM 10000
# define EDGE_NUM 10000

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

void initGraph(){
    memset(nodeHead, -1, sizeof(nodeHead));    
    nodePointer = 0;
}

int main(){
    
    return 0;
};