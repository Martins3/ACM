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

const int LEN = 26 + 26;
int F[LEN];

class Solution {
public:

    int longestPalindrome(string s) {
        memset(F, 0, sizeof(F));
        for (int i = 0; i < s.size(); i++) {
            if(std::islower(s[i]))
                F[s[i] - 'a'] ++;
            else
                F[s[i] - 'A' + 26] ++;
        }

        int res = 0;
        bool center = false;
        for (int i = 0; i < LEN ; i++) {
            res += F[i] / 2 * 2;
            if(F[i] % 2 == 1) center = true;
         }

        if(center) res ++;
        return res;
    }
};
int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    cout << s.longestPalindrome("abccccdd");

    return 0;
}

