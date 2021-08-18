#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/core/ACM/a.txt", "r", stdin);

int nums[2000];
int main(int argc, char *argv[]){
  REOPEN_READ

  int N;
  scanf("%d", &N);
  long int mini = 0x3f3f3f3f3f;
  long int maxi = 0;
  long int sum = 0;
  for (int i = 0; i < N; ++i) {
    int val;
    scanf("%d", &val);
    sum += val;
    if(val > maxi)
      maxi = val;

    if(val < mini)
      mini = val;
  }

  long int x = sum - (mini + maxi) * (maxi - mini + 1) / 2;
  printf("%ld\n", x);

  return 0;
}
