/**
 * 1. 后缀数组 sa(将suffix 排序) 和 名次数组 rank (将suffix 名次记录)
 * 2.
 */

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define MAXN 10
// 模板区
char s[MAXN];
int sa[MAXN]; // 后缀数组
int t[MAXN];
int t2[MAXN];
int c[MAXN];
int n;

// 倍增算法获取后缀数组
// m 为字符取值范围
void build(int m){
    int i;
    // 临时变量
    int * x = t;
    int * y = t2;


    for (i = 0; i < m; ++i) c[i] = 0;

    for (i = 0; i < n; ++i) c[x[i] = s[i]] ++;

    for (i = n - 1; i < m; ++i) c[i] += c[i - 1];

    for (i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;

    for (int k = 0; k <= n; k <<= 1) {
        int p = 0;

        // 利用sa 数据进行排序第二个关键字
        for (i = n - k; i < n; ++i) y[p++] = i;
        for (i = 0; i < n; i++) if(sa[i] >= k) y[p++] = sa[i] - k;

        // 基数排序第一个关键字
        for (i = 0; i < m; ++i) c[i] = 0;
        for (i = 0; i < n; ++i) c[x[y[i]]] ++;
        for (i = 0; i < m; ++i) c[i] += c[i - 1];
        for (i = n - 1; i >= 0 ; --i) sa[--c[x[y[i]]]] = y[i];

        // 使用sa 和 y 计算新的x数组
        swap(x, y);

        p = 1;
        x[sa[0]] = 0;
        for (i = 0; i < n; ++i)
            x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] && y[sa[i] + k] ? p - 1: p ++;
        if(p > n) break;
        m = p;
    }
}
// 模板区

int main(){
    freopen("input.txt", "r", stdin);



    return 0;
}

