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

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.size() < 3) return res;

        sort(nums.begin(), nums.end());


        int len = nums.size();
        int last_i = nums[0] + 1;
        for (int i = 0; i < len - 2; i++) {
            if(nums[i] == last_i) continue;
            last_i = nums[i];

            int last_j = nums[i + 1] + 1;
            for (int j = i + 1; j < len -1; j++) {
                if(nums[j] == last_j) continue;
                last_j = nums[j];
                
                if(nums[i] + nums[j] > 0 & nums[j] >= 0) break;

                auto f = std::lower_bound(nums.begin() + j + 1, nums.end(), -(nums[i] + nums[j]));

                if(f != nums.end() && *f + nums[i] + nums[j] == 0){
                    
                    res.push_back(vector<int>{nums[i], nums[j], *f});
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums{1, 2, -2, -1};
    for(auto k : s.threeSum(nums)){
        for(auto j: k){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
