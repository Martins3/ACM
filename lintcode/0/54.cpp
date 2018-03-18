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
    /**
     * 
     * @param str: A string
     * @return: An integer
     */
    int atoi(string &str) {
        // 前导space
        int i;
        for(i = 0; i < str.size(); i++){
            if(!isspace(str[i])) break;
        }
        if(i == str.size()) return 0;
        str = str.substr(i, str.size() - i);

        // 符号处理掉
        if(!(str[0] == '+' || str[0] == '-' || isdigit(str[0])) )
            return 0;

        bool neg = false;
        if(str[0] == '-') {
            str = str.substr(1, str.size() - 1);
            neg = true;
        }else if(str[0] == '+'){
            str = str.substr(1, str.size() - 1);
        }

        // 排除后面的不正常字符
        for(i = 0; i < str.size(); i++){
            if(!isdigit(str[i])){
                break;
            }
        }
        if(i == 0) return 0;
        str = str.substr(0, i);

        
        string str_max = "2147483647";
        string str_min = "2147483648";
        
        if(str.size() > str_max.size()){
            if(neg){
                return INT_MIN;
            }else{
                return INT_MAX;
            }
        }

        if(str.size() == str_max.size()){
            if(neg && str.compare(str_min) > 0){
                return INT_MIN;
            }

            if(!neg  && str.compare(str_max) > 0){
                return INT_MAX;
            }
        }
        if(str == str_min) return INT_MIN;

        int res = stoi(str);
        res = neg ? -res : res;
        return res;
    }
};

int main(){
    REOPEN_READ
    // REOPEN_WRITE
    Solution s;
    string str = "-2147483647";
    string str_one = "2147483646";
    cout << str.compare(str_one) << endl; 
    cout << s.atoi(str);

    return 0;
}
/**
 * 1. 逻辑书写错误 ！
 * 2. 由于使用了 stoi 没有处理的正确的处理 转化的时候的数值的范围 ！
 * 3. 
 */