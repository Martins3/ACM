#include <bits/stdc++.h>
using namespace std;

#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &intervals) {
    // 尽早结束
    auto cmp = [](const vector<int> &a, const vector<int> &b) {
      return a[1] < b[1];
    };

    sort(intervals.begin(), intervals.end(), cmp);
    long end = 0x3f3f3f3f;
    for (int i = 0; i < intervals.size(); ++i) {
      end = min(end, (long)intervals[i][0]) - 1;
    }

    int ok = 0;
    for (int i = 0; i < intervals.size(); ++i) {
      if (intervals[i][0] > end) {
        end = intervals[i][1];
        ok++;
      }
    }
    // dbg(intervals);
    return ok;
  }
};

int main(int argc, char *argv[]) { return 0; }
