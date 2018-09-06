#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
#include <cassert>

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

char num[300];

int main(){
    REOPEN_READ

    int a;
    while(true){
        if(scanf("%d", &a) != 1) break;
        if(a < 0 || a > 255){
            printf("No!\n");
            while(getchar() != '\n');
            continue;
        }
        getchar();

        scanf("%d", &a);
        if(a < 0 || a > 255){
            printf("No!\n");
            while(getchar() != '\n');
            continue;
        }
        getchar();

        scanf("%d", &a);
        if(a < 0 || a > 255){
            printf("No!\n");
            while(getchar() != '\n');
            continue;
        }
        getchar();

        scanf("%d", &a);
        if(a < 0 || a > 255){
            printf("No!\n");
            while(getchar() != '\n');
            continue;
        }
        getchar();
        
        printf("Yes!\n");
    }



    return 0;
}
