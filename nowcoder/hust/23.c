#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include<stdlib.h> // sort
#include<limits.h> // INT_MAX


int main(){
    int a, b;
    while(scanf("%d %d", &a, &b) ==  2){
        printf("%d\n", a + b );
    }
    
    return 0;
}
