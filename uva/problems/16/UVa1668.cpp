#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int MAXN = 100010;

int T,N;
int sum[MAXN],tmax[MAXN];

int main(){
    int a,b,c;
    scanf("%d",&T);
    for(int tt = 1; tt <= T; ++tt){
        memset(sum,0,sizeof(sum));
        memset(tmax,0,sizeof(tmax));
        scanf("%d",&N);
        for(int i = 1; i < N; ++i){
            scanf("%d%d%d",&a,&b,&c);
            sum[a] += c;
            sum[b] += c;
            tmax[a] = max(tmax[a],c);
            tmax[b] = max(tmax[b],c);
        }
        ll ans = 0;
        for(int i = 1; i <= N; ++i){
            if(tmax[i] > sum[i] - tmax[i]){
                ans += tmax[i] + tmax[i] - sum[i];
            }
            else if(sum[i] & 1) ans++;
        }
        printf("Case #%d: %lld\n",tt,ans >> 1);
    }
    return 0;
}