#include <bits/stdc++.h>
#include "../dbg.hpp"
using namespace std;

#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

class Solution {
public:
  int minimumDeleteSum(string text1, string text2) {
    auto len1 = text1.size();
    auto len2 = text2.size();

    // dp[i][j] 表示字符串的长度为 i 和 j 的时候的情况
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

    dp[0][0] = 0;
    for (int i = 1; i <= len1; ++i) {
      dp[i][0] = dp[i - 1][0] + text1[i - 1];
    }

    for (int i = 1; i <= len2; ++i) {
      dp[0][i] = dp[0][i - 1] + text2[i - 1];
    }

    for (int i = 1; i <= len1; ++i) {
      for (int j = 1; j <= len2; ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] =
              min(dp[i - 1][j] + text1[i - 1], dp[i][j - 1] + text2[j - 1]);
        }
      }
    }

    // dbg(dp);
    return dp[len1][len2];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.minimumDeleteSum("sea", "eat");
  return 0;
}
