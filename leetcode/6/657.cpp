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
    bool judgeCircle(string moves) {
        pair<int, int> pos(0, 0);
        for(char c: moves){
             switch(c){
                case 'D':
                    pos.second --;
                    break;
                case 'L':
                    pos.first --;
                    break;
                case 'R':
                    pos.first ++;
                    break;
                case 'U':
                    pos.second ++;
                    break;
             }
        }
        return !(pos.first || pos.second);
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    return 0;
}
