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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/OnlineJudge/output.txt", "w", stdout);

class Solution {
public:
    void to_stk(deque<int> & stk, string & str){
        for (int i = 0; i < str.size(); ++i) {
            stk.push_back(str[i] - '0');
        }
    }

    void to_string(deque<int> & stk, string & str ){
        while(!stk.empty()){
            str.push_back(stk.front() + '0');
            stk.pop_front();
        }
    }

    string addStrings(string num1, string num2) {
        deque<int> stk1;
        deque<int> stk2;

        to_stk(stk1, num1);
        to_stk(stk2, num2);
        deque<int> res;

        int carry = 0;
        while(!stk1.empty() || !stk2.empty()){
            int x;
            int y;
            if(stk1.empty()){
                x  = 0;
            }else{
                x = stk1.back();
                stk1.pop_back();
            }

            if(stk2.empty()){
                y  = 0;
            }else{
                y = stk2.back();
                stk2.pop_back();
            }

            int sum = x + y + carry;
            carry = sum / 10;
            res.push_front(sum  % 10);
        }

        if(carry) res.push_front(1);
        string str;
        to_string(res, str);
        return str;
    }
};
int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    cout << s.addStrings("0", "0");

    return 0;
}
