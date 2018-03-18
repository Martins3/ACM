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

int N, M;
# define VERTEX_NUM (110)
# define EDGE_NUM (110 * 110)

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


stack<int> q;
int x, y;
bool vis[110];

void initGraph(stack<int> & q) {
    memset(nodeHead, -1, sizeof(nodeHead));
    nodePointer = 0;
    stack<int> empty;
    swap(q, empty);
    memset(vis, false, sizeof(vis));
}

void dfs(int x){
    vis[x] = true;
    for(int i = nodeHead[x]; i != -1; i = graph[i].head){
        if(vis[graph[i].y]) continue; 
        dfs(graph[i].y);
    }
    q.push(x);
}

int main(){
    REOPEN_READ
    REOPEN_WRITE
    while(true){
        scanf("%d %d", &N, &M);
        if(N == 0 && M == 0) break;
        initGraph(q);
        for(int i = 0; i < M; i++){
            scanf("%d %d", &x, &y);
            addEdge(x, y);
        }
        for(int i = 1; i <= N; i++){
            if(vis[i]) continue;
            dfs(i);
        }

        printf("%d", q.top());
        q.pop();
        while(!q.empty()){
            printf(" %d", q.top());
            q.pop();
        }
        printf("\n");
    }
    return 0;
}