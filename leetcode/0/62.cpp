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

/**
 * 计算组合数
 * (m, n) = (m - 1, n - 1) + (m - 1, n)
 */

int D[101][101];


class Solution {
public:


    // diff
    int init_D(int m, int n){
        for (int i = 0; i <= m; i++) {
            D[i][0] = 1;
            D[i][i] = 1;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j < m ; j++) {
                D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
            }
        }

        // for (int i = 0; i <= m; i++) {
            // for (int j = 0; j <= m; j++) {
                // cout << D[i][j] << " ";
            // }
            // cout << endl;
        // }

        return D[m][n];
    }
    
    int uniquePaths(int m, int n) {
        return init_D(m + n - 2, n - 1);
    }
};

int main(){
    Solution s;
    cout << s.uniquePaths(7, 3);
    return 0;
}
