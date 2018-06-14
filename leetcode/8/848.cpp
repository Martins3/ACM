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
    string shiftingLetters(string S, vector<int>& shifts) {
        int last = 0;
        int strIndex = S.size() - 1;
        for (int i = shifts.size() - 1; i >=0; i--) {
            int len = (shifts[i] + last) % 26;
            S[strIndex] = ((S[strIndex] - 'a' + 0) + len) % 26 + 'a';
            last = len;
            strIndex --;
        }
        return S;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    vector<int> a{3, 5, 9};
    cout << s.shiftingLetters("abc", a);
    return 0;
}
