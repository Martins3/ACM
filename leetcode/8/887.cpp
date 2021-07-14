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
#include <memory>
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

// 使用 2 分的思路其实并不行，因为 100 层楼，2 个鸡蛋，如果使用 2 分，其实需要
// 50 次， 使用 5 分，那么最多只是需要 20 次, 还是应该使用 dp 分析

// 使用 dp 的方法 :
// 状态 : 记录 还有 k 个鸡蛋，测试 n 个楼的方法
// 最优 : 遍历所有楼层，然后找到最优解
#include "../dbg.hpp"

class Solution {
public:
  int superEggDrop(int k, int n) {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; ++i) {
      dp[1][i] = i;
    }

    for (int i = 1; i <= k; ++i) {
      dp[i][0] = 0;
      dp[i][1] = 1;
    }

    for (int i = 2; i <= k; ++i) {
      for (int j = 2; j <= n; ++j) {
        int res = 0x3f3f3f3f;

        int left = 1;
        int right = j;
        while (left != right) {
          int m = (left + right) / 2;
          if (dp[i][j - m] > dp[i - 1][m - 1]) {
            left = m + 1;
          } else {
            right = m;
          }
        }
        int m = right;
        if (dp[i][j - m] > dp[i - 1][m - 1]) {
          exit(1);
        }
        res = min(res, max(dp[i][j - m], dp[i - 1][m - 1]));
        if (m - 1 >= 1) {
          m = m - 1;
          if (dp[i][j - m] <= dp[i - 1][m - 1]) {
            exit(1);
          }
        }
        res = min(res, max(dp[i][j - m], dp[i - 1][m - 1])) + 1;

        dp[i][j] = res;
      }
    }

    // dbg(dp);
    return dp[k][n];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.superEggDrop(5, 5000);
  return 0;
}
