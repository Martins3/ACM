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

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

class Solution {


  bool tran(vector<vector<char>> &grid, int i, int j) {
    if (grid[i][j] == '0')
      return false;

    std::queue<pair<int, int>> qu;
    grid[i][j] = '0';
    qu.push(make_pair(i, j));

    while (!qu.empty()) {
      auto x = qu.front();
      qu.pop();

      int a = x.first;
      int b = x.second;

      auto f = [&](int l, int r) {
        if (l < 0 || r < 0 || l >= grid.size() || r >= grid[0].size())
          return;

        if (grid[l][r] == '1') {
          qu.push(make_pair(l, r));
          grid[l][r] = '0';
        }
      };

      f(a - 1, b );
      f(a + 1, b);
      f(a , b - 1);
      f(a , b + 1);
    }

    return true;
  }
public:

  int numIslands(vector<vector<char>> &grid) {
    /* vector<vector<bool>> visited(grid.size(),
     * std::vector<bool>(grid[0].size(), false)); */
    int res = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); j++) {
        res += tran(grid, i, j);
      }
    }
    return res;
  }
};

int main() {

  std::queue<pair<int, int>> qu;
  qu.push(make_pair(1, 2));
  qu.push(make_pair(10, 2));
  qu.pop();
  cout << qu.front().first << endl;

  return 0;
}
