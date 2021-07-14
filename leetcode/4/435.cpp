
#include <bits/stdc++.h>
using namespace std;
#include "../dbg.hpp"

#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

class Solution {
public:
  // 之前的最优化问题就是求解最多可以放下多少啊

  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    // 尽早结束
    auto cmp = [](const vector<int> &a, const vector<int> &b) {
      return a[1] < b[1];
    };

    sort(intervals.begin(), intervals.end(), cmp);
    int end = 0x3f3f3f3f;
    for (int i = 0; i < intervals.size(); ++i) {
      end = min(end, intervals[i][0]);
    }
    
    int ok = 0;
    for (int i = 0; i < intervals.size(); ++i) {
      if(intervals[i][0] >= end ){
        end = intervals[i][1];
        ok ++;
      }
    }
    dbg(intervals);
    return intervals.size() - ok;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int> > a;
  a.push_back({1,4});
  a.push_back({1,2});
  a.push_back({1,3});
  s.eraseOverlapIntervals(a);
  return 0;
}
