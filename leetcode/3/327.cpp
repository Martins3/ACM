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

#define lld long long int

class Solution {
public:
    lld lower;
    lld upper;

    int count(vector<int>& nums, int l, int r){
        if(l == r){
            if(nums[l] <= upper && nums[l] >= lower) return 1;
            return 0;
        }

        lld m = l + (r - l) / 2;
        vector<lld> a;
        vector<lld> b;
        lld sum = 0;
        for(lld i = m; i >= l ; i --){
            sum += nums[i];
            a.push_back(sum);
        }
        sort(a.begin(), a.end());

        sum = 0;
        for(lld i = m + 1; i <= r ; i++){
            sum += nums[i];
            b.push_back(sum);
        }
        sort(b.begin(), b.end());
        
        // lower bound 第一个的大于等于 x + y >= 10  x + y <= 20
        lld res = 0;
        for(const lld & x : a){
            vector<lld>::iterator l = lower_bound(b.begin(), b.end(), lower - x);
            vector<lld>::iterator r = upper_bound(b.begin(), b.end(), upper - x);
            res += (r - l);
        }

        return count(nums, l, m) + res + count(nums, m + 1, r);
    }
    
    lld countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size() == 0) return 0;
        this->lower = lower;
        this->upper = upper;
        return count(nums, 0, nums.size() - 1);
    }
};

int main(){
    REOPEN_READ
    //REOPEN_WRITE
    vector<int> vec = {-2,5,-1};
    Solution s;
    cout << s.countRangeSum(vec, -2, 2) << endl;
    return 0;
}