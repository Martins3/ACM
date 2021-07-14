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
    vector<int> partitionLabels(string S) {
      vector<int> x(26, -1);

      for (int i = 0; i < S.length(); ++i) {
        x[S[i] - 'a'] = i;
      }

      vector<int> g;
      g.push_back(-1);
      
      int cur = 0;
      for (int i = 0; i < S.length(); ++i) {
        int k = x[S[i] - 'a'];
        cur = max(k, cur);
        if(i == cur) g.push_back(i);
      }

      vector<int> res;
      for (int i = 1; i < g.size(); ++i) {
        res.push_back(g[i] - g[i - 1]);
      }

      return res;
    }
};

int main(){
  
  return 0;
}
