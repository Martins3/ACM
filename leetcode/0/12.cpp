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
 * I	1
 * V	5
 * X	10
 * L	50
 * C	100
 * D	500
 * M    1000
 * 所有的数值的都是的单独表示的，
 * 对于 4 和 9 采用特殊的表示方法
 * 从上的向下的分析的， 对于数值的分析的而不是， 按照对应的原则分析
*/
char Roman[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
int num[] = {1000, 500, 100, 50, 10, 5, 1};
class Solution {
public:
    string intToRoman(int num) {
        string s;
        int base = 1000;
        int where = 0; 
        // 900 -> 1

        while(num){
            int digit = num / base;
            if(digit == 9) {
                s += Roman[where * 2];
                s += Roman[where * 2 - 2];
            }else if(digit >= 5){
                s += Roman[where * 2 - 1];
                for(int i = 0; i < (digit - 5) ; i++){
                    s += Roman[where * 2];
                }                
            }else if(digit == 4){
                s += Roman[where * 2];
                s += Roman[where * 2 - 1];
            }else{
                for(int i = 0; i < digit ; i++){
                    s += Roman[where * 2];
                }                
            }

            where ++;
            num -= base * digit;
            base = base / 10;
        }
        return s;
    }
};

int main(){
    REOPEN_READ
    //REOPEN_WRITE

    Solution s;
    cout << s.intToRoman(1);
    cout << s.intToRoman(19) << endl;
    cout << s.intToRoman(99) << endl;
    cout << s.intToRoman(999) << endl;
    cout << s.intToRoman(9) << endl;
    cout << s.intToRoman(444) << endl;
    return 0;
}
