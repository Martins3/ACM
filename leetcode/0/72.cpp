#include "../dbg.hpp"
#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <forward_list>
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
/**
 * 1. 如果匹配了，那么就进行下一个分析
 * 2. 编辑一个string，直到其和第二个 string 相同
 * 3. dp[i][j] string A [0..i] 和 string B[0..j] 之间的编辑距离
 *
 * dp 的构建需要 行 列 交错的进行的
 *
 * 还可以求解出来操作的方法 : dp[i][j] 记录自己是靠什么方法求解来的，不同的求解方法可以找到上一个位置。
 */

class Solution {
public:
  int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));

    if (min(word1.size(), word2.size()) == 0) {
      return max(word1.size(), word2.size());
    }

    for (int i = 0; i <= word1.size(); ++i) {
      dp[i][0] = i;
    }

    for (int j = 0; j <= word2.size(); ++j) {
      dp[0][j] = j;
    }

    // 下标 i 和 j 在索引 dp 的描述的是长度
    for (int i = 1; i <= word1.size(); ++i) {
      for (int j = 1; j <= word2.size(); ++j) {
        if (word1[i - 1] == word2[j - 1]) { // 如果正好相等, 那么就无需变化 
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
        }
      }
    }
    dbg(dp);

    return dp[word1.size()][word2.size()];
  }
};

int main() {
  Solution s;
  cout << s.minDistance("intention", "execution");
  return 0;
}
