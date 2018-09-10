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
#include "../info.hpp"

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        std::vector<vector<int> > matrix(n, vector<int>(n)) ;


        int matrixRowSize = n;
        int matrixColSize = n;

        int x = 0;
        int y = 0;

        int D = 1;

        while(matrixRowSize > 0 && matrixColSize > 0){
            // 上
            for (int i = y; i < matrixColSize + y; ++i)
                matrix[x][i] = D++;
            x ++;
            matrixRowSize --;
            if(matrixRowSize <= 0 || matrixColSize <= 0) break;

            // 右
            for (int i = x; i < x + matrixRowSize ; ++i)
                matrix[i][y + matrixColSize - 1] = D++;
            matrixColSize --;
            if(matrixRowSize <= 0 || matrixColSize <= 0) break;

            // 下
            for (int i = y + matrixColSize - 1; i >= y ; --i) {
                matrix[x + matrixRowSize - 1][i] = D++;
            }
            matrixRowSize --;
            if(matrixRowSize <= 0 || matrixColSize <= 0) break;

            // 左
            for (int i = x + matrixRowSize - 1; i >= x; --i)
                matrix[i][y] = D++;
            matrixColSize --;
            if(matrixRowSize <= 0 || matrixColSize <= 0) break;
            y ++;
        }
        return matrix;
    }
};

int main(int argc, const char *argv[]){
    Solution s;
    vector<vector<int> > a = s.generateMatrix(10);
    for (int i = 0; i < 10; i++) {
        print_v(a[i]);
    }

    return 0;
}
