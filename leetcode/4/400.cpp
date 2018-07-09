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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);
class Solution {
public:
    int index;
    int get_num_length(int n){
        int res = 0;
        do {
            n -= 9 * (int)pow(10, res) * (res + 1);
            res ++;
            if(n > 0) index = res;
        } while (n > 0);
        return res;
    }

    int findNthDigit(int n) {
        int len = get_num_length(n);

        int num = index / len;
        int pos = index % len;
        return 0;
    }
};

int main(){
    for (int j = 0; j < 100; ++j) {
        cout << j << endl;
    }
    return 0;
}

