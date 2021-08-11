#include <bits/stdc++.h>
#include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

class Solution {
public:
  string longestPalindrome(string s) {
    // 表示 [i, j] 的范围是否为
    vector<vector<bool>> isPalindrome(s.size(), vector<bool>(s.size(), false));

    pair<int, int> res;
    for (int len = 1; len <= s.size(); ++len) {
      for (int i = 0; i < s.size(); ++i) {
        int j = i + len - 1;
        if(j >= s.size()) continue;
        if (len == 1)
          isPalindrome[i][j] = true;

        if (len == 2 && s[i] == s[j])
          isPalindrome[i][j] = true;

        if (len > 2 && isPalindrome[i + 1][j - 1] && s[i] == s[j])
          isPalindrome[i][j] = true;

        if (isPalindrome[i][j]) {
          res.first = i;
          res.second = j;
        }
      }
    }

    // dbg(isPalindrome);
    return s.substr(res.first, res.second - res.first + 1);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.longestPalindrome("aca");
  return 0;
}
