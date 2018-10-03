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
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

#define maxn 10
int T;
int N;
char table[maxn][maxn];

bool isOut(int x, int y){
    return x <  0 || y < 0 || x >= N || y >= N;
}


void dfs(int x){
    //上到下 从左到右， 编号的大小    

}

void solve(){
    
}


int main(){
    REOPEN_READ
    REOPEN_WRITE
    scanf("%d", &T);

    for(int msn = 0; msn < T; msn++){
        scanf("%d", &N);
        char c;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                c = ' ';
                while(c == ' ' || c == '\n') c = getchar();
                table[i][j] = c;
            }
        }
        

    }
    return 0;
}