#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;
#define UVa freopen("../input.txt", "r", stdin);
#define VSCODE_READ freopen("../../../input.txt", "r", stdin);
#define C_READ freopen("input.txt", "r", stdin);

/**
* every time added a char, check
* if there is adjacent same substring, some one wound check
* and if added successfully, then counting will be added !
*/

int chars[100]; // start form 0, just 0 1 2 and so on

void printRes(int n){
  for(int i = 0; i < n; i ++){
    if(i % 4 == 0 && i != 0 && i != 64) putchar(' ');
    if(i == 64) putchar('\n');
    char c = chars[i] + 'A';
    printf("%c", c);
  }
  printf("%d\n", n);
}

int counter;
int Range; // form 0 to Range - 1

// cur position is newly added
bool check(int cur){
  for(int length = 1; cur + 1 - 2 * length >= 0 ; length ++){
      for(int i = 0; i < length ; i ++){
        // todo it  !
      }
  }
}

void backTracking(int cur){

}

int main(){
    UVa

    int kth;
    int Num;
    while (scanf("%d %d\n", &kth, &Num) != EOF) {
      counter = 0;

    }
    return 0;
}
