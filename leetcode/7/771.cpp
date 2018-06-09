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

const int  LEN = 26 + 26;
bool Jewel[LEN];

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        memset(Jewel, false, sizeof(Jewel));
        for(char c : J){
            if(std::islower(c))
                Jewel[c - 'a'] = true;
            else
                Jewel[c - 'A' + 26] = true;
        }

        int res = 0;
        for(char c: S){
            if(std::islower(c)){
                if(Jewel[c - 'a'])
                    res ++;
            }else{
                if(Jewel[c - 'A' + 26])
                    res ++;
            }
        }
        return res;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    return 0;
}
