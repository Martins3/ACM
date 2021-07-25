#include <bits/stdc++.h>
#include "leetcode/dbg.hpp"
using namespace std;

#define REOPEN_READ freopen("/home/maritns3/core/ACM/a.txt", "r", stdin);

int arr[100];
int daxiao = 0;

int insert(int x) {
  cout << x << endl;

  arr[daxiao]= x;
  for (int i = daxiao - 1; i >= 0; --i) {
    if (arr[i] == x) {
      int res = daxiao - i + 1;
      daxiao = i;
      return res;
    }
  }
  daxiao++;
  return 0;
}

int main(int argc, char *argv[]) {
  REOPEN_READ
  int N;
  scanf("%d", &N);
  vector<int> A;
  vector<int> B;
  int n = N;
  while (n--) {
    int l;
    scanf("%d", &l);
    A.push_back(l);
  }

  n = N;
  while (n--) {
    int l;
    scanf("%d", &l);
    B.push_back(l);
  }

  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());

  // dbg(A);
  // dbg(B);

  int A_score = 0;
  int B_score = 0;

  while (!A.empty() || !B.empty()) {
    while (!A.empty()) {
      int res = insert(A.back());
      A.pop_back();
      if (res == 0)
        break;
      A_score += res;
    }

    while (!B.empty()) {
      int res = insert(B.back());
      B.pop_back();
      if (res == 0)
        break;
      B_score += res;
    }
  }

  for (int i = 0; i < daxiao; ++i) {
    if(arr[i] % 2){
      A_score ++;
    }else{
      B_score ++;
    }
  }
  printf("%d %d\n", A_score, B_score);

  return 0;
}
