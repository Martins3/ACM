#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
#include <cassert>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

#define VERTEX_NUM (100000 + 10)
class Edge{
   public:
       int x;
       int y;
       int weight;
       Edge(){};
       Edge(int x, int y, int weight):x(x), y(y), weight(weight){}
};

vector<Edge> graph[VERTEX_NUM];

void add_w_edge(int x, int y, int weight){
    graph[x].push_back(Edge(x, y, weight));
}


int N, M;
int weight; // the weight in the search 
bool vis[VERTEX_NUM];

void initGraph() {
    for(int i = 0; i < VERTEX_NUM; i++) graph[i].clear();
}


bool dfs(int x){
    vis[x] = true;
    if(x == N) return true;
    int len = graph[x].size();
    for(int i = 0; i < len; i++){
        Edge & e = graph[x][i];
        if(weight >= e.weight && !vis[e.y]){
            if(dfs(e.y)){
                return true;
            }
        } 
    }
    return false;
}

bool dfs_check(int w){
    weight = w;
    memset(vis, 0, sizeof(vis));
    return dfs(1);
}

int main(){
    REOPEN_READ
    //REOPEN_WRITE
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        add_w_edge(x, y, w);
        add_w_edge(y, x, w);
    }    

    int left = 1;
    int right = 1000000;
    int middle =  left + (right - left) / 2;

    while(left < right){
        if(dfs_check(middle)){
            right = middle;
        }else{
            left = middle + 1;
        }
        middle = left + (right - left) / 2;
    }

    printf("%d\n", middle);
    return 0;
}

/**
 * 办公电话： 87540950
 */