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

#define maxn (100000 + 10)

#define INF 0x3f3f3f3f


int test_case;
int N;
int num[maxn];
int S;

int main(){
    REOPEN_READ
    //REOPEN_WRITE
    scanf("%d", &test_case);
    while(test_case --){
        scanf("%d %d", &N, &S);
        for(int i = 0; i < N; i++){
            scanf("%d", &num[i]);
        }

        int left = 0;
        int right = 0;
        int sum = num[left];
        int res = INF;

        while(true){
            
            while(true){
                right ++;
                if(right >= N) break;
                sum += num[right];
                if(sum >= S) break; 
            }

            if(sum < S) break;

            while(left < N && sum >= S){
                res = min(res, right - left + 1);
                sum -= num[left];
                left ++;
            }
        }
        if(res ==  INF) res = 0;
        printf("%d\n", res);
    }
    return 0;
}