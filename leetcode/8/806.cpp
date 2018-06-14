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

const int MAX_LEN = 100;
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lineNum = 1;
        int lineLen = 0;
        for(char c : S){
            if(lineLen + widths[c - 'a'] > MAX_LEN){
                lineLen = widths[c - 'a'];
                lineNum ++;
                continue;
            }
            lineLen += widths[c - 'a'];
        }
        return vector<int>{lineNum, lineLen};
    }
};
int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    return 0;
}
