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

#define LEN 1010
int dp[LEN][LEN];
vector<int> cuts;

int query(int l, int r){
    // printf("%d %d\n", l, r);
    if(dp[l][r] != -1) return dp[l][r];
    auto lp = std::lower_bound(cuts.begin(), cuts.end(), l);
    auto rp = std::lower_bound(cuts.begin(), cuts.end(), r);
    lp ++;

    if(lp == rp){
        return dp[l][r] = 0;
    }

    int M = INT_MAX;
    for(;lp != rp; lp ++){
        M = min(M, query(l, *lp) + query(*lp, r));
    }

    return dp[l][r] = (M + r - l);
}

int main(){
    REOPEN_READ

    int Len;
    while(scanf("%d", &Len) == 1 && Len != 0){
        int T;
        scanf("%d", &T);
        cuts.clear();
        cuts.push_back(0);
        for (int i = 0; i < T; i++) {
            int t;
            scanf("%d", &t);
            cuts.push_back(t);
        }
        cuts.push_back(Len);

        memset(dp, -1, sizeof(dp));

        printf("The minimum cutting is %d.\n", query(0, Len));
    }
    return 0;
}
