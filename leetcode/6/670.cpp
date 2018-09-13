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
 * 1. 出现了多个数值可以替代
 *      1. 使用最后的一个数值替代
 *
 * 2. 查找最大值替代的时候，只是使用未确定的数值
 *
 */
class Solution {
public:
    int maximumSwap(int num) {
        std::vector<int> v;
        while(num){
            v.push_back(num % 10);
            num = num / 10;
        }

        

    }
};

int main(){
    
    return 0;
}
