#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true

//
// 为什么不是用bit 计算，错误的方式
//

unsigned char IP[4];

bool BIP[32];


void toIP(){
    for (int i = 0; i < 4; ++i) {
        IP[i] = 0;
        for (int j = 0; j < 8; ++j) {
            if(BIP[i * 8 + j]) IP[i] |= 1 << (7 -j);
        }
    }
}

void toBIP(){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            if(IP[i] & (1 << (7 - j)))
                BIP[i * 8 + j] = true;
            else
                BIP[i * 8 + j] = false;
        }
    }
}

void print_IP(){
    for (int i = 0; i < 4; ++i) {
        printf("%d%c", IP[i], i == 3 ? '\n' : '.');
    }
}

void print_BIP(){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            printf("%d", BIP[i * 8 + j]);;
        }
        printf("%c",  i == 3 ? '\n' : '.');
    }
}

void read_IP(){
    for (int i = 0; i < 4; ++i) {
        int t;
        scanf("%d",&t);
        getchar();
        IP[i] = t;
    }
}

//
// 处理m = 1 的情况
// 所有全部不相同，IP Address ?

int mask[32];

int main(){
    int N;

    while(scanf("%d", &N) == 1){
        memset(mask, 0, sizeof(int) * 32);

        for (int i = 0; i < N; ++i) {
            read_IP();
                // print_IP();
            toBIP();
                // print_BIP();
            for (int i = 0; i < 32; ++i) {
                if(BIP[i]) mask[i] ++;
            }
        }

        // for (int i = 0; i < 32; ++i) {
            // printf("%d ", mask[i]);
        // }

        int i;
        for (i = 0; i < 32; ++i) {
            if(mask[i] != N && mask[i] != 0){
                break;
            }
        }

        for (int j = i; j < 32; ++j) {
            BIP[j] = false;
        }
        toIP();
        print_IP();

        for (int j = 0; j < i; ++j) {
            BIP[j] = true;
        }
        toIP();
        print_IP();
    }

    return 0;
}
