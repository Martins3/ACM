#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    int gg[10010];
    stack<int> stk;

    for (int j = 0; j < nums2.size(); ++j) {
      int y = nums2[nums2.size() - 1 - j];

      while (!stk.empty() && stk.top() < y) {
        stk.pop();
      }

      if (stk.empty()) {
        gg[y] = -1;
      } else {
        gg[y] = stk.top();
      }
    }
    vector<int> res;
    for (auto n : nums1) {
      res.push_back(gg[n]);
    }

    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
