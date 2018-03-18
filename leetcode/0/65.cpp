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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

class Solution {
public:
    /**
     * 1.仅仅含有一个字符为e，后面为数
     * 2. 只有一个小数点， 后面是整数
     * 3. 数值中间的空格无效, 但是前后可以
     * 4. 缺省 0 的处理 
     * 5. 对于空 string的处理
     * 6. 对于只有 "." 的处理没有完成的
     */

    string trim(const string& str,
                     const std::string& whitespace = " \t"){
        const auto strBegin = str.find_first_not_of(whitespace);
        if (strBegin == std::string::npos)
            return ""; // no content

        const auto strEnd = str.find_last_not_of(whitespace);
        const auto strRange = strEnd - strBegin + 1;

        return str.substr(strBegin, strRange);
    }

    // 含有数值， ！empty 没有符号
    bool isUnsigned(const string & s){
        size_t n = s.find_first_not_of("0123456789");
        if(n != string::npos) return false;
        if(s.empty()) return false;
        return true;
    }

    // 空 或者 符号
    bool isDefaultZero(const string & s){
        return s.empty() || (s.size() == 1 && (s[0] == '+' || s[0] == '-'));
    }

    // 和 unsigned 兼容 符号
    bool isInteger(const string & s){
        if(s[0] == '-' || s[0] == '+') return isUnsigned(s.substr(1, s.size() - 1));
        return isUnsigned(s);
    }

    /**
     * 左边可以含有符号， 但是右边不可以含有符号
     */
    bool isDecimal(const string & s){
        string::size_type t = s.find(".");
        string a = s.substr(0, t);
        string b = s.substr(t + 1, s.size() - (t + 1));

        if((isDefaultZero(a) || isInteger(a)) && (b.empty() || isUnsigned(b))){
            if(isDefaultZero(a) && b.empty()) return false;
            return true;
        }
        return false;
    }

    bool isNumber(string s) {
        s = trim(s);
                
        string::size_type n = s.find("e");
        string::size_type N = s.find("E");
        
        if(n != string::npos || N != string::npos){
            if(N != string::npos) swap(N, n);
            string a = s.substr(0, n);
            string b = s.substr(n + 1, s.size() - (n + 1));
            if((isInteger(a) || isDecimal(a)) && isInteger(b)){
                return true;
            }else{
                return false;
            }
        } 

        size_t d = s.find(".");
        if(d != string::npos) return isDecimal(s);
        return isInteger(s);
    }
};

int main(){
    double a = -.3;
    cout << a << endl;
    return 0;
}

