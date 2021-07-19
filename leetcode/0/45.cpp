#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <forward_list>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);
/**
 * 计算出来可以到达的最远的距离
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        // 长度为1

        // inclusive
        int left = 0; 
        int right = 0;
        int len = nums.size() - 1;
        int epoch = 0;

        while(right < len){
            int range = 0;
            for(int i = left; i <= right; i++){
                range = max(range, i + nums[i]); 
            }
            left = right + 1;
            right = range;
            epoch ++;
        }

        return epoch;
    }

};

int main(){
    Solution s;
    vector<int> v;
    
    return 0;
}
