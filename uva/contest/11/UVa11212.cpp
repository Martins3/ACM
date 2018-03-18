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

int num[10];

int main(){
    int N;
    while (scanf("%d\n", &N)) {
      if(!N) break;
      for(int i = 0; i < N; i ++){
        scanf("%d\n", &(num[i]));
      }

    }
    return 0;
}
