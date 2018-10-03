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

/**
 * 对于每一个cc 都是可以添加查看中间含有多少个基数， 可以减少为，
 */

int N, M, T;
# define VERTEX_NUM (1010)
# define EDGE_NUM (1000 * 1000)

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

bool vis[VERTEX_NUM];
int odd;
int cc_size;
void initGraph() {
    memset(nodeHead, -1, sizeof(nodeHead));
    nodePointer = 0;
    memset(vis, false, sizeof(vis));
}

void dfs(int s){
    vis[s] = true;
    bool is_odd = false;
    cc_size ++;
    // cout << s << endl;
    for(int i = nodeHead[s]; i != -1 ; i = graph[i].head){
        is_odd = !is_odd;
        if(vis[graph[i].y]) continue;
        dfs(graph[i].y);
    }

    if(is_odd) odd++;
}

int main(){
    REOPEN_READ
   REOPEN_WRITE
    int Case = 1;
    while(scanf("%d %d %d", &N, &M, &T) == 3 && N){
        initGraph();
        for(int i = 0; i < M; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            addEdge(x, y);
            addEdge(y, x);
        }

        int cc_num = 0;
        int vain = 0;
        for(int i = 1; i <= N; i++){
            if(vis[i]) continue;
            odd = 0;
            cc_size = 0;
            dfs(i);
            // cout << endl;
            vain += (max(0, odd - 2) + 1) / 2; 
            if(cc_size > 1) cc_num ++;
        }

        printf("Case %d: %d\n", Case ++, (M + max(0, cc_num - 1) + vain) * T );
    }

    return 0;
}