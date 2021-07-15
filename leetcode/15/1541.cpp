#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);
class Solution {
public:
  int minInsertions(string s) {
    int left = 0;
    int need = 0;

    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (c == '(') {
        left++;
      } else {
        if (!left) {
          if (i + 1 < s.size() && s[i + 1] == ')') {
            need++;
            i++;
          } else {
            need += 2;
          }
        } else {
          if (i + 1 < s.size() && s[i + 1] == ')') {
            i++;
          } else {
            need++;
          }
          left--;
        }
      }
    }
    return left * 2 + need;
  }
};

int main(int argc, char *argv[]) { return 0; }
