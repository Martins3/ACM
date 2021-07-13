#include <bits/stdc++.h>
using namespace std;

#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);
class Solution {
public:
    int arr[100];
    int fib(int n) {
      arr[0] = 0;
      arr[1] = 1;
      for (int i = 2; i <= n; ++i) {
        arr[i] = arr[i-1] + arr[i - 2];
      }
      return arr[n];
    }
};
int main(int argc, char *argv[]){
  
  return 0;
}
