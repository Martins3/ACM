#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

class Solution {
public:
  void swap(vector<int> &nums, int a, int b) {
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
  }

  void moveZeroes(vector<int> &nums) {
    int l = 0;
    int r = 0;

    while (l < nums.size() && nums[l])
      l++;
    r = l;
    while (true) {
      while (l < nums.size() && nums[l])
        l++;

      if (l == nums.size())
        break;

      while (r < nums.size() && !nums[r])
        r++;

      if (r == nums.size())
        break;

      swap(nums, l, r);
    }
  }
};

int main(int argc, char *argv[]) { return 0; }
