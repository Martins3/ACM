#include "../dbg.hpp"
#include <bits/stdc++.h>
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);
class Solution {
public:
  int get_max(vector<int> &vec, int range) {
    int pos = -1;
    int mini = -1;
    for (int i = 0; i <= range; ++i) {
      if (vec[i] > mini) {
        mini = vec[i];
        pos = i;
      }
    }
    return pos;
  }

  vector<int> pancakeSort(vector<int> &arr) {
    vector<int> res;
    for (int i = arr.size() - 1; i > 0; --i) {
      int pos = get_max(arr, i);
      if (pos == i)
        continue;

      if (pos == 0) {
        res.push_back(i + 1);
        reverse(arr.begin(), arr.begin() + i + 1);
      } else {
        res.push_back(pos + 1);
        res.push_back(i + 1);
        reverse(arr.begin(), arr.begin() + pos + 1);
        reverse(arr.begin(), arr.begin() + i + 1);
      }
      dbg(arr);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> v = {3, 2, 4, 1};

  auto x = s.pancakeSort(v);
  dbg(x);
  dbg(v);
  return 0;
}
