#include <bits/stdc++.h>
using namespace std;
#include "../dbg.hpp"

class Solution {
  typedef pair<int, pair<int, int>> Elm;

  // X 的角度，毕竟每一次都是存在 X 的内容的
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    priority_queue<Elm, vector<Elm>, std::greater<Elm>> pq;
    vector<vector<int>> ans;
    if (nums1.size() == 0 || nums2.size() == 0)
      return ans;

    vector<int> X(nums1.size(), 0);

    X[0]++;

    pq.push(make_pair(nums1[0] + nums2[0], make_pair(0, 0)));

    for (int i = 0; i < k && !pq.empty(); ++i) {
      Elm a = pq.top();
      pq.pop();

      int x = a.second.first;
      int y = a.second.second;
      ans.push_back(vector<int>{nums1[x], nums2[y]});

      if (X[x] < nums2.size()) {
        pq.push(make_pair(nums1[x] + nums2[X[x]], make_pair(x, X[x])));
        X[x]++;
      }

      x++;
      if (x < nums1.size() && X[x] < nums2.size()) {
        pq.push(make_pair(nums1[x] + nums2[X[x]], make_pair(x, X[x])));
        X[x]++;
      }
    }

    return ans;
  }
};

#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);
int main(int argc, char *argv[]) {
  Solution s;
  vector<int> a{-10, -4, 0, 0, 6};
  vector<int> b{3, 5, 6, 7, 8, 100};

  auto x = s.kSmallestPairs(a, b, 100);
  for (auto sm : x) {
    dbg(sm);
  }
  return 0;
}
