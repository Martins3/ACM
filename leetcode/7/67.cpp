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

// 这个题目虽然容易，但是并没有清晰的证明为什么
class Solution {
public:
    int can(vector<int> & vec, int skip){
      int m = 0; // 只有 > 0 才可以进入
      int res = -1;
      for (int i = 0; i < 26; ++i) {
        if(i == skip) continue;
        
        if(m < vec[i]){
          m = vec[i];
          res = i;
        }
      }
      vec[res] --;
      return res;
    }
    
    string reorganizeString(string S) {
      vector<char> res;
      vector<int> count(26,0 );
      for(auto c : S){
        count[c - 'a'] ++;
      } 
      int c = -1;
      for (int i = 0; i < S.size(); ++i) {
        c = can(count, c);
        if(c == -1) return "";
        res.push_back('a' + c);
      }

      string s(res.begin(), res.end());
      return s;
    }
};

int main(){
  
  return 0;
}

/**
 * 错误原因 : 没有考虑，将字符用掉之后，字符计数器的变化
 * 措施: 首先设计，然后写代码
 */
