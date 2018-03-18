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
    int strStr(string haystack, string needle) {
        if(haystack.size() == 0){
            if(needle.size() != 0) return -1;
            return 0;
        }

        if(needle.size() == 0){
            return 0;
        }

        vector<int> next(needle.size(), 0);
        int len;
        for(int pos = 1; pos < needle.size(); pos++){
            len = next[pos - 1];

            if(needle[pos] == needle[len]){
                next[pos] = len + 1;
                continue;
            }

            while(needle[pos] != needle[len] && len > 0){
                len = next[len - 1];    
            }
            if(len || needle[pos] == needle[len]) len ++;
            next[pos] = len;
        }
        
        // 查询 haystack
        int i = 0;
        int j = 0;
        while(i < haystack.size()){
            if(haystack[i] ==  needle[j]){
                i ++;
                j ++;
                if(j == needle.size()){
                    return i - j; 
                }
            }else{
                // 类似构建的next 数组， 只有查询 或者 全部GG 才会跳出来
                if(j != 0){
                    j = next[j - 1];
                }else{
                    i ++;
                }
            }
        }
        return -1;
    }
};
int main(){
    REOPEN_READ
    // REOPEN_WRITE
    Solution s;
    cout << s.strStr("aaaaaaabaaaa", "aba");
    return 0;
}