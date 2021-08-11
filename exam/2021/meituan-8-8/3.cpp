#include <bits/stdc++.h>
#include "leetcode/dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/core/ACM/a.txt", "r", stdin);

int main(int argc, char *argv[]) {
  REOPEN_READ

  set<int, greater<long long int>> s;
  int N;
  scanf("%d", &N);
  vector<int> nums;
  while (N--) {
    int tmp;
    scanf("%d", &tmp);
    nums.push_back(tmp);
  }

  long long int res = 0;
  for (int i = 0; i < nums.size(); ++i) {
    int num = nums[i];
    // dbg(s);
    auto it = s.upper_bound(num);
    if(it != s.end()){
      res += (*it) * (i + 1) ;
    }
    s.insert(num);
  }
  printf("%lld", res);
  return 0;
}
