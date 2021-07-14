#include <bits/stdc++.h>
using namespace std;
#include "../dbg.hpp"

#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    set<int> s;
    s.insert(0);

    int sum = 0;
    for (auto x : nums)
      sum += x;

    if (sum % 2)
      return false;

    if (sum == 0)
      return true;

    sum = sum / 2;

    for (auto num : nums) {
      vector<int> adds;
      for (int all : s) {
        auto candidate = all + num;
        if(candidate == sum){
          return true;
        }
        if(candidate > sum) continue;
        adds.push_back(candidate);
      }

      for(auto n : adds){
        s.insert(n);
      }
    }
    // dbg(s);
    return false;
  }
};

int main(int argc, char *argv[]) { 
  Solution s;
  auto v = vector<int>{1,2,3,8};
  cout << s.canPartition(v);

  return 0; 
}
