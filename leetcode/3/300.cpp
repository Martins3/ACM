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
#include <unordered_set>
#include <unordered_map>
#include "../info.hpp"

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

/**
 * analyze this wrongly
 * binary search is needed
 *
 * a vector containing the LIS
 *
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int L = nums.size();
        if(L <= 1) return L;

        std::vector<int> pre(L); pre[0] = -1;
        std::vector<int> len(L); len[0] = 1;

        for (int i = 1; i < L; i++) {
            int p;
            for (p = i - 1;p >= 0; p = pre[p]) {
                if(nums[p] < nums[i]){
                    break;
                }
            }
            len[i] = p == -1 ? 1 : len[p] + 1; 
            pre[i] = p;
        }
        print_v(len);
        print_v(pre);

        int M = 0;
        for (int i = 0; i < L; i++) {
            M = max(len[i], M);
        }
        return M;
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
    print_v(vec);
    cout << s.lengthOfLIS(vec);
    return 0;
}
