#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include<stdlib.h> // sort
#include<limits.h> // INT_MAX

// 注意是元素的指针的，如果元素是指针，
int compare(const void * a, const void * b){
    char * A = *((char * *) a);
    char * B = *((char * *) b);

    int len_a = 0;
    int len_b = 0;
    while(*A != '\0'){
        A ++;
        len_a ++;
    }

    while(*B != '\0'){
        B ++;
        len_b ++;
    }

    // test len
    if(len_a > len_b){
        return 1;
    }else if(len_a < len_b){
        return -1;
    }else{
        A = *((char * *) a);
        B = *((char * *) b);
        while(*A != '\0'){
            if(*A - *B) return *A - *B;
            A ++;
            B ++;
        }
        return 0;
    }
}

#define MAXN 120
char * D[MAXN];


int main(){
    int N;
    for (int i = 0; i < MAXN; ++i) {
        D[i] = (char *)malloc(sizeof(char) * 1200);
    }

    while(scanf("%d", &N) == 1){
        for (int i = 0; i < N; ++i) {
            scanf("%s", D[i]);
        }


        qsort(D, N, sizeof(char *), compare);

        for (int i = 0; i < N; ++i) {
            printf("%s\n", D[i]);
        }
    }

    return 0;
}
