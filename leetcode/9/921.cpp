#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

class Solution {
public:
  int minAddToMakeValid(string s) {
    int left = 0;
    int need = 0;
    for (auto c : s) {
      if (c == '(') {
        left++;
      }else{
        if(!left){
          need ++;
        }else{
          left --;
        }
      }
    }
    return left + need;
  }
};

int main(int argc, char *argv[]) { return 0; }
