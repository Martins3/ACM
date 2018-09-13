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
 * 需要注意:
 * 1. 对应的数值超过的整数的表达范围
 * 2. 符号
 *      1. 负数比整数多一个
 * 3. 中间含有奇怪的符号 
 * 4. 长度为０
 */
class Solution {
public:
    int StrToInt(string str) {
        // 之后所有的数值小于等于　INT_MAX

        if(str == "-2147483648") return INT_MIN;
        if(str.empty()){
            return 0;
        }

        bool neg = false;
        int off = 0;
        if(!isdigit(str[off])){
            if(str[off] == '-'){
                neg = true;
            }else if(str[off] != '+'){
                return 0;
            }
            off ++;
        }

        vector<int> s;
        for (int i = off; i < str.size(); i++) {
            if(isdigit(str[i])){
                s.push_back(str[i] - '0');
            }else{
                return 0;
            }
        }


        vector<int> int_max;
        int big = INT_MAX;
        while(big){
            int_max.push_back(big % 10);
            big = big / 10;
        }
        reverse(int_max.begin(), int_max.end());

        if(s.size() > int_max.size()){
            return 0;
        }else if(s.size() == int_max.size()){
            for (int i = 0; i < s.size(); i++) {
                if(s[i] > int_max[i]) return 0;
                if(s[i] < int_max[i]) break;
            }
        }

        int res = 0;
        int pow = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            res += s[i] * pow;
            pow *= 10;
        }

        if(neg){
            res = -res;
        }

        return res;
    }
};

int main(){
    Solution s;
    cout << s.StrToInt("123");
    
    return 0;
}
