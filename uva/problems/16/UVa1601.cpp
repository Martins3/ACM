#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;
#define UVa freopen("../input.txt", "r", stdin);
#define VSCODE_READ freopen("../../../input.txt", "r", stdin);
#define C_READ freopen("input.txt", "r", stdin);
/**
* make a graph for white space !
* bfs => can not every time, move the node one by one
* we should run by all kinds of priority
* make a stage table => 256 * 256 * 256(2 ^ 24) => 4M
*/

# define VERTEX_NUM 256
# define EDGE_NUM 256 * 4

class Edge{
   public:
       int y;
       int head;
       Edge(){};
       Edge(int y, int head):y(y), head(head){}

   };
int nodeHead[VERTEX_NUM];
int nodePointer;
Edge graph[EDGE_NUM];


void addEdge(int x, int y){
       graph[nodePointer] = Edge(y, nodeHead[x]);
       nodeHead[x] = nodePointer;
       nodePointer ++;
   }

void initGraph() {
    memset(nodeHead, -1, sizeof(nodeHead));
    nodePointer = 0;
}



int main(){
    UVa
    int Width;
    int Height;
    int Num;
    while (scanf("%d %d %d\n", &Width, &Height, &Num)) {
      if(Width == 0 ) break;


    }
    return 0;
}
