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
 * 1. 找到上升的a b
 * 2. 对于接下来数值　< a  记录下来, 区间合并处理
 * 3. = a
 * 4. a b　返回
 * 5. b 没有意义
 * 6. 替换b
 *
 *
 * 连续上升和连续下降的没有意义
 * 为什么是stack 计算:
 *  检查附近的数值而已
 *  连续的上升和下降的结果是什么
 */
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // 计算的方法
    }
};

int main(){
    
    return 0;
}
