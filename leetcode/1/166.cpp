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
 *
 * 商 不重要，当出现的余数相同
 * 1. 没有循环
 * 2. 含有整数
 * 3. 只有整数
 * 4. 有没有可能直接从整数的部分循环的，显然可能的
 * 5. 小数点的插入位置
 * 6. 当出现相同的余数的时候，那么商可以循环
 * 7. 似乎整数部分是不关心的，只有小数在乎
 * 8. 第一个就是余数
 * 9. 
 */

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        printf("%lf\n", numerator * 1.0 / denominator);

        int left = numerator / denominator;
        numerator = numerator % denominator;

        
        map<int, int> m;
        int d;
        vector<int> frac;
        while(true){
            numerator *= 10;
            d = numerator / denominator;
            frac.push_back(d);

            numerator = numerator % denominator;
            cout << numerator << endl;
            auto f = m.find(numerator);
            
            if(f != m.end()){
                break;
            }else{
                m[numerator] = d;
                
            }
        }

        cout << "faaaaaaaa" << endl;


        for(int a : frac){
            cout << a << endl;
        }
        

        string a = to_string(left);
        return a;
    }
};


int main(){
    Solution s;
    s.fractionToDecimal(7000000, 13);
    return 0;
}

