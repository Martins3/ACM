#include "../dbg.hpp"
#include <bits/stdc++.h>
using namespace std;

#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);
class Solution {
public:
  int minDistance(string text1, string text2) {
    auto len1 = text1.size();
    auto len2 = text2.size();
    vector<vector<int>> dp(len1, vector<int>(len2));

    for (int i = 0; i < len1; ++i) {
      for (int j = 0; j < len2; ++j) {
        if (text1[i] == text2[j]) {
          if (i - 1 >= 0 && j - 1 >= 0)
            dp[i][j] = dp[i - 1][j - 1];
          else if (i - 1 < 0) {
            dp[i][j] = j;
          } else if (j - 1 < 0) {
            dp[i][j] = i;
          }
        } else {
          if (i == 0 && j == 0) {
            dp[i][j] = 2;
            continue;
          }

          int l = 0x3f3f3f3f;
          int r = 0x3f3f3f3f;

          if (i - 1 >= 0)
            l = dp[i - 1][j];
          if (j - 1 >= 0)
            r = dp[i][j - 1];

          dp[i][j] = min(l, r) + 1;
        }
      }
    }

    dbg(dp);
    return dp[len1 - 1][len2 - 1];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  auto a = "et";
  auto b = "te";
  s.minDistance(a, b);
  return 0;
}
