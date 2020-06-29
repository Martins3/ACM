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

// 这是典型的 区间相等的做法
// 循环之前进行清零
class Solution {
public:
  int countTriplets(vector<int> &arr) {
    int len = arr.size();
    int res = 0;

    int a, b;
    for (int i = 0; i < len; ++i) {
      a = 0;
      for (int j = i + 1; j < len; ++j) {
        a ^= arr[j - 1];
        b = 0;
        for (int k = j; k < len; ++k) {
          b ^= arr[k];
          if (a == b)
            res++;
        }
      }
    }
    return res;
  }
};

int main() { return 0; }
