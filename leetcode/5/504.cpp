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
    string convertToBase7(int num) {
        string str;
        if(num < 0){
            num = - num;
            str = "-";
        }

        stack<int> stk;
        while(num){
            stk.push(num % 7);
            num = num / 7;
        }

        while(!stk.empty()){
            str.push_back('0' + stk.top());
            stk.pop();
        }
        if(str.size() == 0) return "0";
           return str;

    }
};
int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    cout << s.convertToBase7(7);

    return 0;
}
