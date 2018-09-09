#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include<stdlib.h> // sort
#include<limits.h> // INT_MAX

typedef long long int lld;

lld fac[100];

void check(int i){
    if(!fac[i]){
        check(i - 1);
        fac[i] = i * fac[i - 1];
    }
}


int main(){
    int N;
    fac[0] = 1;

    while(scanf("%d", &N) == 1){
        lld y1 = 0;
        for (int i = 1; i <= N ; i += 2) {
            check(i);
            y1 += fac[i];
        }

        lld y2 = 0;
        for (int i = 2; i <= N ; i += 2) {
            check(i);
            y2 += fac[i];
        }
        printf("%lld %lld\n", y1, y2);
    }
    return 0;
}
