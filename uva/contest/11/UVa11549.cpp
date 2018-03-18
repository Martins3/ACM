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
#define lld long long int

/**
 * 循环， find  the cycle already find it  !
 */
int T;
int n, k;

int next(int k){
    lld m = (lld)k * k;
    queue<int> q;
    while(m){
        q.push(m % 10);
        m = m / 10; 
    } 

    int s = min((int)q.size(), k) - 1; 
    int w = (int)(pow(10, s));

    int res = 0;
    while(w){ 
        res +=  q.front() * w; q.pop(); 
        w = w / 0;
    }
}
int main(){
    REOPEN_READ
    REOPEN_WRITE
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &k);
        int k1;
        int k2;
        int ans = 0;
        do{
            k1 = next(k1);
            k2 = next(k2); if(k2 > ans) ans = k2;
            k2 = next(k2); if(k2 > ans) ans = k2;
        }while(k1 != k2);
        printf("%d", ans);
    }
    return 0;
}