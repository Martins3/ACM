#include <bits/stdc++.h>
using namespace std;

#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

class Solution {
public:
  // 之所以可以动态规划，无论上面如何到达，总是可以
  int minFallingPathSum(vector<vector<int>> &matrix) {
    const int row = matrix.size();
    const int col = matrix[0].size();
    vector<vector<int>> res(row, vector<int>(col, 0));
    res[0] = matrix[0];

    for (int i = 1; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        int l = 0x3f3f3f3f;
        int m = res[i - 1][j];
        int r = 0x3f3f3f3f;
        if (j - 1 >= 0)
          l = res[i - 1][j - 1];

        if (j + 1 < col)
          r = res[i - 1][j + 1];

        res[i][j] = matrix[i][j] + min(min(l, m), r);
      }
    }

    int best = 0x3f3f3f3f;
    for (int i = 0; i < col; ++i) {
      best = min(best, res[row - 1][i]);
    }
    return best;
  }
};
int main(int argc, char *argv[]) { return 0; }
