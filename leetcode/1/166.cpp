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

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

/**
 * 1. 负数
 * 2. 含有负数的整数部分
 * 3. 只有0 的时候
 *
 */

class Solution {
public:
    string fractionToDecimal(int numerato, int denominato) {
        long long int numerator = numerato;
        long long int denominator = denominato;

        // 数值正规化
        bool pos = true;
        if(numerator < 0){
            pos = !pos;
            numerator = -numerator;
        }

        if(denominator < 0){
            pos = !pos;
            denominator = -denominator;
        }

        long long int left = numerator / denominator;
        
        string a;
        if(!pos) a = "-";
        a += to_string(left);

        numerator = numerator % denominator;

        if(!numerator){
            // 只有整数
            if(left == 0) return "0";
            return a;
        }

        map<long long int, long long int> m;
        long long int d;
        vector<long long int> frac;
        long long int index = 0;
        bool flag = false;
        while(true){
            if(numerator == 0){
                flag = true;
                break;
            }

            numerator *= 10; // 当次数相同，那么结果必定相同
            auto f = m.find(numerator);

            if(f != m.end()){
                index = f->second;
                break;
            }else{

                d = numerator / denominator;
                m[numerator] = index ++;
                frac.push_back(d);
                numerator = numerator % denominator;
            }
        }

        string b;
        if(flag){
            for(auto num : frac){
                b.push_back(num + '0');
            }
        }else{
            for (long long int i = 0; i < frac.size(); i++) {
                if(i == index) b.push_back('(');
                b.push_back(frac[i] + '0');
            }
            b.push_back(')');
        }

        return a  + "." + b;
    }
};


int main(){
    
    Solution s;
    cout << s.fractionToDecimal(-1111, 1);
    // Line 6: division of -2147483648 by -1 cannot be represented in type 'int'
    
    return 0;
}

