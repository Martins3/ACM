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

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

#define maxn (200000 + 100)
int N, M;
int dragons[maxn];
int knights[maxn];

/**
 * 
 */

char no_res[] = "Loowater is doomed!";
int main(){
    REOPEN_READ
    while(scanf("%d %d", &N, &M) == 2 && N == 0 && M == 0){
        for(int i = 0; i < N; i++) scanf("%d", &dragons[i]);
        for(int i = 0; i < M; i++) scanf("%d", &knights[i]);

        sort(dragons, dragons + N);
        sort(knights, knights + M);

        int res = 0;
        
        int j = 0;
        for(int i = 0; i < N; i++){
            if(j == M){
                res = -1;
                break;
            }
            for(; j < M; j++){
                if(knights[j] > dragons[i]) {
                    res += knights[j];
                    j ++;
                    break;
                }
            }
        }

        if(res != -1){
            printf("%d\n", res);
        }else{
            printf("%s\n", no_res);
        }

    }
    return 0;
}