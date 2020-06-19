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
    int countTriplets(vector<int>& arr) {
      int len = arr.size();
      int res = 0;
      
      int a = 0;
      int b = 0;
      for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
          a ^= arr[j - 1];
          for (int k = j; k < len; ++k) {
            b ^= arr[k];
            if(a == b)  res ++;
          }
        }
        a ^= arr[i];
      }
      return res;
    }
};

int main(){
  
  return 0;
}
