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
  void rotate(vector<vector<int>> &matrix) {
    int N = matrix.size();
    int I = N - 1;
    for (int level = 0; level < N; level++) {
      int i = level;
      for (int j = level; j < N - level - 1; ++j) {
        int tmp = matrix[I - j][i];
        matrix[I - j][i] = matrix[I - i][I - j];
        matrix[I - i][I - j] = matrix[j][I - i];
        matrix[j][I - i] = matrix[i][j];
        matrix[i][j] = tmp;
      }
    }
  }
};
// 各种大小 ？

int main(int argc, char *argv[]) { return 0; }
