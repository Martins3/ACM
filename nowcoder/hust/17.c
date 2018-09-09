#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include <stdlib.h> // sort


int M[120][120];
int main(){
    int N;
    while(scanf("%d", &N) == 1){
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &(M[i][j]));
            }
        }
        
        bool fuck = false;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (M[i][j] != M[j][i]) {
                    printf("%s\n", "No!");
                    fuck = true;
                    break;
                }
            }
            if(fuck) break;
        }
        if(fuck) continue;

        printf("%s\n", "Yes!");
    }

    return 0;
}
