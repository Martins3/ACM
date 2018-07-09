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
 * 如何利用KMP的计算方法
 * 首先将 字符串 翻转的过来的， 然后看的可以回退的到哪一个的位置
 * 构建 s 的 kmp 数组， 然后认为 p 是p 的查询
 */
class Solution {
public:
    string shortestPalindrome(string s) {
        string p = s;
        reverse(p.begin(), p.end());

        // 构建 s 的 next 数组
        vector<int> next(s.size(), 0);
        int len;
        for(int pos = 1; pos < s.size(); pos++){
            len = next[pos - 1];

            if(s[pos] == s[len]){
                next[pos] = len + 1;
                continue;
            }

            while(s[pos] != s[len] && len > 0){
                len = next[len - 1];
            }
            if(len || s[pos] == s[len]) len ++;
            next[pos] = len;
        }

        // 查询 p
        // 由于的长度相同
        int i = 0; // i 文本指针
        int j = 0; // j 模式 长度
        while(i < p.size()){
            if(p[i] == s[j]){
                i ++;
                j ++;
            }else{
                if(j != 0){
                    j = next[j - 1];
                }else{
                    i ++;
                }
            }
        }

        // 构建连接在一起的字符串
        string append = s.substr(j, s.size() - j);
        reverse(append.begin(), append.end());
        return append + s;
    }
};


int main(){
    REOPEN_READ
    //REOPEN_WRITE
    Solution s;
    cout << s.shortestPalindrome("21123456");
    return 0;
}
