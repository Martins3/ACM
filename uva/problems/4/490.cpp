#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
#include <cassert>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

#define LEN 120

char mat[LEN][LEN];

int main(){
    REOPEN_READ
    // REOPEN_WRITE

    int i;
    int max_len = 0;
    for (i = 0; ; i++) {
        char * t = fgets(mat[i], LEN, stdin);
        if(t == NULL) break;
        max_len = max(max_len, (int)strlen(mat[i]));
        printf("%s\n", mat[i]);
    }

    for (int k = 0; k < max_len; k++) {
        for (int j = i; j >= 0; j++) {
            char c = mat[j][k];

            if(c != 0){
                putchar(c);
            }else{
                putchar(' ');
            }
        }
        putchar('\n');
    }

    return 0;
}
