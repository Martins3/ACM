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
       int weight;
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

int s_dis[VERTEX_NUM];
int s_father[VERTEX_NUM];

int e_dis[VERTEX_NUM];
int e_father[VERTEX_NUM];

bool vis[VERTEX_NUM];


void dijkstra(int source, int * dis, int * father){
    memset(dis, INF, sizeof(int) * VERTEX_NUM);
    memset(vis, false, sizeof(vis));
    dis[source] = 0;
    father[source] = source;
    priority_queue<Node> pq;
    pq.push(Node(source, 0));

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
                father[e.y] = n.x;
            }
        }
    }
}


/**
 * 直接的暴力处理， impossible ! 
 * 如果计算出来的从起点到达任何点的距离是什么！
 * memset 是一个问题
 */
int N, S, E;
int M; 
int K;



void make_graph(){
    initGraph();
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        add_w_edge(x, y, z);
        add_w_edge(y, x, z);
    }
}


void permutaiton(){
    scanf("%d", &K);
    int min_dis = INF;
    int l = -1;
    int r = -1;

    for(int i = 0; i < K; i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        int dis = s_dis[x] + z + e_dis[y];
        if(dis < min_dis){
            l = x;
            r = y;
            min_dis = dis;
        }


        dis = s_dis[y] + z + e_dis[x];
        if(dis < min_dis){
            l = y;
            r = x;
            min_dis = dis;
        }
    }

    if(s_dis[E] <= min_dis){
        int n = S;
        while(n != E){
            printf("%d ", n);
            n = e_father[n];
        }

        printf("%d\n", n);
        printf("%s\n","Ticket Not Used");
        printf("%d\n", s_dis[E]);
        return;
    }
    

    // print the route
    stack<int> route;
    int n = l;
    while(n != S){
        route.push(n);
        n = s_father[n];
    }
    route.push(S);
    
    while(!route.empty()){
        printf("%d ", route.top());
        route.pop();
    }

    n = r;
    while(n != E){
        printf("%d ", n);
        n = e_father[n];
    }
    printf("%d\n", E);

    // print l
    printf("%d\n", l);

    //print dis
    printf("%d\n", min_dis);
}


int in;
int main(){
    REOPEN_READ
    REOPEN_WRITE
    while(scanf("%d %d %d", &N, &S, &E) == 3){
        if(in ++) printf("\n");
        make_graph();
        dijkstra(S, s_dis, s_father);
        dijkstra(E, e_dis, e_father);
        permutaiton();
    }
    return 0;
}