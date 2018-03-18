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
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

class Solution {
public:
    int width; 
    int depth;
    bool ok(int x, int y, int m, int n, vector<vector<int>>& matrix){
        if(m < 0 || m >= width) return false;
        if(n < 0 || n >= depth) return false;
        if(matrix[m][n] <= matrix[x][y]) return false;
        return true;
    }

    void dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int> >& dp){
        if(dp[x][y] == -1){
            int sub_max = 0;
            int m, n;

            m = x - 1; 
            n = y; 
            if(ok(x, y, m, n, matrix)){
                dfs(m, n, matrix, dp);
                sub_max = max(sub_max, dp[m][n]);
            }

            m = x + 1; 
            n = y; 
            if(ok(x, y, m, n, matrix)){
                dfs(m, n, matrix, dp);
                sub_max = max(sub_max, dp[m][n]);
            }

            m = x; 
            n = y - 1; 
            if(ok(x, y, m, n, matrix)){
                dfs(m, n, matrix, dp);
                sub_max = max(sub_max, dp[m][n]);
            }

            m = x; 
            n = y + 1; 
            if(ok(x, y, m, n, matrix)){
                dfs(m, n, matrix, dp);
                sub_max = max(sub_max, dp[m][n]);
            }

            dp[x][y] = sub_max + 1;
        }
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
         
        width = matrix.size();
        depth = matrix[0].size();

        vector<vector<int>> dp;
        for(int i = 0; i < width; i++){
            dp.emplace_back(depth, -1);
        }

        int res = 0;
        for(int i = 0; i < width; i++){
            for(int j = 0; j < depth; j++){
                dfs(i, j, matrix, dp);
                res = max(res, dp[i][j]);
            }
        }

        return res;
    }
};

int main(){
    REOPEN_READ
    //REOPEN_WRITE
    Solution s;
    vector<vector<int> > matrix;

    vector<int> a{9, 9, 4};
    vector<int> a1{6, 6, 8};
    vector<int> a2{2, 2, 1};

    matrix.push_back(a);
    matrix.push_back(a1);
    matrix.push_back(a2);

    cout << s.longestIncreasingPath(matrix);

    return 0;
}

/**
 * 矩阵为的空的时候没有分析过的
 */