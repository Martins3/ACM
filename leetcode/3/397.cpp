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
 * 使用暴力搜索
 * 当出现偶数的时候，一定采用　>> 1 的策略，当奇数的时候
 * 对于1 2 3 4 5 6 7的时候采用枚举，对于大于８采用，查看的是不是存在
 * 其他的情况总是采用　+1 的方法
 */
class Solution {
public:
    int res;
    void do_it(unsigned n){
        switch (n) {
            case 1:
                break;
            case 2:
                res += 1;
                break;
            case 3:
                res += 2;
                break;
            case 4:
                res += 2;
                break;
            case 5:
                res += 3;
                break;
            case 6:
                res += 3;
                break;
            case 7:
                res += 4;
                break;
            default:
                if(n & 1){
                    n ++;
                    res ++;
                    do_it(n);
                }else{
                    n /= 2;
                    res ++;
                    do_it(n);
                }
        }
    }
    int integerReplacement(int n) {
        // 不清楚对于ox7fffffff 是否需要单独的处理
        res = 0;
        do_it((unsigned)n);
        return res;
    }
};

int main(int argc, char *argv[]){
    Solution s;
    cout << s.integerReplacement(1234) << endl;
    return 0;
}
