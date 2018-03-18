#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;
#define VSCODE_READ freopen("../../../input.txt", "r", stdin);
#define C_READ freopen("input.txt", "r", stdin);

#define MAX_INPUT 12881
int f[MAX_INPUT];

int main(){
    VSCODE_READ

    int charmNum;
    int weightLimit;
    scanf("%d %d", &charmNum, &weightLimit);

    for(int i = 0; i < charmNum; i++){
        int w, d;
        scanf("%d %d", &w, &d);
        for(int j = weightLimit; j >= 1 ; j--){
            if(j >= w) f[j] = max(f[j], f[j - w] + d); 
        }
    } 

    printf("%d", f[weightLimit]);
    return 0;
};