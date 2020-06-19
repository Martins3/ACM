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
    int minIncrementForUnique(vector<int>& A) {
      int res = 0;
      sort(A.begin(), A.end());
      int max = -1;
    
      for (int i = 0; i < A.size(); ++i) {
        if(A[i] >= max) {
          max = A[i] + 1;
          continue;
        }

        res += max - A[i];
        max = max + 1;
      }

      return res;
    }
};

int main(){
  
  return 0;
}

