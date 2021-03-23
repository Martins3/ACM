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

#include "../dbg.hpp"

class Solution {
public:
  vector<vector<int>> replace(string &s) {
    vector<vector<int>> acc;
    acc.push_back(vector<int>{0, 0, 0, 0, 0});
    for (auto i = 0; i < s.size(); i++) {
      if (i != 0) {
        acc.push_back(acc.back());
      }
      switch (s[i]) {
      case 'a':
        acc[i][0]++;
        break;
      case 'e':
        acc[i][1]++;
        break;
      case 'i':
        acc[i][2]++;
        break;
      case 'o':
        acc[i][3]++;
        break;
      case 'u':
        acc[i][4]++;
        break;
      }
    }
    return acc;
  }

  inline bool ok(const vector<int> &vec, const vector<int> &vec2) {
    for (int i = 0; i < 5; ++i) {
      if ((vec[i] - vec2[i]) % 2)
        return false;
    }
    return true;
  }

  // 为什么循环的次数不会很多? right 的开始位置的限制从当时的最大值开始。
  //
  // 需要计算出来，任意位置的累积量，之后，只需要直接比较即可
  int findTheLongestSubstring(string s) {
    auto acc = replace(s);
    int final_result = -1;

    int left = 0;
    vector<int> counter = {0, 0, 0, 0, 0};
    for (; left < acc.size(); ++left) {
      int res = -1;
      for (int right = left + final_result + 1; right < acc.size(); ++right) {
        if (left == 0) {
          if (ok(acc[right], counter)) {
            res = right;
          }
        } else if (ok(acc[right], acc[left - 1])) {
          res = right;
        }
      }

      if (res - left > final_result) {
        final_result = res - left;
      }
    }
    return final_result + 1;
  }
};

class CorrectSolution {
public:
  int findTheLongestSubstring(string s) {
    std::array<int, 32> pos;
    std::fill(pos.begin(), pos.end(), s.size());
    pos[0] = -1; // 恐怖的边界条件处理, 如果

    int res = 0;
    int val = 0;

    for (int i = 0; i < s.size(); i++) {
      char ch = s[i];
      switch (ch) {
      case 'a':
        val ^= 0b10000;
        break;
      case 'e':
        val ^= 0b01000;
        break;
      case 'i':
        val ^= 0b00100;
        break;
      case 'o':
        val ^= 0b00010;
        break;
      case 'u':
        val ^= 0b00001;
        break;
      }

      if (pos[val] == s.size()) {
        pos[val] = i;
      } else {
        res = std::max(res, i - pos[val]);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.findTheLongestSubstring("a");
  return 0;
}
