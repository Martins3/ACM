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
    int RowSize;
    int ColSize;
    void clear_row(vector<vector<int>>& matrix, int row){
        for (int i = 0; i < RowSize; i++) {
            matrix[row][i] = 0;
        }
    }

    void clear_col(vector<vector<int>>& matrix, int col){
        for (int i = 0; i < ColSize; i++) {
            matrix[i][col] = 0;
        }
    }

    bool check_row(vector<vector<int>>& matrix, int row){
        for (int i = 0; i < RowSize; i++) {
            if(matrix[row][i] == 0){
                return true;
            }
        }
        return false;
    }

    bool check_col(vector<vector<int>>& matrix, int col){
        for (int i = 0; i < ColSize; i++) {
            if(matrix[i][col] == 0){
                return true;
            }
        }
        return false;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        RowSize = matrix[0].size();
        ColSize = matrix.size();

        bool left = check_col(matrix, 0);
        bool top = check_row(matrix, 0);

        for (int i = 0; i < ColSize; i++) {
            for (int j = 0; j < RowSize; j++) {
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // up
        for (int i = 1; i < RowSize; i++) {
            if(matrix[0][i] == 0){
                clear_col(matrix, i);
            }
        }

        // left
        for (int i = 1; i < ColSize; i++) {
            if(matrix[i][0] == 0){
                clear_row(matrix, i);
            }
        }

        if(top) clear_row(matrix, 0);
        if(left) clear_col(matrix, 0);
    }
};

int main(){
    vector<vector<int>> vec;
    vec.push_back(vector<int>{0, 1, 1, 1});
    vec.push_back(vector<int>{1, 0, 1, 1});
    vec.push_back(vector<int>{1, 1, 1, 1});

    Solution s;
    s.setZeroes(vec);

    for(auto s: vec){
        print_v(s);
    }
    
    return 0;
}
