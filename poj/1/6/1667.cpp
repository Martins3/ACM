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

int T;
int M, N;

/**
 * 把 M 个同样的苹果放在 N 个同样的盘子里，
 * 允许有的盘子空着不放，问共有多少种不同的分法？
 * (用K表示）5，1，1和1，5，1 是同一种分法
 */

int RES;
int debug[20];
int pointer;
void rec_handle(int Max, int pos, int num){

    //　使用鸽巢原理提前终止
    if(num / pos + (int)(num % pos != 0) > Max) return;

    //　如果当前数值的不够，结束
    if(num < 0) return;

    pointer ++;
    // 最后一个位置
    if(pos == 1 && num <= Max){
        RES ++;
        debug[pointer] = num;
        for (int i = 0; i < N; ++i) {
            printf("%d ", debug[i]);
        }
        printf("\n");
        return;
    }


    for (int j = Max; j >= 0; --j) {
        debug[pointer] = j;
        rec_handle(j, pos - 1, num - j);
    }
    pointer --;
}


void handle(int M, int N){
    if(N == 1){
        RES = 1;
        return;
    }
    for (int i = 1; i <= M; ++i) {

        pointer = 0;
        debug[pointer] = i;
        rec_handle(i, N - 1, M - i);
    }
}
int main(int argc, char *argv[]) {
    REOPEN_READ
    REOPEN_WRITE
    scanf("%d", & T);
    while(T--){
        RES = 0;
        scanf("%d%d", &M, &N);
        //　保证之后的数值逐渐变小
        handle(M, N);
        printf("RES is %d\n", RES);
    }
    return 0;
}
