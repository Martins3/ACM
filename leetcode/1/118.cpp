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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 1; i <=  numRows; ++i) {
            if(i == 1){
                res.push_back(vector<int>{1});
                continue;
            }

            vector<int> v;
            for (int j = 0; j < i; ++j) {
                if(j == 0 || j == i - 1){
                    v.push_back(1);
                    continue;
                }
                v.push_back(res.back()[j] + res.back()[j - 1]);
            }

            res.push_back(v);
        }
        return res;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    return 0;
}
