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


int T, M, N, K;

const int m = 1000007;

#define maxn 500

int C[maxn][maxn];

int c(int n, int k){
    return C[n][k];
}

void calculate(){
    for(int i = 0; i <= maxn ; i++){
        C[i][0] = C[i][i] = 1;
        for(int j = 0; j < i; j++){
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % m;
        }
    }
}

int main(){

    REOPEN_READ
    REOPEN_WRITE
    calculate();
    scanf("%d", &T);
    for(int case_num = 1; case_num <= T; case_num++){
        scanf("%d %d %d", &M, &N, &K);
        int a = c(M * N, K);
        int b = (c(M * N - M, K)  + c(M * N - N, K)) * 2; // 1
        int d = c((M - 1) * (N - 1), K) * 4 + c(M * N - M - M, K) + c(M * N - N - N, K); // 2
        int e = (c((M - 1) * (N - 2), K)  + c((M - 2) * (N - 1), K)) * 2; // 3
        int f = c((M - 2) * (N - 2), K); // 0
       d

        int res = (a - e + d - b + f) % m;
        res = res < 0 ? res + m : res;
        printf("Case %d: %d\n", case_num, res);
    }
    return 0;
}

/**
 * error log:
 * 1, 在函数的 c 中间， res 初始值不应该是 0
 * 2. 输出的位置， 除法没有 括号
 * 3. 计算行列数目的错误
 * 4. 在计算函数计算的时候已经发生了的数值溢出
 * 5. 计算f 也就是所有行 全部不可以包含的时候， 使用数值出现错误， 应该是 -2 
 */