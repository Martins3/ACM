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

// 考虑的问题 :
class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> reverse(nums.size());

    for (int i = 0; i < nums.size(); i++) {
      reverse[i] = nums[nums.size() - 1 - i];
    }

    int diff = 0x3f3f3f3f;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (j + 1 >= nums.size())
          break;
        int kValue = target - nums[i] - nums[j];
        auto left = lower_bound(nums.begin() + j + 1, nums.end(), kValue);
        auto right =
            lower_bound(reverse.begin(), reverse.end() - j - 1, kValue,
                        [](const int x, const int y) -> bool { return y < x; });
        int leftValue;
        int rightValue;
        if (left != nums.end()) {
          leftValue = *left;
        } else {
          leftValue = nums.back();
        }

        if (right < reverse.end() - j - 1) {
          rightValue = *right;
        } else {
          rightValue = *(reverse.end() - j - 2);
        }

        if (abs(kValue - leftValue) < abs(diff)) {
          diff = kValue - leftValue;
        }
        if (abs(kValue - rightValue) < abs(diff)) {
          diff = kValue - rightValue;
        }

        if (diff == 0) {
          cout << i << " " << j << "fu k" << endl;
          return target;
        }
      }
    }

    return target - diff;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  // vector<int> nums = {-1, 2, 1, -4};
  // auto target = 1;
  
  vector<int> nums = {0, 1, 2};
  auto target = 0;
  cout << s.threeSumClosest(nums, target);
  return 0;
}
