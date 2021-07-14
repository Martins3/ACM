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
  int minDominoRotations(vector<int> &A, vector<int> &B) {
    std::vector<int> v;
    for (int i = 1; i <= 6; ++i) {
      int j = 0;
      for (; j < A.size(); ++j) {
        if (A[j] == i || B[j] == i) continue;
        break;
      }
      if(j == A.size()){
        v.push_back(i);
      }
    }
        if(v.empty()) return -1;

    int res = A.size();
    for(auto i : v){
      int g = 0;
      for(auto x : A){
        if(x == i) g ++;
      }
      res = min(res, min(g, (int)A.size() - g));
    }
        for(auto i : v){
      int g = 0;
      for(auto x : B){
        if(x == i) g ++;
      }
      res = min(res, min(g, (int)A.size() - g));
    }


    return res;
  }
};

/**
 * 错误原因 : 没有考虑数值相同的情况
 * 措施:
 */

int main() { return 0; }
