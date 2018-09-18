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
 * 既然可以使用二维数组，那么就很简单了
 *
 * 依赖关系是什么:
 *
 * 一个字母最多和一个pattern 匹配
 * 空字符串的处理，计算其中的字符串方法
 *
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool> > dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;

        // 和空元素匹配，那么要求
        for (int i = 0; i < p.size(); i++) {
            if(p[i] == '*')
                dp[0][i + 1] =  true;
            else
                break;
        }


        // 第一个元素可以匹配的项目
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < p.size(); j++) {
                if(dp[i][j]){
                    if(p[j] == s[i] || p[j] == '?' || p[j] == '*'){
                        dp[i + 1][j + 1] = true;
                    }
                }

                if(dp[i][j + 1] && p[j] == '*'){
                    dp[i + 1][j + 1] = true;
                }

                if(dp[i + 1][j] && p[j] == '*' ){
                    dp[i + 1][j + 1] = true;
                }
            }
        }

        for (int i = 0; i <= s.size(); i++) {
            for (int j = 0; j <= p.size(); j++) {
                printf("%d ", dp[i][j] == true);
            }
            cout << endl;
        }
        
        return dp[s.size()][p.size()];
    }
};

int main(){
    Solution s;
    string A = "a";
    string B = "a*";
    cout << s.isMatch(A, B);


    return 0;
}
