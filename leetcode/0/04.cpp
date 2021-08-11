#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

// 真正的挑战巅峰


/*
 * 首先 :  装换为一般的题目, 如何找 k 的数值
 *
 * 对于 k = 2n + 1，当 B[n] > A[n] 的时候，说明不可能出现在 A 的 [0, n] 个中间
 * 因为如果出现在其中，需要需要从 B 中间至少找到 n 个比 A[n] 小的，这显然不可以
 * 因此可以直接去掉 n 个
 * 
 * 对于 k = 2n 的时候，B[n] > A[n] 类似
 * 
 * 1. 如果 A[n] == B[n] 的情况下，如何处理?
 *    1. 实际上，从 A 中，从 n 向下找，知道比 B[n] 小的就可以
 * 2. 如果一个数组的长度不足 n ，怎么办法?
 */


int main(int argc, char *argv[]){
  return 0;
}
