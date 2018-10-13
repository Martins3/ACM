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
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);


/**
 * Understanding bellman-ford from bp perspective !
 * If we want to find the path, do mini-path sysmetricly
 */

typedef long long int lld;

int Graph[10][100];
lld dis[10][101];
int R;
int C;
stack<int> Res;

void debug(){
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%15lld ", dis[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

void find(int r, int c){
    if(c == C - 1){
        printf("%d\n", r + 1);
        return;
    }
    printf("%d ", r + 1);


    vector<int> a;
    int y = c + 1;
    for (int bias = -1;  bias <= 1; bias ++) {
        int x = (R + r + bias) % R;
        if(dis[x][y] + Graph[r][c] == dis[r][c]){
            a.push_back(x);
        }
    }
    sort(a.begin(), a.end());
    find(a[0], y);
}

int main(){
    REOPEN_READ
    REOPEN_WRITE

    while(scanf("%d%d", &R, &C) == 2){
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                scanf("%d", &(Graph[i][j]));
            }
        }


        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                dis[i][j] = INT_MAX;
            }
        }

        for (int i = 0; i < R; i++) {
            dis[i][C - 1] = Graph[i][C - 1];
        }
        

        for (int i = 0; i < R * C; i++) {
            for (int i = 0; i < R; i++) {
                for (int j = C - 1; j >= 1; j--) {
                    for (int bias = -1;  bias <= 1; bias ++) {
                        int x = (R + i + bias) % R;
                        int y = j - 1;
                        if(dis[x][y] - Graph[x][y] > dis[i][j]){
                            dis[x][y] = Graph[x][y] + dis[i][j];
                        }
                    }
                    // debug();
                }
            }
        }


        int who;
        int M = INT_MAX;
        for (int i = 0; i < R; i++) {
            if(M > dis[i][0]){
                who = i;
                M = dis[i][0];
            }
        }

        find(who, 0);
        printf("%d\n", M);
    }
    return 0;
}
