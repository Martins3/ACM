#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include<stdlib.h> // sort
#include<limits.h> // INT_MAX

char A[3000];
int main(){
    while(scanf("%s", A) == 1){
        int a = strlen(A);
        bool flag = false;
        for (int i = 0; i < a; ++i) {
            if(A[i] != A[a - 1 - i]){
                printf("%s\n", "No!");
                flag = true;
                break;
            }
        }
        if(flag) continue;

        printf("%s\n", "Yes!");
    }
    return 0;
}
