/**
 * 实在是不知道为什么会有runtime error
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;
#define REOPEN_READ freopen("./../input.txt", "r", stdin);
#define REOPEN_WRITE freopen("./../output.txt", "w", stdout);

# define VERTEX_NUM (1000 * 1000)
# define EDGE_NUM (1000 * 1000 * 4)

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

char maze[1000][1000];
int depth;
int width;
int J;
int F;

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

void clear( std::queue<int> &q ){
   std::queue<int> empty;
   std::swap(q, empty);
}
queue<int>  fireQueue;
bool vis[1000 * 1000];
bool onFire[1000 * 1000];

void makeGraph(){
    memset(vis, false, sizeof(vis));
    memset(onFire, false, sizeof(onFire));
    
    F = -1;
    clear(fireQueue);

    for(int i = 0; i < depth; i++){
        for(int j = 0; j < width; j++){
            if(maze[i][j] == '#') continue;
                        
                if(maze[i][j] == 'J') J = i * width + j;
                if(maze[i][j] == 'F') {
                    F = i * width + j;
                    fireQueue.push(F);
                    onFire[F] = true;
                }
                

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


bool onBoard(int pos){
    int x = pos / width;
    int y = pos % width;
    if(x == 0 || x == depth - 1 || y == 0 || y == width -1)
        return true;
    return false;

}

void solve(){
    // handling the kernel problem
    queue<int>  jQueue;
    jQueue.push(J);
    vis[J] = true;


    // 不可以和下一步发生冲突的
    bool ok = false;
    int epoch = 0;
    while(!jQueue.empty()){
        // 处理的fire
        epoch ++;
        int size = fireQueue.size();
        for(int i = 0; i < size; i++){
            int pos = fireQueue.front();
            fireQueue.pop();

            for(int j = nodeHead[pos]; j != -1 ; j = graph[j].head){
                int y = graph[j].y;
                if(!onFire[y]){
                    onFire[y] = true;
                    fireQueue.push(y);
                }
            }
        }

        size = jQueue.size();
        for(int i = 0; i < size; i++){
            int pos = jQueue.front();
            jQueue.pop();
            
            if(onBoard(pos)){
                ok = true;
                break;
            } 

            for(int j = nodeHead[pos]; j != -1 ; j = graph[j].head){
                int y = graph[j].y;
                if(!onFire[y] && !vis[y]){
                    vis[y] = true;
                    jQueue.push(y);
                }
            }
        }
        if(ok) break;
    }
    if(ok)
        printf("%d", epoch);
    else
        printf("IMPOSSIBLE");
}


int main(){
    int N;
    REOPEN_READ
    REOPEN_WRITE
    scanf("%d", &N);
    while(N--){
        scanf("%d %d", &depth, &width);
        readMaze();
        initGraph();        
        makeGraph();
        solve();
        putchar('\n');
    }   
    
    return 0;
}