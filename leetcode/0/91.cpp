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

class Solution {
public:
  int len;
  
  int dothis(string &s, int i){
    if(i >= len) return 1;

    if(s[i] == '0') return 0;

    int sum = 0;
    if((s[i] == '1' && i + 1 < len ) || (s[i] == '2' && i + 1 < len && s[i + 1] <= '6' )){
      sum += dothis(s, i + 2);
    }
    sum += dothis(s, i + 1);

    return sum;
  }

  int numDecodings(string s) {
      len = s.length();
      /* return dothis(s, 0); */

      vector<int> dp(len, 0);
      if(s[0] != '0') dp[0] = 1;

      for (int i = 1; i < len; ++i) {
        if(s[i] != '0') dp[i] += dp[i -1];
        if((s[i -1] == '1') || (s[i - 1] == '2'  && s[i] <= '6' )) {
          if(i >= 2)
            dp[i] += dp[i -2];
          else 
            dp[i] += 1;
        }
      }
      return dp[len - 1];
  }
};

int main(){
  Solution s;
  cout << s.numDecodings("226");
  return 0;
}
/**
 * 错误原因 : 没有考虑 一些数值不存在的情况
 * 措施:
 */

/**
 * 错误原因 : 超时，需要使用 dp
 * 措施: 从算法题目的角度分析，不会由于递归而导致算法无法正确运行，而是递归存在不是完全分离的，那么就要考虑使用 dp 了
 */
