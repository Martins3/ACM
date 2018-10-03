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
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

typedef long long int lld;


int main(){
    REOPEN_READ
    REOPEN_WRITE

    int Case;
    scanf("%d", &Case);
    while(Case --){
        int N;
        lld sum = 0;
        scanf("%d", &N);
        while(N --){
            lld A, B, C;
            scanf("%lld%lld%lld", &A, &B, &C);
            // sum += (lld)(A * 1.0 / B * C * B);
            sum += A * C;
        }
        printf("%lld%c", sum, '\n');
    }
    return 0;
}
