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
public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries) {
    vector<bool> res;

    vector<vector<int>> sum(s.length() + 1, vector<int>(26, 0));

    // 想要获取 a 到 b 之间的，
    // sum 表示我的左侧的数量，sum[0] 必然全部都是 0
    for (int i = 1; i <= s.length(); ++i) {
      sum[i] = sum[i - 1];
      sum[i][s[i - 1] - 'a'] ++;
    }

    for (auto &q : queries) {
      int x = q[0];
      int y = q[1];
      q[2] *= 2;
      /* sort(g.begin(), g.end()); */
      /* for(auto x : g){ */
      /*   cout << x << endl; */
      /* } */

      vector<int> work(26, 0);

      for (int i = 0; i < 26; i ++) {
        /* work[g[i] - 'a'] ++; */ 
        work[i] = sum[y + 1][i] - sum[x][i] ;
      }

      for(auto x : work){
        /* cout << x << " "; */
        if(x % 2) {
          q[2] --;
          /* cout << "w" << q[2] << endl; */
        }
      }
      /* cout << endl; */

      /* if(g.size() % 2) q[2] ++; */
      if((y - x  + 1) % 2 ) q[2] ++;

      if (q[2] >= 0)
        res.push_back(true);
      else
        res.push_back(false);
    }
    return res;
  }
};

int main() {
  Solution c;
  vector<vector<int>> x = {{1, 10, 3}};
  auto g = c.canMakePaliQueries("xebyvmjqbmbs", x);
  for(auto m : g){
    cout << m << endl;
  }
  
  return 0;
}

/**
 * 错误原因 : 不应该使用简单的排序，注意替换字符可以同时消除两个不一致性
 * 措施:
 */

/**
 * 错误原因 : 错误的估计算法复杂度，如果字符串很大，而且测试量很大的时候不行，
 * 措施:
 */


/**
 * 错误原因 : 字符串范围没有加以控制
 * 措施: 记住，范围是左开右闭的
 */
