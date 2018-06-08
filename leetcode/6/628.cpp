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

    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0x80000000;
        int size = nums.size();

        // 三个正数
        int a = nums[size - 1];
        int b = nums[size - 2];
        int c = nums[size - 3];
        if(a > 0 && b > 0 && c > 0)
            res = max(res, a * b * c);

        // 两个负数
        a = nums[0];
        b = nums[1];
        c = nums[size - 1];
        if(a < 0 && b < 0 && c > 0)
            res = max(res, a * b * c);


        vector<int>::iterator low = std::lower_bound(nums.begin(), nums.end(), 0);
        vector<int>::iterator up = std::lower_bound(nums.begin(), nums.end(), 0);

        // 一个负数
        if(low - nums.begin()  >= 1 && nums.end() - up >= 1){
            res =  max(res, *(low - 1) * nums[size - 1] * nums[size - 2]);
        }


        // 三个负数
        if(low  - nums.begin() >= 3){
            res = max(res,  *(low - 1) * *(low - 2) * *(low - 3));
        }

        // 包含 0
        if(low != nums.end() && *low == 0){
            res = max(res,  0);
        }
        return res;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE
    int res = 0x80000000;
    cout << res << endl;
    vector<int> a = {1, 3, 5, 7};
    cout << std::upper_bound(a.begin(), a.end(), 1000) - a.begin() << endl;
    cout << std::upper_bound(a.begin(), a.end(), 7) - a.end() << endl;
    cout << *std::lower_bound(a.begin(), a.end(), 4)  << endl;

    return 0;
}
