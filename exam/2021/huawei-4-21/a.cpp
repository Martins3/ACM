#include <bits/stdc++.h>
// #include "leetcode/dbg.hpp"

using namespace std;

#define REOPEN_READ freopen("/home/maritns3/core/ACM/a.txt", "r", stdin);
int main(int argc, char *argv[]){
  REOPEN_READ

    int N;
    int M;
    scanf("%d %d", &N, &M);
    vector<int> left(24, M);
    // dbg(left);

    while(N --){
      int start;
      int end;
      int num;
      scanf("%d %d %d", &start, &end, &num);
      bool ok = true;
      
      for (int i = start; i < end; ++i) {
        if(left[i] < num){
          ok = false;
        }
      }
      if(!ok) continue;

      for (int i = start; i < end; ++i) {
        left[i] -= num;
      }
    }
    
    for (int i = 0; i < 24; ++i) {
      printf("%d ", M - left[i]);
    }
    printf("\n");
  return 0;
}
