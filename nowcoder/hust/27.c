#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include<stdlib.h> // sort
#include<limits.h> // INT_MAX


char res[100];
int K;


void push(char i){
    res[K] = i;
    K ++;
}

void print(){
    for (int i = K - 1; i >= 0; --i) {
        printf("%c", res[i]);
    }
    printf("\n");
    K = 0;
}


int main(){
    int N;
    while(scanf("%d", &N) == 1){
        while(N){
            push('0' + N % 8);
            N = N / 8;
        }
        print();
    }
    return 0;
}
