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

#define LEN 8
int N, M;

int tree[1 << LEN];
int nodes[LEN];
int input[LEN];
char var[5];
int main(){
    
    REOPEN_READ
    REOPEN_WRITE
    int fuck = 0;
    while(scanf("%d", &N), N){
        fuck ++; 
        for(int i = 0; i < N; i++){
            scanf("%s", var);
            nodes[i] = var[1] - '1';
        }

        getchar();
        for(int i = 0; i < (1 << N); i++){
            tree[i] = getchar() - '0';
        }

        scanf("%d", &M); getchar();
        // cout << N << endl;
        // cout << M << endl;
        string line;
        printf("S-Tree #%d:\n", fuck);
        for(int i = 0; i < M; i++){
            getline(cin, line);
            for(int i = 0; i < N; i++){
                input[i] = line[i] - '0';
            }
            
            int index = 0;
            for(int i = 0; i < N; i++){
                if(input[nodes[i]]) index += (1 << (N - i - 1));
            }

            printf("%d", tree[index]);
        }
        printf("\n\n");
    }
    return 0;
}