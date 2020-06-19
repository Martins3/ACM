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
  bool test(vector<vector<bool>> &used, int i, int j, string & word, vector<vector<char>> &board, int index) {
    if(index == word.size()) return true;

    if (i < 0 || j < 0 || i >= board.size() || j >=board[0].size())
      return false;
    if (used[i][j])
      return false;


    if(word[index] == board[i][j]) {
      used[i][j] = true;
      if (test(used, i - 1, j, word, board, index + 1)) return true;
      if (test(used, i + 1, j, word, board, index + 1)) return true;
      if (test(used, i, j - 1, word, board, index + 1)) return true;
      if (test(used, i, j + 1, word, board, index + 1)) return true;
      used[i][j] = false;
    }
    return false;
  }

public:
  bool exist(vector<vector<char>> &board, string word) {
    vector<vector<bool>> used(board.size(), std::vector<bool>(board[0].size(), false));

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
         if(test(used,i, j, word, board, 0)) return true;
        }
      }
    return false;
  }
};

int main() { 
  Solution s;
  vector<vector<char>> v{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  s.exist(v, "ABCCED");
  return 0; }

  /**
   * 错误原因 : 居然写递归，出现了 segment fault 的错误，好吧，居然是范围判断错误 !
   * 措施:
   */
