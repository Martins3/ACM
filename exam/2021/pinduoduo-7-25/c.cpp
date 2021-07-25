#include "leetcode/dbg.hpp"
#include <bits/stdc++.h>
using namespace std;

#define REOPEN_READ freopen("/home/maritns3/core/ACM/a.txt", "r", stdin);

bool bigger(const vector<char> &a, const vector<char> &b) {
  if (a.size() != b.size())
    return a.size() > b.size();
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i])
      return a[i] > b[i];
  }
  return true;
}

// left
void add_vec(vector<int> &res, int x, int y, int offset) {
  assert(x < 10 && y < 10);
  int N = x * y;
  // 3 * 4
  // ab = 12
  //
  // 2 1 // 向右扩散啊
  int b = N / 10;
  int a = N % 10;

  dbg(offset);

  int A = res[offset];
  int B = res[offset + 1];

  int new_A = (a + A) % 10;
  int new_B = (a + A) / 10 + b + B;

  res[offset] = new_A;
  res[offset + 1] = new_B % 10;

  offset += 2;
  int GG = new_B / 10;
  while (GG) {
    int the_val = res[offset];
    res[offset] = (the_val + 1) % 10;
    GG = (the_val + 1) / 10;
    offset++;
  }
}

void multiple(const vector<char> &a, const vector<char> &b) {
  dbg(a);
  dbg(b);
  vector<int> res(10000, 0);
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < b.size(); ++j) {
      int offset = (a.size() - i - 1) + (b.size() - j - 1);
      add_vec(res, a[i] - '0', b[j] - '0', offset);
    }
  }
  dbg(res);
  bool doit = false;
  for (int i = 10000 - 1; i >= 0; i--) {
    if (res[i])
      doit = true;
    if (doit) {
      printf("%c", res[i] + '0');
    }
  }
  printf("\n");
}


int main(int argc, char *argv[]) {
  REOPEN_READ

  int GG = 2;
  while (GG--) {

    int N = 10;
    vector<int> nums;
    while (N--) {
      int x;
      scanf("%d", &x);
      nums.push_back(x);
    }

    vector<char> a;
    vector<char> b;
    // 谁更加小，谁添加
    for (int i = nums.size() - 1; i >= 0; --i) {
      int how_many = nums[i];
      for (int f = 0; f < how_many; ++f) {
        if (bigger(a, b)) {
          b.push_back('0' + i);
        } else {
          a.push_back('0' + i);
        }
      }
    }
    multiple(a, b);
  }

  return 0;
}
