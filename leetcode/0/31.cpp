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
#include <memory>
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
class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    if (is_sorted(nums.begin(), nums.end(),
                  [](const int a, const int b) -> bool { return b < a; })) {
      reverse(nums.begin(), nums.end());
      // TODO test it
      return;
    }

    for (int i = nums.size() - 2; i >= 0; --i) {
      // who is smaller than me and break immediately
      int diff = 0x3f3f3f3f;
      int target = -1;
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[i] < nums[j] && (nums[j] - nums[i] < diff)) {
          diff = nums[j] - nums[i];
          target = j;
        }
      }

      if (diff != 0x3f3f3f3f) {
        int tmp = nums[i];
        nums[i] = nums[target];
        nums[target] = tmp;
        sort(nums.begin() + i + 1, nums.end());
        return;
      }
    }
  }
};

// 思路完全错了
// 
int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums{1, 3};
  s.nextPermutation(nums);
  for(auto x : nums){
    cout << x  << " ";
  }
  return 0;
}
