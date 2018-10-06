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

#define LEN 1000
int dp[LEN][LEN];



int main(){
    REOPEN_READ
    REOPEN_WRITE
    string A;
    string B;
    while(getline(cin, A) && getline(cin, B)){
        int a = A.length(); // row
        int b = B.length(); // col


        for (int i = 0; i <= a; ++i) {
            dp[i][0] =  0;
        }

        for (int i = 0; i <= b; ++i) {
            dp[0][i] =  0;
        }

        for (int i = 1; i <= a; ++i) {
            for (int j = 1; j <= b; ++j) {
                if(A[i - 1] == B[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i -1][j], dp[i][j - 1]);
                }
            }
        }

        // for (int i = 0; i <= a; ++i) {
            // for (int j = 0; j <= b; ++j) {
                // cout <<  dp[i][j] << " ";
            // }
            // cout << endl;
        // }
        printf("%d\n",dp[a][b]);
    }
    return 0;
}
