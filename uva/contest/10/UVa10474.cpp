#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <forward_list>
#include <deque>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
#include <iterator>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("../output.txt", "w", stdout);
int N;
int Q;
int main(){
    REOPEN_READ
    REOPEN_WRITE
    int index = 1;
    while(scanf("%d %d", &N, &Q)){
        if(Q == 0 || N == 0) break;
        vector<int>  num;
        for(int i = 0; i < N; i++){
            int t;
            scanf("%d", &t);
            num.push_back(t);
        }
        sort(num.begin(), num.end());

        printf("CASE# %d:\n", index++);
        for(int i = 0; i < Q; i++){
            int t;
            scanf("%d", &t);
            auto j = lower_bound(num.cbegin(), num.cend(), t);
            if(*j == t){
                printf("%d found at %d\n", t, (int)distance(num.cbegin(), j) + 1);
            }else{
                printf("%d not found\n", t);
            }
        }
    }
    return 0;
}