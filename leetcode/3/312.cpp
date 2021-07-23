#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

class Solution {
public:
  int maxCoins(vector<int> &nums) {
    int LEN = nums.size() + 2;
    vector<vector<int>> dp(LEN, vector<int>(LEN));
    vector<int> points(LEN);

    for (int i = 0; i < LEN - 2; ++i) {
      points[i + 1] = nums[i];
    }
    points[0] = 1;
    points[LEN - 1] = 1;

    // 初始化 size = 1
    for (int i = 0; i < LEN; ++i) {
      int j = i + 1;
      if (j < LEN) {
        dp[i][j] = 0;
      }
    }

    for (int len = 2; len < LEN; ++len) {
      for (int i = 0; i < LEN; ++i) {
        int j = i + len;
        if (j < LEN) {
          int max_v = -1;
          for (int k = i + 1; k < j; ++k) {
            max_v = max(max_v, points[k] * points[i] * points[j] + dp[i][k] +
                                   dp[k][j]);
          }
          dp[i][j] = max_v;
        }
      }
    }
    return dp[0][LEN - 1];
  }
};

int main(int argc, char *argv[]) { return 0; }
