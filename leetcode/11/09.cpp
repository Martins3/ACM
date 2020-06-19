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

// 1. 使用 segment tree 的做法应该不错 !
// 2. 使用积分的思想处理

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
      // 0 和 最后的位置
      vector<int> res(n + 2, 0);

      for(auto & k : bookings){
        res[k[0]] += k[2];
        res[k[1] + 1] -= k[2];
      }

      vector<int> R(n, 0);

      R[0] = res[1];

      for (int i = 1; i < n ; ++i) {
        R[i] = R[i - 1] + res[i + 1];
      }

      return R ;
    }
};

int main(){
  return 0;
}
