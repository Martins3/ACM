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
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for(int i : bills){
            if(i == 20){
             if(ten >= 1){
                    five --;
                    ten --;
                }else{
                    five -= 3;
                }
            }else if(i == 10){
                five --;
                ten ++;
            }else if(i == 5){
                five ++;
            }
            if(five < 0 || ten < 0) return false;
        }
        return true;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    vector<int> a{5, 5, 10, 10, 20};
    cout << s.lemonadeChange(a);
    return 0;
}
