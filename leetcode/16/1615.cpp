#include "../info.hpp"
#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int maximalNetworkRank(int n, vector<vector<int>> &roads) {
    vector<vector<int>> neighbor(n);
    for (int i = 0; i < n; ++i) {
      neighbor[i].push_back(i);
    }
    for (auto x : roads) {
      neighbor[x[0]].push_back(x[1]);
      neighbor[x[1]].push_back(x[0]);
    }
    sort(neighbor.begin(), neighbor.end(),
         [](vector<int> &a, vector<int> &b) -> bool {
           return a.size() > b.size();
         });

    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (neighbor[i].size() + neighbor[j].size() <= res)
          break;
        auto find =
            find_if(neighbor[i].begin() + 1, neighbor[i].end(),
                    [j, &neighbor](int x) { return x == neighbor[j][0]; });
        auto roads = neighbor[i].size() + neighbor[j].size() - 2;

        if (find != neighbor[i].end())
          roads--;
        if (roads > res)
          res = roads;
      }
    }
    return res;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int>> vec{{0, 1}, {0, 3}, {1, 2}, {1, 3}};
  cout << s.maximalNetworkRank(4, vec);
  return 0;
}
