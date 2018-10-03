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

#define maxn (300 * 300)
int T;
int n, p, q;
int A[maxn];
int B[maxn];

/**
 * LCS questions to  LIS questions(Longest Increasing Subsequence)
 * 
 */
int main(){
    REOPEN_READ
    REOPEN_WRITE
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &n, &p, &q);
        for(int i = 0; i <= p; i++){ scanf("%d", &A[i]); }
        for(int i = 0; i <= q; i++){ scanf("%d", &B[i]); }


        
    }
    return 0;
}