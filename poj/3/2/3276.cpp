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
#define maxn (50 + 10)

int N;
bool facing[maxn];
bool turns[maxn]; // document if i turns or not
bool turn_locs[maxn];

#define INF 0x3f3f3f3f
int main(){
    REOPEN_READ
    //REOPEN_WRITE
    scanf("%d", &N); getchar();
    for(int i = 0; i < N; i++){
        char f;
        scanf("%c", &f); getchar(); 
        facing[i] = (f == 'F');
    }

    
    // for every K make a test
    int min_M = INF;
    int min_K = INF;
    for(int K = N; K >= 1; K --){
        int M = 0;

        int is_ok = 0;
        memset(turns, 0, sizeof(turns));
        memset(turn_locs, 0, sizeof(turn_locs));

        for(int i = 0; i < N; i++){
            // heritage
            if(i >= 1){
                turns[i] = turns[i - 1];
            }

            // cal the turns fisrt
            if(i - K >= 0){
                if(turn_locs[i- K]){
                    turns[i] = !turns[i] ;
                }
            }

            // synthesis the info to turning or not
            if((facing[i] && !turns[i]) || (!facing[i] && turns[i])){
                continue;
            }
            
            M ++;
            turn_locs[i] = true;
            turns[i] = !turns[i];
            is_ok = i;
        }

        if(is_ok + K <= N){
            if(M < min_M){
                min_M = M;
                min_K = K;
            }else if(M == min_M){
                min_K = min(min_K, K);
            }
        }
    }
    printf("%d %d\n", min_K, min_M);
    return 0;
}