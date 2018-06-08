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
    uint16_t sup(uint16_t n){
        printf("%x\n", n);
        for (int i = 0; i < 15; ++i) {
            n = (n << 1) | (n >> 15);
            printf("%x\n", n);
        }
        return n;
    }
    uint32_t reverseBits(uint32_t n) {
        // 1 2 3 4 5 6 => 3 2 1  6 5 4 => 6 5 4 3 2 1
        uint32_t l, r;
        l = sup(n >> 16);
        r = sup(n);
        return (r << 16) | l;
    }
};

int main(){
    Solution s;
    int m = 43261596;
    int a = s.reverseBits(3);
    cout << a << endl;
    printf("%x\n", a);
    return 0;
}
