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

// 似乎dfs 的方法也是含有不同的
class Solution {
public:


    int target;

    bool dfs(vector<int>& side, vector<int>& nums, int index){
        if(index == nums.size()){
             return side[0] == side[1] && side[0] == side[2] && side[0] == side[3];
        }

        for (int i = 0; i < 4; ++i) {
            side[i] += nums[index];
            if(side[i] <= target && dfs(side, nums, index + 1)) return true;
            side[i] -= nums[index];
        }

        return false;
    }



    bool makesquare(vector<int>& nums) {
        if(nums.empty()) return false;
        int sum = 0;
        for (int i : nums) sum += i;
        if(sum & 0x3) return false;

        target = sum / 4;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> visited(4, 0);
        return dfs(visited, nums, 0);
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    vector<int> v{5,5,5,5,16,4,4,4,4,4,3,3,3,3,4};
    cout << s.makesquare(v);
    return 0;
}
