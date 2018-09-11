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
 * 简单的dp 问题而已
 */

class Solution {
public:

    // 仅仅是该数值
    int dp[15];
    int sdp[15];
    int POW[15];
    int NumberOf1Between1AndN_Solution(int n){
        for (int i = 0; i < 15; i++) {
            dp[i] = 0;
        }

        dp[1] = 1;
        POW[0] = 1;
        int pow = 10;
        for (int i = 2; i < 15; i++) {
            dp[i] = 9 * dp[i - 1] + pow; 
            POW[i - 1] =  pow;
            pow = pow * 10;
        }

        sdp[0] = 1;
        for (int i = 1; i < 15; i++) {
            sdp[i] += sdp[i - 1] + dp[i];
        }
        
        // 逐级添加内容 27853
        // 判断最高位是否为1
        // 最高位为0 的情况
        // 使用部分　1. 是１
        // 转化为多个子问题
        
        stack<int> stk;
        while(n){
            stk.push(n % 10);
            n = n / 10;
        }

        int res = 0;
        while(!stk.empty()){
            int N = stk.top(); stk.pop();
            int size = stk.size();

            if(!size){
                res += (size >=1 ? 1 : 0 ); 
                break;
            }

            // 1789787
            // 如果最高位就是１, 如何处理
            // 处理最高位为１的情况
            if(N == 0){
                continue;
            }else if(N == 1){
                    // 处理最最高位为0的
                    res += sdp[size];

                    // 剩下的直接加起来
                    string s;
                    while(!stk.empty()){
                        s.push_back(stk.top() + '0');
                        stk.pop();
                    }
                    res += stoi(s);
            }else{
                // 最高位无法处理，向下传递
                
                // 处理为1 的情况
                res += POW[size];

                // 处理不是１的情况和最高位的情况
                for (int i = 0; i < N - 1; i++) {
                    res += sdp[size];
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.NumberOf1Between1AndN_Solution(13);
    return 0;
}
