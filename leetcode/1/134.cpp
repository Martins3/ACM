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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (size_t i = 0; i < gas.size(); ++i) {
            gas[i] -= cost[i];
        }

        if(gas.size() == 1){
            if(gas[0] < 0)
                return -1;
            else
                return 0;
        }

        bool all_neg = true;
        for (size_t i = 0; i < gas.size(); ++i) {
            if(gas[i] >= 0){
                all_neg = false;
                break;
            }
        }

        if(all_neg) return -1;

        size_t right = 0;
        bool neg = false;
        for (size_t i = 0; i < gas.size() * 2; ++i) {
            i =  i % gas.size();
            if(gas[i] < 0){
                neg = true;
            }else{
                if(neg){
                    right = i;
                    break;
                }
            }
        }
        // 设计失误， 如果同一个位置，两次上岸， 那么结束。

        size_t loc = right ++;
        set<int> death_point;
        death_point.insert(loc);
        right = right % gas.size();
        int sum = gas[loc];

        bool in_water = false;

        while(true){
            sum += gas[right];
            if(sum < 0){
                sum = 0;
                in_water = true;
            }else{
                if(in_water){
                    loc = right;
                    if(death_point.find(loc) != death_point.end())
                        return -1;
                    else
                        death_point.insert(loc);
                }else{
                    if(loc == right) return loc;
                }
                in_water = false;
            }

            right ++;
            right = right % gas.size();
        }
        return -1;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    vector<int> a{5};
    vector<int> b{4};
    cout << s.canCompleteCircuit(a, b);
    return 0;
}
