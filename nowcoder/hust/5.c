#include<stdio.h>
#include<stdlib.h> // malloc 

char A[200];
char B[200];
char res[500];

int main(){
    
    while(scanf("%s %s", A, B) == 2){
        int i;
        for (i = 0; A[i] != '\0'; ++i) {
            res[i] = A[i];
        }

        int j;
        for (j = 0; B[j] != '\0' ; j++) {
            res[i + j] = B[j];
        }

        res[i + j] = '\0';

        printf("%s\n", A);
    }

    return 0;
}
