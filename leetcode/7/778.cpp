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

#define maxn 50
class Solution {
public:
    bool vis[maxn][maxn];
    int N;
    int T;
    bool isOut(int x, int y, vector<vector<int>>& grid){
        return x < 0 || y < 0 || x >= N || y >= N || grid[x][y] > T; 
    }

    void add(int x, int y, queue<pair<int, int> >& q, vector<vector<int>>& grid){
        if(!isOut(x, y, grid)){
            if(!vis[x][y]){
                vis[x][y] = true;
                q.push(make_pair(x, y));
            }
        } 
    }

    bool bfs(int m, vector<vector<int>>& grid){
        this->T = m;
        if(grid[0][0] > T) return false;
        
        memset(vis, 0, sizeof(vis[0][0]) * maxn * maxn);
        vis[0][0] = true;
        queue<pair<int,int> > q;
        q.push(make_pair(0, 0));
        bool ok = false;
        
        while(!q.empty()){
            auto p = q.front(); q.pop();
            int x, y;
            if(p.first == N - 1 && p.second == N - 1){
                ok  = true;
                break;
            }
            x = p.first - 1;
            y = p.second;
            add(x, y, q, grid);

            x = p.first + 1;
            y = p.second;
            add(x, y, q, grid);


            x = p.first;
            y = p.second - 1;
            add(x, y, q, grid);
            
            x = p.first;
            y = p.second + 1;
            add(x, y, q, grid);
        }

        if(ok) return true;
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        N = grid.size();
        int l = 1;
        int r = N * N - 1;

        //  求解满足的最小的数值
        int m = l + (r - l) / 2;
        while(l < r){
            if(bfs(m, grid)){
                r = m;
            }else{
                l = m + 1;
            }
            m = l + (r - l) / 2;
        }
        return m;
    }
};
int main(){
    REOPEN_READ
    // REOPEN_WRITE
    Solution s;

    return 0;
}