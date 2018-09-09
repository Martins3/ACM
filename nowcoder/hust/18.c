#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include<stdlib.h> // sort
#include<limits.h> // INT_MAX


int num[15];
int K;
bool neg = false;

void push(int val){
    num[K] = val;
    // printf("[%d]\n", val);
    K++;
}

int get_val(){
    int val = 0;
    int pow = 1;
    for (int i = K - 1; i >= 0; --i) {
        val += pow * num[i];
        pow = pow * 10;
    }

    K = 0;
    if(neg) return -val;
    return val;
}

int main(){
    
    char c;
    bool fuck = false;

    while(true){
        bool SP = true;

        int D[2];
        int W = 0;

        bool over = false;
        while(true){
            c = getchar();
            switch(c){
                case EOF:
                    fuck = true;
                    break;
                case '\n':
                    if(!SP){
                        D[W ++] = get_val();
                        SP = true;
                        neg = false;
                    }
                    over = true;
                    break;
                case ' ':
                    if(!SP){
                        D[W ++] = get_val();
                        SP = true;
                        neg = false;
                    }
                    break;
                default:
                    SP = false;
                    if(c != ','){
                        if(c == '-'){
                            neg = true;
                        }else{
                            push(c - '0');
                        }
                    }
                    break;
            }
            if(over) break;
            if(fuck) break;
        }
        if(over){
            printf("%d\n", D[0] + D[1]);
            // printf("%d %d \n", D[0], D[1]);
        }
        if(fuck) break;
    }
    return 0;
}
