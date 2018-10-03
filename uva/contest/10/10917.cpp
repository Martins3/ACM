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


#define VERTEX_NUM (1000 + 10)
class Edge{
   public:
       int x;
       int y;
       int weight = 0;
       Edge(){};
       Edge(int x, int y):x(x), y(y){}
       Edge(int x, int y, int weight):x(x), y(y), weight(weight){}
};

vector<Edge> graph[VERTEX_NUM];

void add_w_edge(int x, int y, int weight){
    graph[x].push_back(Edge(x, y, weight));
}

void add_edge(int x, int y){
    graph[x].push_back(Edge(x, y));
}

void initGraph() {
    for(int i = 0; i < VERTEX_NUM; i++) graph[i].clear();
}

#define INF 0x3f3f3f3f

class Node{
public:
    int x;
    int w;  
    bool operator < (const Node & e) const{
         return w > e.w; 
    }
    Node(int x, int w): x(x), w(w){};
};

int dis[VERTEX_NUM];
bool vis[VERTEX_NUM];




void dijkstra(){
    memset(dis, INF, sizeof(dis));
    memset(vis, false, sizeof(vis));

    dis[2] = 0;
    priority_queue<Node> pq;
    pq.push(Node(2, 0));

    while(!pq.empty()){
        Node n = pq.top(); pq.pop();
        if(vis[n.x]) continue;

        vis[n.x] = true; 
        for(int i = 0; i < graph[n.x].size(); i++){
            const Edge & e = graph[n.x][i];
            if(vis[e.y]) continue;

            if(dis[n.x] + e.weight < dis[e.y]){
                dis[e.y] = dis[n.x] + e.weight;
                pq.push(Node(e.y, dis[e.y]));
            }
        }
    }
}



void make_graph(){
    initGraph();
    int M;
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        add_w_edge(x, y, z);
        add_w_edge(y, x, z);
    }
}



int N;
int num[VERTEX_NUM];

void dp(int x){
    if(x == 2) return;
    
    int sum = 0;
    for(int i = 0; i < graph[x].size(); i++){
        int y = graph[x][i].y;
        if(dis[x] <= dis[y]) continue;
        if(num[y] == -1) dp(y);
        sum += num[y];
    }
    num[x] = sum;
}


void solve(){
   memset(num, -1, sizeof(num));
   num[2] = 1;
   dp(1);
   printf("%d\n", num[1]);
}


int in;
int main(){
    REOPEN_READ
    REOPEN_WRITE
    
    while(scanf("%d", &N) == 1 && N != 0){
        in ++;
        make_graph();
        dijkstra();
        solve();
    } 
    return 0;
}

/**
 * 错误log:
 * 1. dp 中间出现错误， 将变量书写错误 ！
 * 2. 思维江化， 没有必要生成dag 出来
 * 3. reading 出现错误， from 2 to 1
 * 
 */