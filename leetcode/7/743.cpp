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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/OnlineJudge/output.txt", "w", stdout);


class Edge{
public:
    int x;
    int y;
    int w;

    Edge(int x, int y, int w):x(x), y(y), w(w){}

    bool operator < (const Edge & e)const{
        return this->w < e.w;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int> >& times, int N, int K) {
        // make graph
        vector<vector<Edge> > graph(N + 1, vector<Edge>());
        for (unsigned i = 0; i < times.size(); ++i) {
            graph[times[i][0]].push_back(Edge(times[i][0], times[i][1], times[i][2]));
        }

        vector<bool> visited(N + 1, false);
        priority_queue<Edge, vector<Edge> > p;
        vector<int> dis(N + 1, 0x3f3f3f3f);

        p.push(Edge(0, K, 0));
        dis[K] = 0;


        while(!p.empty()){
            Edge e = p.top(); p.pop();
            if(visited[e.y]) continue;
            visited[e.y] = true;

            for(Edge nei : graph[e.y]){
                if(visited[nei.y]) continue;
                if(nei.w + dis[e.y] < dis[nei.y]){
                    dis[nei.y] = dis[e.y] + nei.w;
                    p.push(Edge(0, nei.y,  dis[nei.y]));
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= N; ++i) {
            res = max(res, dis[i]);
        }

        return res;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    return 0;
}
