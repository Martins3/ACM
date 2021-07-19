#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<pair<int, int>> s;
    vector<int> res;
    for (int i = temperatures.size() - 1; i >= 0; --i) {
      int v = temperatures[i];

      while (!s.empty() && s.top().first < v) {
        s.pop();
      }
      if (s.empty()) {
        res.push_back(0);
      } else {
        res.push_back(i - s.top().second);
      }
      s.push(make_pair(v, i));
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
