#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include <stdlib.h> // sort

int main(){
    int N;

    while(scanf("%d", &N) == 1){
        int r = N * N;
        if(N < 10){
            r = r % 10;
        }else{
            r = r % 100;
        }

        if(r == N){
            printf("%s\n","Yes!");
        }else{
            printf("%s\n","No!");
        }
    }
    return 0;
}
