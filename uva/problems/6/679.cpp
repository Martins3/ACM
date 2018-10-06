#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <forward_list>
#include <deque>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("../output.txt", "w", stdout);

# define SIZE 1048576

bool Node[SIZE + 1];
int N;
int D;
int I;
int res; 

bool is_leaf(int num){
    if(num * 2 > pow(2, D) - 1) return true;
    return false;
}

int main(){
    REOPEN_READ
    REOPEN_WRITE
    scanf("%d", &N);
    while(N --){
        scanf("%d %d", &D, &I);
        memset(Node, false, sizeof(Node));
        
     
        printf("%d\n", res);
    }
    return 0;
}

