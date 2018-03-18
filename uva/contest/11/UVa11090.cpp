/**
 * 似乎题目假设了所有weight > 0
 */
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

#define VERTEX_NUM (53)
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


void initGraph() {
    for(int i = 0; i < VERTEX_NUM; i++) graph[i].clear();
}

int C;
int N, M;

#define INF 0x3f3f3f3f
bool in_queue[VERTEX_NUM];
int dis[VERTEX_NUM];
int cnt[VERTEX_NUM];

bool negative_cycle(){
    // start from 1
    queue<int> q;
    memset(in_queue, false, sizeof(in_queue)); // 当节点不在队列中间的时候添加
    memset(dis, INF, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));

    q.push(1);
    in_queue[1] = true;
    dis[1] = 0;
    cnt[1] = 1;

    while(!q.empty()){
        int x = q.front(); q.pop();
        
        for(int i = 0; i < graph[x].size(); i++){
            int y = graph[x][i].y;
            int w = graph[x][i].weight;
            int d = dis[x] + w;
            if(d > dis[y]){
                dis[y] = d;

                if(!in_queue[y]){
                    q.push(y);
                    in_queue[y] = true;
                    if(cnt[y] ++ > N) return true;
                }
            }
        }
    }
    return false;
}
int main(){
    REOPEN_READ
    scanf("%d", &C);
    for(int case_num = 1; case_num <= C; case_num++){
        scanf("%d %d", &N, &M);
        int R = 0;
        for(int i = 0; i < M; i++){
            int a, b, c;
            add_w_edge(a, b, c);
            R = max(c, R);
        }

    }
    return 0;
}
