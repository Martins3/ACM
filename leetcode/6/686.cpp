#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <forward_list>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

#define maxn 10000

char str[maxn * 2 + 10];

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int len = A.size();
        int times = maxn / len;
        if(maxn % len) times ++;

        memset(str, 0, sizeof(str));

        int wt = 0;
        for(int i = 0; i < times; i++){
            for(int j = 0; j < len; j++){
                str[i * len + j] = A[j];
                wt ++;
            }
        } 

        A.assign(str, find(str, str + maxn * 2 + 10, '\0'));
        cout << A.size() << endl;

        size_t f = A.find(B);
        if(f == string::npos) return -1;

        f += B.size();

        int res = f / len;
        if(f % len) res ++;
        return res;
    }
};
int main(){
    REOPEN_READ
    // REOPEN_WRITE
    Solution s;
    string a = "aaaaaaaaaaaaaaaaaaaaa";
    string b = "bacbacbac";
    cout << s.repeatedStringMatch(a, b);
    return 0;
}