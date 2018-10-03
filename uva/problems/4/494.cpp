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

char A [100000];

int counter(){
    int sum = 0;
    bool in = false;
    int i = 0;

    while(A[i] != '\0'){
        if(!isalpha(A[i])){
            in = false;
        }else{
            if(!in){
                sum ++;
            }
            in = true;
        }
        i ++;
    }
    return sum;
}
int main(){
    REOPEN_READ
    // REOPEN_WRITE
    
    while(fgets(A, 100000, stdin) != NULL){
        printf("%d\n", counter());
        // memset(A, 0, sizeof(A));
    }

    return 0;
}
