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

// 实际上可以使用BIT实现
// 如果求和过程中间

typedef long long int lld;
class Solution {
public:

    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;

        int left = 0;
        int right = 0;

        lld sum = 0;
        int res = INT_MAX;
        
        // right 到达最右边的时候可以提前结束
        while(right != nums.size()){

            sum += nums[right];
            right ++;

            while(sum >= s){
                sum -= nums[left];
                res = min(right - left, res);
                printf("%d %d \n", right , left );
                left ++;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};

int main(){
    REOPEN_READ
    vector<int> vec;
    int d;
    
    while(scanf("%d", &d) == 1){
        vec.push_back(d);
    }
    Solution s;
    int ss = 7;
    cout << s.minSubArrayLen(ss, vec);
    
    return 0;
}
