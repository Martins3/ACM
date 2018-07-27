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
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        size_t right = 0;
        int res = INT_MIN;
        while(right < nums.size()){
            sum += nums[right];
            res =  max(res, sum);
            if(sum < 0){
                sum = 0;
            }
            right ++;
        }
        return res;
    }
};

int main(){
    // REOPEN_READ
    // REOPEN_WRITE

    return 0;
}
