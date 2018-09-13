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
 *
 * 只要元素可以删除， 那么就是继续添加到中间
 * 类似题目 https://leetcode.com/problems/create-maximum-number/description/
 * 
 * 如何使用stack来实现。
 * 保证栈底的元素总是最小的即可
 *
 * using a stack, we just keep exchange digit
 * if it's smaller than the previous one until
 * k digits are already removed.
 *
 * 本来采用的算法是:
 *  1. 指定区间的最小值的第一个找出来
 *  2. 当k 使用完了的时候结束
 *  3. 当确定了第一个数值，那么就是转化为一个类似的问题
 * 
 * 使用stack并不是很容易想到，但是没有必要使用RMQ
 *
 * 换一种思路:
 * 1.
 *
 */
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        res.push_back('0'); // edge case
        
        for(char d : num){
            while(k && res.back() > d){
                res.pop_back();
                k --;
            }
            res.push_back(d);
        }

    
        while(k){
            res.pop_back();
            k --;
        }
        

        int i;
        for (i = 0; i < res.size(); i++) {
            if(res[i] != '0')
                break;
        }
        
        if(i == res.size()) return "0";

        return res.substr(i, res.size() - i);
    }
};

int main(){
    Solution s;
    cout << s.removeKdigits("1432219", 3);

    return 0;
}
