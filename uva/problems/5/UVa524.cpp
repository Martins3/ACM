//
// Created by Martin on 2018/2/2.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;
#define VSCODE_READ freopen("../input.txt", "r", stdin);
#define C_READ freopen("input.txt", "r", stdin);

bool isPrime(int num){
  num = abs(num);
  if (num < 2) return false;
  if (num == 2) return true;
  if (num % 2 == 0) return false;
  for (int i = 3; i * i <= num; i += 2)
    if (num % i == 0) return false;
  return true;
}

int numbers[20];
void printTheArray(int n){
  printf("1");
  for(int i = 2; i <= n; i ++){
    printf(" %d", numbers[i]);
  }
  printf("\n");
}

void permutation(int n, int cur){
    if(cur > 1) {
      int sum = numbers[cur] + numbers[cur - 1];
      if(!isPrime(sum)) return;
    }

    if(cur == n) {
      int sum = numbers[cur] + numbers[1];
      if(!isPrime(sum)) return;
      printTheArray(n);
      return;
    }


    for(int i = 1; i <= n; i ++){
      if(cur == 0 && i > 1) return;

      bool ok = true;
      for(int j = 1; j <= cur; j ++){
        if(i == numbers[j]) {
          ok = false;
          break;
        }
      }

      if(ok){
        numbers[cur + 1] = i;
        permutation(n, cur + 1);
      }
    }
}

int main(){
    VSCODE_READ
    int N;
    int Case = 0;
    while (scanf("%d", &N) != EOF) {
       if (Case++) putchar('\n');
       printf("Case %d:\n", Case);
       permutation(N,  0);
    }
    return 0;
}
