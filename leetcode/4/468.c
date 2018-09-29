#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include<stdlib.h> // sort
#include<limits.h> // INT_MAX
#include<math.h> // sqrt

char nums[8][8];
char len[8];
char res[20];

bool is4(char * IP){
    memset(nums, 0, sizeof(nums));
    int off = 0;
    int num_inx = 0;

    // num is too much or too little
    while(IP[off] != '\0'){
        if(num_inx == 4) return false;

        int k = 1;
        while(IP[off] != '.' && IP[off] != '\0'){
            if(k == 3) return false;
            nums[num_inx][k] = IP[off];
            off ++;
            k++;
        }
        if(k == 0) return false;
        if(IP[off] == '.'){
            off ++;
            num_inx ++;
        }
        len[num_inx] = k;
    }

    if(num_inx != 4) return false;

    for (int i = 0; i < 4; ++i) {
        int num = 0;
        // leading zero
        // isdigit in decimal
        
        for (int j = 0; j < len[i]; j++) {
            if(j == 0 && nums[i][j] == '0') return false;
            num *= 10;
            int isNum = nums[i][j] - '0';
            if(isNum < 0 || isNum > 9) return false;
            num += isNum;
        }
        // in range
        if(num >= 256) return false;
    }

    return true;
}

int isHex(char a){
    if(a >= '0' && a <= '9') return a - '0';
    if(a >= 'a' && a <= 'f') return a = 'a';
    if(a >= 'A' && a <= 'F') return a - 'A';
    return -1;
}


bool is6(char * IP){
    memset(nums, 0, sizeof(nums));
    int off = 0;
    int num_inx = 1;

    // num is too much or too little
    while(IP[off] != '\0'){
        if(num_inx == 8) return false;

        int k = 0;
        while(IP[off] != ':' && IP[off] != '\0'){
            if(k == 4) return false;
            nums[num_inx][k] = IP[off];
            if(isHex(IP[off]) == -1) return false;
            off ++;
            k++;
        }
        // length can not be 0
        if(k == 0) return false;
        if(IP[off] == ':'){
            off ++;
            num_inx ++;
        }
        len[num_inx] = k;
    }

    if(num_inx != 8) return false;

    for (int i = 0; i < 8; ++i) {
        int num = 0;
        for (int j = 0; j < len[i]; j++) {
            num = num << 4;
            num += isHex(nums[i][j]);
        }
        if(num >> 16) return false;
    }

    return true;
}


char* validIPAddress(char* IP) {

    if(is4(IP)){
        strcpy(res, "IPv4");
        return res;
    }

    if(is6(IP)){
        strcpy(res, "IPv6");
        return res;
    }

    strcpy(res, "Neither");
    return res;
}

int main(){
    char ip[] = "2001:0db8:85a3:0:0:8A2E:0370:7334:";
    printf("%s\n", validIPAddress(ip));
    return 0;
}
