#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

/**
 * 错误原因 : 没有注意到正方形的属性，应该是，可以对于每一个节点逐个判断的
 * 措施:
 */

/**
 * 错误原因 : 对于代码的边界进行修改的时候，只是修改了一部分
 * 措施: 牢记，不可以复制代码，修改代码需要是 atomic 的
 */
class Solution {
public:
  int largest1BorderedSquare(vector<vector<int>> &grid) {
    int x = grid.size();
    int y = grid[0].size();

    int ans = 0;

    vector<vector<pair<int, int>>> dp(x + 1, vector<pair<int,int>>(y + 1, pair<int, int>(0, 0)));

    for (int i = 1; i <= x; ++i) {
      for (int j = 1; j <= y; ++j) {
        // 对于 0 的节点跳过
        if(grid[i-1][j-1] == 0) continue;

        dp[i][j].first += dp[i-1][j].first + 1; // first 记录 上
        dp[i][j].second += dp[i][j-1].second + 1; // second 记录 左

        int pos =  min(dp[i][j].first, dp[i][j].second);

        // 需要测试两个端点到达此处的范围
        for (int k = pos - 1; k >=0; k--) {
          if(dp[i - k][j].second > k){
            // 
          }else {
            continue;
          }

          if(dp[i][j -k].first > k){
            // 
          }else {
            continue;
          }

          ans = max(ans, k + 1);
          
        }
      }
    }

    return ans * ans;
  }
};

int main() { return 0; }
