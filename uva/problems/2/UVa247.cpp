#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <forward_list>
#include <deque>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("../output.txt", "w", stdout);

int C, S, Q;


int ans[105][105];

int x, y, weight;
int a, b;
int main(){
    REOPEN_READ
    REOPEN_WRITE
    for(int i = 1; scanf("%d %d %d", &C, &S, &Q);i++){

        if(!(C + S + Q)) break;
        if(i != 1) printf("\n");

        for(int j = 0; j < 105; j++){
            for(int k = 0; k < 105; k++){
                ans[k][j] = INT_MAX;
            }
        }
        for(int j = 0; j < S; j++){
            scanf("%d %d %d", &x, &y, &weight);
            ans[x][y] = weight;
            ans[y][x] = weight;
        }

        // FW
        for(int j = 1; j <= C; j++){
            // j is middle
            for(int k = 1; k <= C; k++){
                for(int l = 1; l <= C; l++){
                    ans[k][l] = ans[l][k] = min(ans[l][k], max(ans[l][j], ans[j][k]));
                }
            }
        }

        printf("Case #%d\n", i);
        for(int j = 0; j < Q; j++){
            scanf("%d %d", &a, &b);
            int dis = ans[a][b];
            if(dis == INT_MAX)
                printf("%s\n", "no path");
            else
                printf("%d\n", dis);
        }
    }
    return 0;
}