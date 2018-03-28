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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);
#define maxn 100010

int loc[maxn];
int N;
int C;

bool check(int dis){
    int t = C - 1;
    int last = loc[0];
    for(int i = 1; i < N; i++){
        if(loc[i] - last >= dis){
            last = loc[i];
            t --;
            if(t == 0) return true;
        }
    }
    return false; 
}


int main(){
    REOPEN_READ
    //REOPEN_WRITE
    scanf("%d %d", &N, &C);
    for(int i = 0; i < N; i++){
        scanf("%d", &loc[i]);
    }
    sort(loc, loc + N);

    int l = 1;
    int r = loc[N - 1] - loc[0];
    int m = l + (r - l) / 2;
    while(l + 1 < r) {
        if(check(m)){
            l = m; 
        }else{
            r = m - 1;
        } 
        m = l + (r - l) / 2;
    }
    
    int res = 0;
    if(check(l)) res = l;
    if(check(r)) res = r;
    printf("%d\n", res);
    return 0;
}