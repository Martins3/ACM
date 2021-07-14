#include <bits/stdc++.h>
using namespace std;
#include "../dbg.hpp"

#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

class Solution {
public:
  // 应该是按照长度来分析的吧

  int longestPalindromeSubseq(string s) {
    auto LEN = s.length();
    vector<vector<int>> dp(LEN, vector<int>(LEN));
    // dp[i][j] 表示从 i 到 j 的 , 左右都包括

    for (int i = 0; i < LEN; ++i) {
      dp[i][i] = 1;
    }

    for (int length = 2; length <= LEN; ++length) {
      for (int i = 0;; ++i) {
        int j = i + length - 1;
        if (j >= LEN)
          break;

        if (s[i] == s[j]) {
          if (i - 1 > j - 1)
            dp[i][j] = 2;
          else
            dp[i][j] = 2 + dp[i + 1][j - 1];
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }
    dbg(dp);
    return dp[0][LEN - 1];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.longestPalindromeSubseq("bbbab");
  return 0;
}
