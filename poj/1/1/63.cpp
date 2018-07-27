#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define VSCODE_READ freopen("../../../input.txt", "r", stdin);

#define MAX_INPUT 101
int num [MAX_INPUT][MAX_INPUT];
int res [MAX_INPUT][MAX_INPUT];



int main(){
    VSCODE_READ
    int rowNum;
    scanf("%d", &rowNum);
    
    for(int i = 1; i <= rowNum; i++){
        for(int j = 1; j <= i; j++){
            int temp;;
            scanf("%d", &temp);
            num[i][j] = temp;
        }
    }

    // 处理最后一行
    for(int i = 1; i <= rowNum; i++){
        res[rowNum][i] = num[rowNum][i];
    }
    
    for(int i = rowNum - 1; i >= 1; i--){
        for(int j = 1; j <= i; j++){
            res[i][j] = max(res[i + 1][j], res[i + 1][j + 1]) + num[i][j];
        }
    }
    
    printf("%d\n", res[1][1]);
    return 0;
}