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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

int N;
int D;
#define maxn (100000 + 10)
char A[maxn]; // 1 start 
pair<int, int> dp[maxn][20];

void ST(int n) {  
    for (int i = 1; i <= n; i++)  
        dp[i][0] = make_pair(A[i], i);  
    for (int j = 1; (1 << j) <= n; j++) {  
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {  
                int l = dp[i][j - 1].first;
                int l_i = dp[i][j - 1].second;
                int r = dp[i + (1 << (j - 1))][j - 1].first;
                int r_i = dp[i + (1 << (j - 1))][j - 1].second;
                if(l >= r){
                    dp[i][j] = make_pair(l, l_i);
                }else{
                    dp[i][j] = make_pair(r, r_i);
                }
        }  
    }  
}  
pair<int, int> RMQ(int l, int r) {  

    int k = 0;  
    while ((1 << (k + 1)) <= r - l + 1) k++;  


    int ll = dp[l][k].first;
    int ll_i = dp[l][k].second;
    int rr = dp[r - (1 << k) + 1][k].first;
    int rr_i = dp[r - (1 << k) + 1][k].second;
    if(ll >= rr)
        return make_pair(ll, ll_i);
    return make_pair(rr, rr_i);
}  

int main(){
    REOPEN_READ
    REOPEN_WRITE
    while(scanf("%d %d", &N, &D)){
        if(N == 0 && D == 0) break; 
        getchar();
        scanf("%s", A + 1);
        ST(strlen(A + 1));
        int start = 1;

        // 被迫删除的最后的元素的
        while(D && start + D <= N){
            int a = RMQ(start, start + D).second;
            // [start, a) 的元素标记删除， 从 start = a + 1的位置, 对于 D 同步修改
            for(int i = start; i < a; i++){
                D --;
                A[i] = 1;
            }
            start = a + 1;
        }

        if(start + D > N){
            for(int i = start; i <= N ; i++){
                A[i] = 1;
            }
        }
        start = 1;
        while(A[start] != 0){
            if(A[start] != 1) putchar(A[start]);
            start ++;
        }
        putchar('\n');
    }

    return 0;
}