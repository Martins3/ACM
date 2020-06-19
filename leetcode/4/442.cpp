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
    vector<int> findDuplicates(vector<int>& nums) {
      for (int i = 0; i < nums.size(); ++i) {
        int r = i + 1;
        if(r != nums[i]){
          int ti = nums[i] - 1;
          if(nums[i] != nums[ti]){
            int t = nums[i];
            nums[i] = nums[ti];
            nums[ti] = t;
            i --;
          }
        }
      }

  for(auto g : nums){
    cout << g << " ";
  }
  cout << endl;

      vector<int> x;
      for (int i = 0; i < nums.size(); ++i) {
        if(i + 1 != nums[i]){
          x.push_back(nums[i]);
        }
      }
      return x;
    }
};

int main(){
  Solution s;
  vector<int> a{4,3,2,7,8,2,3,1};
  auto f = s.findDuplicates(a);
  for(auto g : f){
    cout << g << " ";
  }
  return 0;
}
