#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include<stdlib.h> // sort
#include<limits.h> // INT_MAX
#include<time.h>

int Days[] = {31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int day(int year, int m){
    if(m == 1){
        if((year % 4 == 0 && year % 100) || year % 400 == 0) return 29;
        return 28;
    }
    return Days[m];
}

int main(){

    int year;
    int days;
    while(scanf("%d %d", &year, &days) == 2){
        int mon;
        for (mon = 0; days - day(year, mon) >= 1; ++mon) {
            days -= day(year, mon);
        }
        printf("%04d-%02d-%02d\n", year, mon + 1, days);
    }
    return 0;
}
