#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/core/ACM/a.txt", "r", stdin);

int main(int argc, char *argv[]) {
  REOPEN_READ

  char last_one = ' ';
  vector<char> res;
  for (int i = 0; i < 100000 + 10; ++i) {
    char c;
    if(!scanf("%c", &c)) break;

    if(c == '\0') break;
    if(c == EOF) break;
    if (c == '\n') {
      break;
    }
    if (c != ' '){
      if(c != last_one){
        putchar(c);
        last_one = c;
      }
    }
  }
  return 0;
}
