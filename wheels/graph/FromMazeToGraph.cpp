#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;
#define REOPEN_READ freopen("../input.txt", "r", stdin);
#define REOPEN_WRITE freopen("../output.txt", "w", stdout);

# define VERTEX_NUM (25 * 25)
# define EDGE_NUM (25 * 25 * 8)

class Edge{
   public:
       int x;
       int y;
       int head;
       int weight;
       Edge(){};
       Edge(int x, int y, int head):x(x), y(y), head(head){}
       Edge(int x, int y, int head, int weight):x(x), y(y), head(head), weight(weight){}

   };
int nodeHead[VERTEX_NUM];
int nodePointer;
Edge graph[EDGE_NUM];


void addEdge(int x, int y){
       graph[nodePointer] = Edge(x, y, nodeHead[x]);
       nodeHead[x] = nodePointer;
       nodePointer ++;
   }

void initGraph() {
    memset(nodeHead, -1, sizeof(nodeHead));
    nodePointer = 0;
}

int depth;
int width;
char maze[25][25];

void readMaze(){
    for(int i = 0; i < depth; i++){
        for(int j = 0; j < width; j++){
            char c = '\0';
            while(c == '\n' || c == ' ' || c == '\0'){
                c = getchar();
            }
            maze[i][j] = c;
        }
    }    
}

bool isOut(int x, int y){
    if(x < 0 || y < 0 || x >= depth || y >= width){
        return true;
    }    
    return false;
}

void makeGraph(){
    for(int i = 0; i < depth; i++){
        for(int j = 0; j < width; j++){
            if(maze[i][j] == '#') continue;
            int x = i - 1;
            int y = j - 0;
            if(!isOut(x, y) && maze[x][y] != '#'){
                addEdge(i * width + j, x * width + y);
            }

            x = i + 1;
            y = j - 0;
            if(!isOut(x, y) && maze[x][y] != '#'){
                addEdge(i * width + j, x * width + y);
            }

            x = i - 0;
            y = j - 1;
            if(!isOut(x, y) && maze[x][y] != '#'){
                addEdge(i * width + j, x * width + y);
            }

            x = i - 0;
            y = j + 1;
            if(!isOut(x, y) && maze[x][y] != '#'){
                addEdge(i * width + j, x * width + y);
            }
        }
    }
    
}