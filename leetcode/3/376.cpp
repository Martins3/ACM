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

/**
 * 动态规划:
 * 类似的套路，动态规划的问题关键，将原来的问题转化为子问题
 * 
 * 数组的转化为子问题的方法:
 *  数组的长度逐渐增加的方法
 *
 * 最终解是众多问题的合成解
 *
 * 子序列的问题: 
 *  循环，有的添加，有的不添加
 *  stack的方法
 *
 * 本题思路:
 *  up[j] 表示数值到j 的最佳数值
 *  down[j] 
 *  每次添加一个数字的时候，对于所有之前的全部位置查询
 *
 *  linear的看不懂
 *
 */
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();

    }
};
int main(){
    //REOPEN_READ
    //REOPEN_WRITE


    return 0;
}
