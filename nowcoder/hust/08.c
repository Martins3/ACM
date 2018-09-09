#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include <stdlib.h> // sort

int comp (const void * elem1, const void * elem2){
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}



int Arr[1300];
int main(){
    int N;
    while(scanf("%d", &N) == 1){
        if(N == 1){
            scanf("%d", Arr);
            printf("%d\n", Arr[0]);
            printf("%d\n", -1);
            continue;
        }
        for (int i = 0; i < N; ++i) {
            scanf("%d\n", &(Arr[i]));
        }

        qsort (Arr, N, sizeof(int), comp);

        printf("%d\n", Arr[N - 1]);
        for (int i = 0 ; i < N - 1; i++)
            printf ("%d ", Arr[i]);
    }
    return 0;
}
