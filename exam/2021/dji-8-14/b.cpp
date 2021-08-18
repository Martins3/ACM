#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/core/ACM/a.txt", "r", stdin);


int main(int argc, char *argv[]){
  REOPEN_READ

  double base;
  int exp;
  scanf("%lf %d", &base, &exp);
  long double res = 1;
  for (int i = 0; i < exp; ++i) {
    res *= base;
  }
  printf("%.6lf\n", res);
  return 0;
}
