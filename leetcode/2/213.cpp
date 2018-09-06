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

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

//
// 处理环的方法
// 创建四个变量来计算
// A = 首部
// B = 尾部
//

/**
 * 1. 环的长度过小
 * 2. start
 * 3. end
 *
*/
class Solution {
public:

    int rob(vector<int>& nums) {

        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        if(nums.size() == 2) return max(nums[0], nums[1]);

        int max_A_B = nums[0];
        int max_A = 0;
        int max_B = 0;
        int max_ = 0;

        int last_pos = nums.size() - 1;

        for (int i = 1; i < last_pos; i++) {
            int t_max_A_B = max_A + nums[i];
            int t_max_A = max(max_A_B, max_A);

            int t_max_B = max_ + nums[i];
            int t_max_ = max(max_B, max_);

            max_A_B = t_max_A_B;
            max_A = t_max_A;
            max_B = t_max_B;
            max_ = t_max_;
        }

        return max(max(max_A, max_A_B), max(max_ + nums[last_pos] ,max_B));
    }
};

int main(){
    Solution s;

    REOPEN_READ
    vector<int> vec;
    int d;
    while(scanf("%d", &d) == 1){
        vec.push_back(d);
    }

    cout << s.rob(vec);

    return 0;
}
