#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true

char IP[4];

bool BIP[32];


void toIP(){
    for (int i = 3; i >= 0; --i) {
        IP[i] = 0;
        for (int j = 7; j >= 0; --j) {
            if(BIP[i * 8 + j]) IP[i] = 1 << j;
        }
    }
}

void toBIP(){
    for (int i = 3; i >= 0; --i) {
        for (int j = 7; j >= 0; --j) {
            if(IP[i * 8 + j] & 1 << j) IP[i] = true;
        }
    }
}

void print_IP(){
    for (int i = 3; i >= 0; --i) {
        printf("%d%c", IP[i], i == 0 ? '\n' : '.');
    }
}

void print_BIP(){
    for (int i = 3; i >= 0; --i) {
        for (int j = 7; j >= 0; --j) {
            printf("%d", IP[i * 8 + j]);;
        }
        printf("%c",  i == 0 ? '\n' : '.');
    }
}

void read_IP(){
    for (int i = 0; i < 4; ++i) {
        int t;
        scanf("%d",&t);
        IP[t] = t;
    }
}

int main(){
    int N;
    printf("%s\n", "fuck");

    scanf("%d", &N);
    printf("%d\n",N);

    while(scanf("%d", &N) == 1){
        for (int i = 0; i < N; ++i) {
            read_IP();
            print_IP();
        }
    }

    printf("%d\n",N);
    return 0;
}
