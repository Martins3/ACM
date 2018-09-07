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

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int matrixRowSize = matrix.size();
        if(!matrixRowSize) return vector<int>();
        int matrixColSize = matrix[0].size();
        if(!matrixColSize) return vector<int>();
        std::vector<int> res(matrixRowSize * matrixColSize, 0);

    int loc = 0;
    int x = 0;
    int y = 0;

    while(matrixRowSize > 0 && matrixColSize > 0){
        // 上
        for (int i = y; i < matrixColSize + y; ++i)
            res[loc++] = matrix[x][i];
        x ++;
        matrixRowSize --;
        if(matrixRowSize <= 0 || matrixColSize <= 0) break;

        // 右
        for (int i = x; i < x + matrixRowSize ; ++i)
            res[loc++] = matrix[i][y + matrixColSize - 1];
        matrixColSize --;
        if(matrixRowSize <= 0 || matrixColSize <= 0) break;

        // 下
        for (int i = y + matrixColSize - 1; i >= y ; --i) {
            res[loc++] = matrix[x + matrixRowSize - 1][i];
        }
        matrixRowSize --;
        if(matrixRowSize <= 0 || matrixColSize <= 0) break;



        // 左
        for (int i = x + matrixRowSize - 1; i >= x; --i)
            res[loc++] = matrix[i][y];
        matrixColSize --;
        if(matrixRowSize <= 0 || matrixColSize <= 0) break;
        y ++;
    }
    return res;
    }
};


int main(){
    
    return 0;
}

