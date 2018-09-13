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

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

/**
 * 1. 创建函数 sutck() 参数是开始和终止的位置，返回是否遇到障碍
 *      2. 解决的关键问题就是，判断点是否在直线上
 *      3. 对于行和列　分别对于obstacles 排序, 使用lower_bound 和　upper_bound 直接查找
 * 2. 然后模拟过程
 */

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // 模拟所有的过程
    }
};

int main(){
    
    return 0;
}
