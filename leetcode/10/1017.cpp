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
  string baseNeg2(int N) {
    vector<int> vec;

    int limit = get_pos(N);
    if(limit == 0){

    }
    assert(limit % 2 == 0);

    for (int i = limit; i > 0 ; i-= 2) {
      if(N > 0){

      }
    }
    


    // int i;
    // do{
      // i = get_pos(N);
      // cout << "[]" << i << endl;
      // vec.push_back(1);
      // N -= 1 << i;
      // i --;
      // if(i < 0) break;
//
      // if(N >= (1 << i)){
        // vec.push_back(1);
      // }else{
        // vec.push_back(0);
      // }
    // } while(i >= 0);

    for(auto i : vec){
      printf("%d ", i);
    }
    return "fuck";
  }

  pair<int, int> get_max_min(int N){

  }

  // 有可能也是含有问题的
  //
  int get_pos(int N) {
    int i;
    int sum =0;
    for (i = 0; i < 32; i += 2) {
      sum += (1 << i);
      if(sum >= N) return i;
    }
    assert(0);
  }
};

int main() { 
  Solution s;
  cout << s.baseNeg2(10);
  return 0;
}
