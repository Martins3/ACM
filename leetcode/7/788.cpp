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

int R[10] = {0, 0, 2, 3, 3, 2, 2, 3, 0, 2};
class Solution {
public:
    bool test_num(int n){
        bool same = true;
        while(n){
            int m = n % 10;
            if(R[m] == 3) return false;
            if(R[m] == 2) same = false;
            n = n / 10;
        }

        if(same) return false;
        return true;
    }
    int rotatedDigits(int N) {
        int res = 0;
        for (int i = 1; i <= N; ++i) {
            res += test_num(i);
        }
        return res;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    return 0;
}
