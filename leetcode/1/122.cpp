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
 * 首先的出售 ？
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int res = 0;
        int last_num = prices[0];

        for(int i = 0; i < prices.size(); i++){
            int num = prices[i];
            if(num > last_num){
                res += (num - last_num);
            }
            last_num = num;
        }
        
        return res;
    }
};

int main(){
    REOPEN_READ
    //REOPEN_WRITE

    return 0;
}

/**
 * error log: 
 *  1. 没有将最后的输出刷新出来的
 * 
 */