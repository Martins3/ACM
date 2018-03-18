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

class Solution {
public:
    int s_len;
    int p_len;
    string p;
    string s;
    int ** dp;

    void slide(int star, int i, int how_many){
            char target = s[i];
            while(star < p_len && p[star] == '*') dp[i][star++] = true;
            if(how_many){
                if(star < p_len && (p[star] == target || p[star] == '?')){
                    dp[i][star] = true;
                    star ++;
                    while(star < p_len && p[star] == '*') dp[i][star++] = true;
                }
            }
    }
    
    /**
     * 应该让的所有的字符尽可能的实现前后都是处理掉的才可以
     * if dp[i][j] = 1
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool isMatch(string &s, string& p) {
        this->p = p;
        this->s = s;
        s_len = s.size();
        p_len = p.size();

        if(s_len == 0){
            for(int i = 0; i < p_len; i++){
                if(p[i] != '*') return false;
            }
            return true;
        }

        dp = new int * [s_len];
        for(int i = 0; i < s_len; i++){
            dp[i] = new int [p_len];
            memset(dp[i], 0, sizeof(int) * p_len);
        }

        for(int i = 0; i < s_len; i++){
            if(i == 0){
                if(p[0] == '?' || s[0] == p[0]){
                    dp[0][0] = true; 
                    slide(1, 0, 0);
                }else if(p[0] == '*'){
                    dp[0][0] = true; 
                    slide(1, 0, 1);
                }

            }else{
                for(int j = 0; j < p_len; j++){
                    if(dp[i - 1][j]){
                        if(p[j] == '*'){
                            dp[i][j] = true;
                            slide(j + 1, i, 1);
                        }

                        if(j + 1 == p_len) break;
                        if(p[j + 1] == '?' || s[i] == p[j + 1]){
                            dp[i][j + 1] = true;
                            slide(j + 2, i, 0);                   
                        }
                    }
                }
            }


        }

        printf(" ------------------\n");
        for(int i = 0; i < s_len; i++){
            for(int j = 0; j < p_len; j++){
                printf("%d ", dp[i][j]);
            }
            cout << endl;
        }
        
        int res = dp[s_len -  1][p_len - 1];
        for(int i = 0; i < s_len; i++){
            delete dp[i];
        }
        return res;
    }
};

int main(){
    REOPEN_READ
    // REOPEN_WRITE
    Solution s;
    string a = "acaabbaccbbacaabbbb";
    string b = 
"a*?*b*?*a*aa*a*";
    bool aa;
    aa = s.isMatch(a, b);
cout << aa << endl;
    return 0;
}
/**
 * 1. × 可以对应空数字， 所以可以下滑 ， 知道遇到的了不匹配的数值的 或者匹配的数值
 * 
 */