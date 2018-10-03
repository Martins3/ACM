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

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

#define lld long long int

lld n, m;
int main(){
    REOPEN_READ
    REOPEN_WRITE
    while(scanf("%lld %lld", &n, &m) == 2 && n !=0 && m != 0){
        if(n > m) swap(m, n);
        printf("%lld\n", m * n * (m + n - 2) + (n - 1) * n * (3 * m - n - 1) * 2 / 3);
    }
    return 0;
}