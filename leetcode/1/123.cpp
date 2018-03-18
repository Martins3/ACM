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

class Solution {
public:
    /**
     * 查找的之后， 计算所有点的最大值
     * dp 数组计算包含当前位置的以及之后最大值
     */
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> dp(prices.size(), 0);

        for(int i = len - 1; i >= 0; i--){
            if(i == len - 1){
                dp[i] = max(dp[i], prices[i]);
            }else{
                dp[i] = max(dp[i], prices[i]);
                dp[i] = max(dp[i + 1], dp[i]);
            }
        }
        
        int res = 0;
        for(int i = 0; i < len; i++){
            res = max(res, dp[i] - prices[i]);
        }
        return res;
    }
};

int main(){
    REOPEN_READ
    //REOPEN_WRITE
    Solution s;
    vector<int> v{1, 2};
    cout << s.maxProfit(v);
    return 0;
}