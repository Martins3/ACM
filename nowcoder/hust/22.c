#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include<stdlib.h> // sort
#include<limits.h> // INT_MAX


// 14:20
long long int dp[100];
int main(){
    int N;
    dp[1] = 1;
    dp[0] = 1;
    for (int i = 2; i < 95; ++i) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }


    while(scanf("%d", &N) == 1){
        printf("%lld\n", dp[N]);
    }

    return 0;
}
