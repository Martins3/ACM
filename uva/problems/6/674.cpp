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

#define LEN (7489 + 1)
int dp[5][LEN];
vector<int> denomination{1, 5, 10, 25, 50};


/**
 * calculate with 5
 * without 5
 */

int main(){
    REOPEN_READ
    REOPEN_WRITE
    int N;

    // assume we add demnomination 5
    for (int i = 0; i < denomination.size(); i++) {
        dp[i][0] = 1;
        for (int j = 1; j < LEN; j++) {
            int with = j >= denomination[i] ? dp[i][j - denomination[i]] : 0; // every exchange with 5
            int without = i >= 1 ? dp[i - 1][j] : 0; // every exchange without 5
            dp[i][j] = with + without;
        }
    }


    while(scanf("%d", &N) == 1){
        printf("%d\n",dp[4][N]);
    }
    return 0;
}
