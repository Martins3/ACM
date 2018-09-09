#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include <stdlib.h> // sort


typedef int * StuPtr;

int compare(const void * A, const void * B){
    StuPtr a = (StuPtr)A;
    StuPtr b = (StuPtr)B;
    return *a - *b;
}


int main(){
    int N;
    
    while(scanf("%d", &N) == 1){
        StuPtr students = (StuPtr)malloc(sizeof(int) * N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", (students + i));
        }

        qsort(students, N, sizeof(int), compare);

        for (int i = 0; i < N; ++i) {
            printf("%d%c", *(students + i), i == N -1 ? '\n' :' ');
        }
    }

    return 0;
}
