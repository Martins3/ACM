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

#define maxn 10010

#define lld long long int
lld cables[maxn];



int N;
int K;

bool check(lld len){
    if(!len) return true;
    int s = 0;
    for(int i = 0; i < N; i++){
        lld l = cables[i];
        s += l / len;
    }
    return s >= K;
}
int main(){
    REOPEN_READ
    //REOPEN_WRITE
    scanf("%d %d", &N, &K);
    lld r = 0;
    for(int i = 0; i < N; i++){
        double t;
        scanf("%lf", &t);
        t *= 100;
        cables[i] = (lld)t; 
        r += cables[i];
    }
    
    lld l = 0;
    lld m = l + (r - l) / 2;

    while(l + 1 < r){
        if(!check(m)){
            r = m - 1;
        }else{
            l = m;
        }

        m = l + (r - l) / 2;
    }

    lld res = 0;
    if(check(l)) res = l;
    if(check(r)) res = r;

    if(res == 0) printf("%d.00", 0);
    else printf("%.2f", res / 100.0);
    return 0;
}

/**
 * bug log:
 * check 函数的没有的检查的是否出现的 divede by zero
 */