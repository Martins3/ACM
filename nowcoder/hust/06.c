#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true


#define MAXN 1010

char A[MAXN];
char B[MAXN];
char RES[MAXN];

inline int max ( int a, int b ) { return a > b ? a : b; }
inline int min ( int a, int b ) { return a < b ? a : b; }

void add_pos(){
    int len_A = strlen(A);
    int len_B = strlen(B);
    char * a;
    char * b;
    if(len_A < len_B){
        a = &(B[0]);
        b = &(A[0]);
        int t = len_A;
        len_A = len_B;
        len_B = t;
    }else{
        a = &(A[0]);
        b = &(B[0]);
    }
    

    // 数值对其
    for (int i = MAXN - 1, j = 0; i >= MAXN - len_A ; --i, j++) {
        a[i] = a[len_A - 1 - j];
    }

    for (int i = MAXN - 1, j = 0; i >= MAXN - len_B ; --i, j++) {
        b[i] = b[len_B - 1 - j];
    }

    // 循环计算
    int carry = 0;
    for (int i = 0; i < len_B; ++i) {
        int off =  MAXN - 1 - i;
        int x = a[off] - '0';
        int y = b[off] - '0';
        if(x + y + carry >= 10){
            RES[off] = x + y + carry - 10 + '0';
            carry = 1;
        }else{
            RES[off] = x + y + carry + '0';
            carry = 0;
        }
    }

    for (int i = len_B; i < len_A; ++i) {
        int off = MAXN - 1 - i;
        int x = a[off] - '0';
        if(x + carry >= 10){
            RES[off] = x + carry - 10 + '0';
            carry = 1;
        }else{
            RES[off] = x + carry + '0';
            carry = 0;
        }
    }

    // 计算最后的进位
    int res_len = len_A;
    if(carry){
        res_len ++;
        RES[MAXN - 1 - (len_A - 1) - 1] = 1 + '0';
    }

    // 数值对其
    int i;
    for (i = 0; i < res_len; i++) {
        RES[i] = RES[MAXN - 1 - (res_len - 1) + i];
    }

    // 设置结束标志
    RES[i] = '\0';
}

int main(){
    while(scanf("%s %s",A, B) == 2){
        printf("%s\n", A);
        printf("%s\n", B);

        add_pos();
        printf("%s\n", RES);
    }

    return 0;
}
