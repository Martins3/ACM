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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

class Solution {
public:
    /**
     * radix sort 
     * sort from lower radix to high
     */
    void sort_bit(vector<int>& nums, int bit){
        int ones = 0;
        int mask = 1 << bit;
        
        // count zeros
        for(const int & n : nums) if(mask & n) ones++;
        vector<int> t_nums(nums.size(), 0);
        int one_index = 0;
        int zero_index = ones;
        for(const int & n : nums)
            if(mask & n)
                t_nums[one_index ++] = n;
            else
                t_nums[zero_index ++] = n;
        nums = t_nums;        
    }
    
    int maximumGap(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        for(int i = 0; i < 31; i++) sort_bit(nums, i);
        int last = nums[0];
        int res = 0;
        for(size_t i = 1; i < nums.size(); i++){
            res = max(res, last - nums[i]);
            last = nums[i];
        }
        return res; 
    }
};

int main(){
    REOPEN_READ
    //REOPEN_WRITE
    Solution s;
    vector<int> vec;
    cout << s.maximumGap(vec);
    return 0;
}

