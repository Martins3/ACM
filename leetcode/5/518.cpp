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
/**
 * 找零钱问题是动态规划
 * 1. 循环方向的问题
 * 2.
 */

int table[5001];
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        memset(table, 0, sizeof(table));

        // 每次添加一个硬币得到的结果是什么
        // 没有必要添加排序功能
        table[0] = 1;
        for (unsigned i = 0; i < coins.size(); ++i) {

            for (int j = coins[i]; j <= amount; ++j) {
                // 加入硬币导致的增加的种类
                table[j] += table[j - coins[i]];
            }
        }
        return table[amount];
    }
};
int main(){
//    REOPEN_READ
//   REOPEN_WRITE


    Solution s;
    vector<int> v{1, 2};
    cout << s.change(5, v);
    return 0;
}
