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

class Solution {
public:
    /**
     * 利用上 一部计算
     *
     * 还是需要可以 整除的 性质的
     * 
     */ 
    bool repeatedSubstringPattern(string s) {
        vector<int> next(s.size(), 0);
        // kmp 
        // next 数组的表示 suffix 的长度
        int len;
        for(int pos = 1; pos < s.size(); pos++){
            len = next[pos - 1];

            // 匹配成功 
            if(s[pos] == s[len]){
                next[pos] = len + 1;
                continue;
            }

            // 匹配失败
            while(s[pos] != s[len] && len > 0){
                len = next[len - 1];    
            }
            // 匹配成功
            if(len || s[pos] == s[len]) len ++;
            next[pos] = len;
        }

        for(int i: next){
            printf("%d ", i);
        }
        cout << endl;
        int re = next[next.size() - 1];
        return next.size() % (next.size() - re) == 0 && re != 0;
    }
};

int main(){
    REOPEN_READ
    // REOPEN_WRITE
    Solution s;
    bool a = s.repeatedSubstringPattern("abacababacab");
    bool b = s.repeatedSubstringPattern("abababaabababaabababa");
    cout << (a == true) << endl;
    cout << (b == true) << endl;

    return 0;
}