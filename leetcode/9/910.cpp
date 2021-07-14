#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
#include <cassert>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

// 中间的元素不是被去掉，而是需要被全部填充
// 全部填充 : 中间的元素产生严重的威胁
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
      sort(A.begin(), A.end());
      int x = A.front(); // min
      int y = A.back(); // max
      auto res = y - x;
      // 前面的节点，全部增加，后面的节点全部减少
      for (int i = 0; i < A.size() - 1; ++i) {
        int a = A[0] + K;
        int b = A[i] + K;

        int c = A[i + 1] - K;
        int d = A[A.size() - 1] - K;

        int diff = max(b, d) - min(a, c);
        
        res = min(res, diff);
      }

      return res ;
    }
};

int main(){
  
  return 0;
}

/**
 * 错误原因 : 最后看了答案才搞清楚的
 * 措施:
 */
