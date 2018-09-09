#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include <stdlib.h> // sort

int mat[4][5];
int res[2][5];

int min ( int a, int b ) { return a < b ? a : b; }

int max ( int a, int b ) { return a > b ? a : b; }

int main(){
    while(true){
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 5; ++j) {
                if(scanf("%d", &(mat[i][j])) != 1) return 0;
                if(i <= 1) res[i][j] = mat[i][j]; 
            }
        }

        // for (int i = 0; i < 4; ++i) {
            // for (int j = 0; j < 5; ++j) {
                // printf("%d ",mat[i][j]);
            // }
            // printf("\n");
        // }


        for (int j = 0; j < 5; ++j) {
            for (int i = 2; i < 4; ++i) {
                int zero = res[0][j];
                int one = res[1][j];

                int l = min(zero, one);

                if(mat[i][j] > l){
                    bool sub_one = false;
                    
                    if(one < zero) sub_one = true;

                    if(sub_one){
                        res[1][j] = mat[i][j];
                    }else{
                        res[0][j] = res[1][j];
                        res[1][j] = mat[i][j];
                    }
                }
            }
        }

        // printf("\n");
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 5; ++j) {
                printf("%d ", res[i][j]);
            }
            printf("\n");
        }
//
        // printf("%s\n", "----------------------");
    }
    return 0;
}
