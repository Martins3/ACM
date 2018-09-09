#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include <stdlib.h> // sort


void valid(char c){
    bool go = true;
    for (int i = 0; i < 7; ++i) {
        if(c & (1 << i)) go = !go;
    }

    if(go)
        printf("%d", 1);
    else
        printf("%d", 0);


    for (int i = 6; i >= 0; --i) {
        printf("%d", (c & (1 << i)) ? 1 : 0);
    }

    printf("\n");
}
int main(){
    char c;
    while((c = getchar()) != EOF){
        if(c == '\n') continue;
        valid(c);
    }
    return 0;
}
