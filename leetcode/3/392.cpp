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
    bool isSubsequence(string s, string t) {
        if(!s.size()) return true;
        if(!t.size()) return false;

        int left = 0;
        int right = 0;
        while(true){
            while(s[left] != t[right]){
                right ++;
                if(right == t.size()) return false;
            }
            left ++;
            right ++;
            if(left == s.size())
                return true;
            if(right == t.size())
                return false;
        }
        return false;
    }
};
int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    return 0;
}
