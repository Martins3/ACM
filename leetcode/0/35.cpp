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

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/ACM/leetcode/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/ACM/leetcode/output.txt", "w", stdout);
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int left = 0;
        int right = nums.size();

        // 两个边缘的处理
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};

int main(){
    // REOPEN_READ
    // REOPEN_WRITE

    return 0;
}
