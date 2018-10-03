#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <forward_list>
#include <deque>
#include <set>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
/**
 * brute force 
 */
using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

#define maxn 20
int T;
int n;
int matrix[maxn][maxn];

int first_line[maxn];

int permutation = 0;
void next_permutation(){
    int num = 0;
    for(int i = 0; i < n; i++){
        if(matrix[i]) continue;
        
    }

    
}

int main(){
    REOPEN_READ
    REOPEN_WRITE
    scanf("%d", &T);
    for(int msn = 0; msn < T; msn++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &matrix[i][j]);
            }
        }

        
        
    }
    return 0;
}