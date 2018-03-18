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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

#define INF 0x3f3f3f3f
#define VERTEX_NUM (50 + 1)




class Solution {
public:
    int dis[VERTEX_NUM][VERTEX_NUM];

    void add_w_edge(int x, int y, int weight){
        dis[x][y] = weight;
        dis[y][x] = weight;
    }

    void initGraph() {
        for(int i = 0; i < VERTEX_NUM; i++){
            for(int j = 0; j < VERTEX_NUM; j++){
                dis[i][j] = INF;
            }
        }
    }
        /**
     * @param n: maximum index of position.
     * @param m: the number of undirected edges.
     * @param x: 
     * @param y: 
     * @param w: 
     * @return: return the minimum risk value.
     */
    
    int getMinRiskValue(int n, int m, vector<int> &x, vector<int> &y, vector<int> &w) {
        // make Graph
        initGraph();
        for(int i = 0; i < m; i++){
            add_w_edge(x[i], y[i], w[i]);
        }

        // 注意对称
        for(int k = 0; k <= n; k++){
            for(int i = 0; i <= n; i++){
                for(int j = 0; j <= n; j++){
                    int d = min(max(dis[i][k], dis[k][j]), dis[i][j]);
                    dis[i][j] = dis[j][i] = d;
                }
            }
        }
        return dis[0][n];
    }
};

int main(){
    REOPEN_READ
    REOPEN_WRITE

    return 0;
}