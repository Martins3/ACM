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


#define MAXN 101

int matrix[MAXN][MAXN];

int main(){
    REOPEN_READ

    int len;
    while(scanf("%d", &len) == 1){
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                scanf("%d", &(matrix[i][j]));
            }
        }

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                printf("%d%c", matrix[j][i], j + 1 == len ? '\n' : ' ');
            }
        }
    }

    return 0;
}
