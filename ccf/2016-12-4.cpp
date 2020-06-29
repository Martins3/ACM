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
// qwe[^8rD**af_ewRs#Er
using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);
/**
 * 简单的动态规划
 * dp 表示范围从的i 到 j （inclusive） 的区间构建一棵树 的 长度
 * len == 0 
 * 对于n == 1的时候单独处理
 * 12.27 农历的
 * 1998.1.25 阳历
 * 
 */
#define maxn (1000 + 10)
#define INF 0x3f3f3f3f
typedef long long int lld;
int N;
int fre[maxn];
lld dp[maxn][maxn];
lld accu[maxn]; // 含有错位 1 表示 0 的求和


// inclusive 
lld get_sum(int l, int r){
    return accu[r + 1] - accu[l];
}
int main(){
    REOPEN_READ
    //REOPEN_WRITE
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &(fre[i]));
    }

    // 处理 N == 1 的特殊情况
    
    // make accu
    memset(accu, 0, sizeof(accu));
    for(int i = 1; i <= N; i++){
        accu[i] += fre[i - 1] + accu[i - 1];
    }

    // dp
    for(int len = 0; len < N; len++){
        for(int i = 0; i + len < N; i++){
            int j = i + len;

            if(i == j){
                dp[i][j] = 0;
            }else{
                lld min_value = INF;
                for(int k = i; k < j; k++){
                    lld v = dp[i][k] + get_sum(i, k) + dp[k + 1][j] + get_sum(k + 1, j);
                    if(v < min_value) min_value = v;
                } 
                dp[i][j] = min_value;
            }
        }
    }
    printf("%lld", dp[0][N - 1]);
    return 0;
}
