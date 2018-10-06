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

#define LEN 30
int dp[LEN];
int R[LEN][LEN];
int Case;
stack<int> Res;

bool eat(const vector<int>& a, const vector<int> & b){
    for (int i = 0; i < a.size(); ++i) {
        if(a[i] <= b[i]){
            return false;
        }
    }
    return true;
}


int score(int num){
    if(dp[num] != 0) return dp[num];

    int M = 0 ;
    for (int i = 0; i < Case; i++) {
        if(R[num][i]){
            M = max(score(i), M);
        }
    }

    dp[num] = max(1, 1 + M);
    return dp[num];
}


// who can be eat by me and most bigger one !
// should be concise here !
void print_ans(int num, int M){
    Res.push(num + 1);
    if(dp[num] == 1) return;
    for (int i = 0; i < Case; i++) {
        if(R[num][i] && dp[i] == M - 1){
            print_ans(i, M - 1);
            return;
        }
    }
}

void solve(vector<vector<int> > & bag){
    Case = bag.size();

    for(vector<int> & a : bag){
        sort(a.begin(), a.end());
    }

    // make R
    memset(R, 0, sizeof(R));
    for (int i = 0; i < Case; i++) {
        for (int j = 0; j < Case; j++) {
            if(eat(bag[i], bag[j])){
                R[i][j] = 1;
            }
        }
    }


    memset(dp, 0, sizeof(dp));
    int M = 0;
    int who;
    for (int i = 0; i < Case; ++i) {
        int S = score(i);
        if(S > M){
            M = S;
            who = i;
        }
    }

    printf("%d\n", M);
    print_ans(who, M);
    while(!Res.empty()){
        printf("%d ", Res.top());
        Res.pop();
    }
    printf("\n");
}



int main(){
    REOPEN_READ
        REOPEN_WRITE

    int Case;
    int Dim;

    while(scanf("%d %d", &Case, &Dim) == 2){
        vector<vector<int> > bag;
        for (int i = 0; i < Case; ++i) {
            vector<int> a;
            for (int i = 0; i < Dim; ++i) {
                int t;
                scanf("%d", &t);
                a.push_back(t);
            }
            bag.push_back(a);
        }

        solve(bag);
    }
    return 0;
}
