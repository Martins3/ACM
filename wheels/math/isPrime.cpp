#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;
#define VSCODE_READ freopen("../input.txt", "r", stdin);
#define C_READ freopen("input.txt", "r", stdin);

bool isPrime(int n);

int main(){

    return 0;
}

/**
* 检查一个数值是不是素数
*/
bool isPrime(int num){
  num = abs(num);
  if (num < 2) return false;
  if (num == 2) return true;
  if (num % 2 == 0) return false;
  for (int i = 3; i * i <= num; i += 2)
    if (num % i == 0) return false;
  return true;
}
