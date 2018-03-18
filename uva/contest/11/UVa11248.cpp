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
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

class Edge{
public:
    int x;
    int y;
    int cap;
    int flow;
    Edge(int x, int y, int cap, int flow): x(x), y(y), cap(cap), flow(flow){};
};


#define maxn 105
#define INF  2000000000
class Dinic{
public:
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];  
    int d[maxn]; 

    int cur[maxn]; // 当前弧下标


    void addEdge(int start, int end, int cap){
        edges.push_back(Edge(start, end, cap, 0));
        edges.push_back(Edge(end, start, cap, 0));
        int m = edges.size();
        G[start].push_back(m - 2);
        G[end].push_back(m - 1);
    }

    bool BFS(){
        memset(vis, 0, sizeof(vis));

        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = true;

        while(!Q.empty()){
            int x = Q.front(); Q.pop();
            for(int i = 0; i < G[x].size(); i++){
                Edge & e = edges[G[x][i]];
                if(!vis[e.y] && e.cap > e.flow){
                    vis[e.x] = true;
                    d[e.y] = d[x] + 1;
                    Q.push(e.y);
                } 
            }
        }
        return vis[t];
    }

  
    int dfs(int x, int a){
        if(x == t || a == 0) return a;
        
        int flow = 0, f; 
       
        for(int & i = cur[x]; i < G[x].size(); i++){
            Edge & e = edges[G[x][i]];

            if(d[x] + 1 == d[e.y] && (f = dfs(e.y, min(a, e.cap - e.flow))) > 0){

                e.flow += f;
                edges[G[x][i]^1].flow -= f;
                
                flow += f;
                a -= f;
                if(a == 0) break;
            }
        }
        return flow;
    }

    int maxFlow(int s, int t){
        this->s = s; this->t = t;
        int flow = 0;
        while(BFS()){
            memset(cur, 0, sizeof(cur));
            flow += dfs(s, INF);
        }
        return flow;
    }


    vector<pair<int, int> > possible(){
        // 得到 min-cut

        memset(vis, 0, sizeof(vis));

        queue<int> Q;
        Q.push(s);
        vis[s] = true;

        vector<int> min_cut;

        while(!Q.empty()){
            int x = Q.front(); Q.pop();
            
            for(int i = 0; i < G[x].size(); i++){
                Edge & e = edges[G[x][i]];
                
                if(e.cap == e.flow){
                    min_cut.push_back(G[x][i]); // 添加编号的
                }else{
                    if(vis[e.y]) continue; 
                    vis[e.y] = true;
                    Q.push(e.y);
                }
            }
        }

        // 对于所有边， 逐个枚举处理
        for(int i : min_cut){
            // 需要对于整个图流量备份， 由于使用
        }
    }
    
};

int N, E, C;

int main(){
    // REOPEN_READ
    // REOPEN_WRITE
    int case_num = 0;
    while(scanf("%d %d %d", &N, &E, &C) == 3 && N != 0 && C != 0 && E != 0){
        case_num++;

        Dinic dinic;
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        dinic.addEdge(x, y, c);
        
        int s = dinic.maxFlow(1, N);
        if(s >= C){
            printf("Case %d: possible", case_num);            
        }else{
            
        }

    }   
    

    return 0;
}