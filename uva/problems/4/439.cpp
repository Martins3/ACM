#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <forward_list>
#include <deque>
#include <set>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

# define VERTEX_NUM (100)
# define EDGE_NUM (100 * 100 * 8)

class Edge{
   public:
       int x;
       int y;
       int head;
       Edge(){};
       Edge(int x, int y, int head):x(x), y(y), head(head){}

   };
int nodeHead[VERTEX_NUM];
int nodePointer;
Edge graph[EDGE_NUM];

void addEdge(int x, int y){
       graph[nodePointer] = Edge(x, y, nodeHead[x]);
       nodeHead[x] = nodePointer;
       nodePointer ++;
}

void directed(int i, int j, int x, int y){
    int m = i + j * 8;
    int n = x + y * 8;
    addEdge(m, n);
}

bool in_board(int x, int y){
    if(x < 0 || y < 0 || x >= 8 || y >= 8) return false;
        return true;
}
void make_graph(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
        int x, y;

        x = i - 2;
        y = j - 1;
        if(in_board(x, y)) directed(i, j, x, y);

        x = i - 2;
        y = j + 1;
        if(in_board(x, y)) directed(i, j, x, y);
            
        x = i - 1;
        y = j - 2;
        if(in_board(x, y)) directed(i, j, x, y);

        x = i - 1;
        y = j + 2;
        if(in_board(x, y)) directed(i, j, x, y);

        x = i + 2;
        y = j - 1;
        if(in_board(x, y)) directed(i, j, x, y);

        x = i + 2;
        y = j + 1;
        if(in_board(x, y)) directed(i, j, x, y);

        x = i + 1;
        y = j - 2;
        if(in_board(x, y)) directed(i, j, x, y);

        x = i + 1;
        y = j + 2;
        if(in_board(x, y)) directed(i, j, x, y);
        }
    }
}

int s;
int t;
bool vis[100];

char source[3];
char terminal[3];


void solve(){
    int step = -1;
    memset(vis, false, sizeof(vis));
    // 参差bfs 而已
    bool find = false;
    queue<int> q;
    q.push(s);
    vis[s] = true;
    
    while(!q.empty()){
        step ++;
        int size = q.size();
        for(int i = 0; i < size; i++){

            int x = q.front(); q.pop();
                // printf("%d\n", x);
            if(x == t){
                find = true;
                break;
            }

            for(int p = nodeHead[x]; p != -1 ; p = graph[p].head){
                int y = graph[p].y;
                if(vis[y]) continue;
                vis[y] = true;
                q.push(y);
            }
        }
        if(find) break;
    }
    printf("To get from %s to %s takes %d knight moves.\n", source, terminal, step);

}

void initGraph() {
    memset(nodeHead, -1, sizeof(nodeHead));
    nodePointer = 0;
}

// 使用从左下角计数
int main(){
   REOPEN_READ
//    REOPEN_WRITE
   initGraph();
   make_graph();

    while(scanf("%s %s", source, terminal) == 2){
        s = (source[0] - 'a') + (source[1] - '1') * 8;
        t = (terminal[0] - 'a') + (terminal[1] - '1') * 8;
        solve();
    }

    return 0;
}