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

/**
 * 1. 是不是找到以及组合就算一个组合: 并不是的
 * 2. 何时加入数值
 */

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto i : nums)
            sum += i;

        if(sum % k) return false;

        int sig_sum = sum / k;
        for(auto i : nums)
            if(i > sig_sum) return false;

        

    }
};

int main(){
    
    return 0;
}
