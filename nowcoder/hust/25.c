#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include<stdlib.h> // sort
#include<limits.h> // INT_MAX


char str[200];

int stack[1000];
int K;

void push(int val){
    stack[K] = val;
    K ++;
}

void clear(){
    K = 0;
}

void print(char c){
    for (int i = 0; i < K; ++i) {
        printf("%c:%d%c", c, stack[i],  i == K - 1 ? '\n':',');
    }
}

int main(){
    while(scanf("%s", str) == 1){
        int len = strlen(str);
        for (int i = 0; i < len; ++i) {
            char t = str[i];
            if(!t) continue;

            push(i);
            for (int j = i + 1; j < len; ++j) {
                if(str[j] == t){
                    str[j] = 0;
                    push(j);
                }
            }
            if(K > 1)
                print(t);
            clear();
        }
        
    }
    return 0;
}
