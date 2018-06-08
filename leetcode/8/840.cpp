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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

class Solution {
public:
    bool range(vector<vector<int> > & grid, int x, int y){
        int num = 0x1ff << 1;
        for (int i = x; i < x + 3; ++i) {
            for (int j = y; j < y + 3; ++j) {
                int a = grid[i][j];
                if(a < 1 || a > 9) return false;
                num = num ^ (1 << a);
            }
        }
        return !num;
    }

    bool check(vector<vector<int> > & grid, int x, int y){
        if(!range(grid, x, y)) return false;
        int sum = -1;
        int accu;
        for (int i = x; i < x + 3; ++i) {
            accu = 0;
            for (int j = y; j < y + 3; ++j) {
                accu += grid[i][j];
            }
            if(sum == -1){
                sum = accu;
            }else{
                if(sum != accu) return false;
            }
        }

        for (int j = y; j < y + 3; ++j) {
            accu = 0;
            for (int i = x; i < x + 3; ++i) {
                accu += grid[i][j];
            }
            if(sum != accu) return false;
        }

        accu = 0;
        for (int i = 0; i < 3; ++i) {
            accu += grid[i + x][i + y];
        }
        if(sum != accu) return false;

        accu = 0;
        for (int i = 2; i >= 0; --i) {
            accu += grid[i + x][i + y];
        }
        if(sum != accu) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int> >& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        for (int i = 0; i < row; ++i) {
            if(i + 2 >= grid.size()) continue;
            for (int j = 0; j < col; ++j) {
                if(j + 2 >= grid[0].size()) continue;
                if(check(grid, i, j)){
                    res ++;
                }
            }
        }
        return res;
    }
};
int main(){
    REOPEN_READ
    return 0;
}
