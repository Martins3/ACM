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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/OnlineJudge/output.txt", "w", stdout);

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();

        int pre = nums[0];
        int res = 1;
        int max_res = 1;
        for (int i = 1;  i < nums.size() ; ++ i) {
            if(nums[i] > pre){
                res ++;
            }else{
                max_res = max(max_res, res);
                res = 1;
            }
            pre = nums[i];
        }
        return max(max_res, res);
    }
};
int main(){
//    REOPEN_READ
//   REOPEN_WRITE


    return 0;
}
