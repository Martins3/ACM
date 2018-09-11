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

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res; 
        int Row = matrix.size();
        if(!Row) return res;
        int Col = matrix[0].size();
        if(!Col) return res;

        int A = 0;
        int B = 0;

        while(true){
            // 上
            for (int i = B; i < Col + B; i++) {
                res.push_back(matrix[A][i]);
            }
            Row --;
            A ++;
            if(Row <=0) break;

            // 右
            for (int i = A; i < A + Row; i++) {
                res.push_back(matrix[i][B + Col - 1]);
            }
            Col --;
            if(Col <= 0) break;

            // 下
            for (int i = Col + B - 1; i >= B; i--) {
                res.push_back(matrix[A + Row - 1][i]);
            }
            Row --;
            if(Row <=0) break;
            
            // 左
            for (int i = A + Row - 1; i >= A; i--) {
                res.push_back(matrix[i][B]);
            }
            Col --;
            B ++;
            if(Col <= 0) break;
        }

        return res;
    }
};

int main(){
    
    
    return 0;
}
