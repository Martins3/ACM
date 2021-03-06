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
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        for(string str : ops){
            if(str == "C"){
                stk.pop();
            }else if(str == "D"){
                stk.push(stk.top() * 2);
            }else if(str == "+"){
                int t =  stk.top(); stk.pop();
                int m = stk.top();
                stk.push(t);
                stk.push(m + t);
            }else{
                stk.push(stoi(str));
            }
        }
        int res = 0;
        while(!stk.empty()){
             res += stk.top();
             stk.pop();
        }
        return res;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    return 0;
}
