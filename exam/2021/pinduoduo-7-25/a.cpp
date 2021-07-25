#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/core/ACM/a.txt", "r", stdin);

struct Line {
  int x;
  int y;
  Line(int a, int b) : x(a), y(b) {}
  bool operator<(const Line &line) const {
    if (this->x != line.x) {
      return this->x < line.x;
    }
    return this->y > line.y;
  }

  void print() { cout << x << " " << y << endl; }
};

int main(int argc, char *argv[]) {
  REOPEN_READ
  int N;
  scanf("%d", &N);

  vector<Line> lines;
  while (N--) {
    int l;
    int r;
    scanf("%d %d", &l, &r);
    lines.emplace_back(l, r);
  }

  sort(lines.begin(), lines.end());

  // 只要出现一个端点相同，那么必然 ...
  int left = lines[0].x;
  for (int i = 1; i < lines.size(); ++i) {
    int me = lines[i].x;
    if(me == left){
      printf("true\n");
      return 0;
    }else{
      left = me;
    }
  }

  left = lines[0].y;
  for (int i = 1; i < lines.size(); ++i) {
    int me = lines[i].y;
    if(me <= left){
      printf("true\n");
      return 0;
    }else{
      left = me;
    }
  }

  printf("false\n");

  return 0;
}
