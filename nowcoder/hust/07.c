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



int Arr[130];
int main(){
    int N;
    while(scanf("%d", &N) == 1){
        for (int i = 0; i < N; ++i) {
            scanf("%d\n", &(Arr[i]));
        }

        qsort (Arr, N, sizeof(int), comp);

        for (int i = 0 ; i < N ; i++)
            printf ("%d ", Arr[i]);
    }
    return 0;
}
