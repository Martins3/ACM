#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/core/ACM/a.txt", "r", stdin);

int main(int argc, char *argv[]){
  REOPEN_READ
  int T;
  scanf("%d", &T);
  while(T --){
    int N;
    int K;
    scanf("%d", &N);
    scanf("%d", &K);
    vector<int> nums;
    for (int i = 0; i < N; ++i) {
      int tmp;
      scanf("%d", &tmp);
      nums.push_back(tmp);
    }
    sort(nums.begin(), nums.end());
    if(K == 0){
      printf("NO\n");
      continue;
    }

    nums.push_back(N);
    if(nums[K] == nums[K - 1]){
      printf("NO\n");
    }else{
      printf("YES\n");
      printf("%d\n", nums[K - 1] + 1);
    }

  }

  return 0;
}
