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
#include <utility>
#include <vector>
#include "../dbg.hpp"

using namespace std;

int table[5001];

// 这是所有的组合可能性啊
class Solution2 {
public:
  int change(int amount, vector<int> &coins) {
    memset(table, 0, sizeof(table));

    table[0] = 1;
    for (int j = 1; j <= amount; ++j) {
      for (unsigned i = 0; i < coins.size(); ++i) {
        if (j - coins[i] >= 0)
          table[j] += table[j - coins[i]];
      }
    }
    return table[amount];
  }
};

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    memset(table, 0, sizeof(table));

    // 每次添加一个硬币得到的结果是什么
    // 没有必要添加排序功能
    table[0] = 1;
    for (unsigned i = 0; i < coins.size(); ++i) {

      for (int j = coins[i]; j <= amount; ++j) {
        // 加入硬币导致的增加的种类
        table[j] += table[j - coins[i]];
      }
    }
    return table[amount];
  }
};
int main() {
  //    REOPEN_READ
  //   REOPEN_WRITE

  Solution s;
  Solution2 s2;
  vector<int> v{1, 2};
  cout << s.change(5, v) << endl;
  cout << s2.change(5, v);
  return 0;
}
