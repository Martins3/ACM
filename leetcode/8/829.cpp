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

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

// 暴力

typedef long long int lld;

bool ok(lld s, lld sum){


    lld f = (2 * s - 1) * (2 * s - 1) + 8 * sum; // 可以分解

    lld m=floor(sqrt(f)+0.5);
    if(m * m != f ) return false; 

    lld z = -(2 * s - 1) + m;
    if(z > 0 && z % 2 == 0) return true;

    return false;
}

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 0;
        int m = (int)(sqrt(N) + 10);
        for (int i = 0; i < ; i++) {
            
        }
        
    }
};

int main(){
    ok(1, 100);

    return 0;
}
