#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

class Solution {
public:
  int search(vector<int> &nums, int target) {
    if (nums.size() == 0)
      return -1;

    int left = 0;
    int right = nums.size();
    while (left < right) {
      int m = left + (right - left) / 2;
      if (nums[m] >= target) {
        right = m;
      } else {
        left = m + 1;
      }
    }
    if(right == nums.size()) return -1;
    if(nums[right] != target) return -1;
    return right;
  }
};

int main(int argc, char *argv[]) { return 0; }
