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

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

/**
 * 动态规划： 
 *  使用的数组， 记录的和自己匹配的元素的位置, 只
 * -1 表示  
 * 如何保证是最长的, 右括号的表示的控制的位置为 ， 控制的位置是什么
 * （ -1 ） 查询
 * 无人匹配 -2 
 * 如果的是的 -1 （ 
 * 从当前的位置的开始的最大的长度的位置的是什么
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> match(s.size(), -2);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') match[i] = -1;
            if(s[i] == ')'){
                if(i - 1 < 0) continue;

                if(match[i - 1] == -1) {
                    int left = i - 2; 
                    match[i] = i - 1;

                    if(left < 0) continue;
                    
                    if(match[left] >= 0) match[i] = match[left];
                }


                if(match[i - 1] >= 0){
                    int left = match[i - 1] - 1;
                    if(left < 0) continue;
                    if(match[left] == -1) {
                        match[i] = left;

                        left --;
                        if(left < 0) continue;

                        if(match[left] >= 0) match[i] = match[left];
                    }
                }
            }
        }

        // 遍历查询的最大值的即可
        int res = 0;
        for(int i = 0; i < match.size(); i++){
            if(match[i] >= 0){
                res = max(res, i - match[i] + 1);
            }
        }

        return res;        
    }
};
int main(){
    REOPEN_READ
    // REOPEN_WRITE
    Solution s;
    int a = s.longestValidParentheses("");
    cout << a << endl;
    return 0;
}