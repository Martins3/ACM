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

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int L = nums.size();
        if(L <= 1) return L;

        std::vector<int> S;
        S.push_back(nums[0]);

        for (int i = 1; i < L; i++) {
            auto f = std::lower_bound(S.begin(), S.end(), nums[i]);
            if(f == S.end()){
                S.push_back(nums[i]);
            }else{
                *f = nums[i];
            }
        }
        return S.size();
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
