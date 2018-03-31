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

int C;
int N; // nums
int H; // base
int R; // 2* R * (i)
int rT; // time

#define Gravity 10.0
#define maxn 1000
double pos[maxn];
int main(){
    REOPEN_READ
    //REOPEN_WRITE
    scanf("%d", &C);
    while(C --){
        scanf("%d %d %d %d", &N, &H, &R, &rT);
        for(int i = 0; i < N; i++){
            double T = rT - i;
            double h = H;
            if(T <= 0){
                pos[i] = h + 2.0 * R * i  / 100;
                continue;
            }
            double t = sqrt(2.0 * h / Gravity);
            int times = int(T / t);
            double spt = T - times * t;
            // up down
            if(times == 1){
                pos[i] = 1.0 / 2 * Gravity *  spt * spt + 2 * R * i / 100.0;
            }else{
                pos[i] = h - 1.0 / 2 * Gravity *  spt * spt + 2 * R * i / 100.0;
            }
        }
        sort(pos, pos + N);
        for(int i = 0; i < N; i++){
            printf("%.2f%c", pos[i], i == N - 1 ? '\n' : ' ');
        }
    }

    return 0;
}