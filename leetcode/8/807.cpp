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

using namespace std;

int A[50];
int B[50];

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int> >& grid) {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); j++) {
                A[i] = max(A[i], grid[i][j]);
                B[j] = max(B[j], grid[i][j]);
            }
        }

        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); j++) {
                 res += min(A[i], B[j]) - grid[i][j];
            }
        }

        return res;
    }
};

int main(){
    return 0;
}
