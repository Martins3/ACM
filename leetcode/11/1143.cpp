#include "../dbg.hpp"
#include <bits/stdc++.h>
using namespace std;

#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    auto len1 = text1.size();
    auto len2 = text2.size();
    vector<vector<int>> dp(len1, vector<int>(len2));

    for (int i = 0; i < len1; ++i) {
      for (int j = 0; j < len2; ++j) {
        if (text1[i] == text2[j]) {
          if (i - 1 >= 0 && j - 1 >= 0)
            dp[i][j] = dp[i - 1][j - 1] + 1;
          else
            dp[i][j] = 0 + 1;
        } else {
          int l = 0;
          int r = 0;
          if (i - 1 >= 0)
            l = dp[i - 1][j];
          if (j - 1 >= 0)
            r = dp[i][j - 1];
          // printf("huxueshi:%s %d %d %d %d\n", __FUNCTION__, i, j, l, r);
          dp[i][j] = max(l, r);
        }
      }
    }

    // dbg(dp);
    return dp[len1 - 1][len2 - 1];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  s.longestCommonSubsequence("abc", "adbc");
  return 0;
}
