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
    lld A, B;
    while(scanf("%lld%lld", &A, &B) == 2){
        printf("%lld\n", B > A ?  B- A : A - B);
    }
    return 0;
}
