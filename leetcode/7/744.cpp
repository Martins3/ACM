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

bool exist[26];

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        memset(exist, 0, sizeof(exist));

        for (int i = 0; i < letters.size(); ++i) {
            exist[letters[i] - 'a'] = true;
            if(letters[i] - target == 1) return target + 1;
        }

        for (int i = target - 'a' + 1; i < 26; ++i) {
            if(exist[i]) return 'a' + i;
        }

        for (int i = 0; i < 26; ++i) {
            if(exist[i]) return 'a' + i;
        }

        return false;
    }
};
int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    return 0;
}
