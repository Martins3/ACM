#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include<stdlib.h> // sort
#include<limits.h> // INT_MAX

int mat[120];

int main(){
    int M;
    int N;
    while(scanf("%d%d\n", &M, &N) == 2){
        for (int i = 0; i < M; ++i) {
            int sum = 0;
            int m = 0;
            int max;
            for (int j = 0;j < N; ++j) {
                scanf("%d",&(mat[j]));
                sum += mat[j];

                if(j == 0){
                    max = mat[j];
                }else{
                    if(max < mat[j]){
                        max = mat[j];
                        m = j;
                    }
                }

                
            } 

            mat[m] = sum;
            for (int i = 0; i < N; ++i) {
                printf("%d%c", mat[i], i == N - 1 ? '\n' : ' ');
            }
        }
    }
    
    return 0;
}
