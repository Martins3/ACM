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
    int rows;
    int cols;
    char * * matrix;
    bool ** visited;
    char * str;
    bool getNei(int a, int b, int pos){
        if(a == 0 && pos == 1) return false;
        if(a == rows - 1 && pos == 2 ) return false;
        if(b == 0 && pos == 3) return false;
        if(b == cols - 1 && pos == 4) return false;

        return true;
    }

    bool find(int a, int b, int loc){
        if(visited[a][b]) return false;

        visited[a][b] = true;
        if(matrix[a][b] == str[loc]){
            if(str[loc + 1] == '\0') return true;
            if(getNei(a, b, 1) && find(a - 1, b, loc + 1)) return true;
            if(getNei(a, b, 2) && find(a + 1, b, loc + 1)) return true;
            if(getNei(a, b, 3) && find(a , b - 1, loc + 1)) return true;
            if(getNei(a, b, 4) && find(a , b + 1, loc + 1)) return true;
        }
        visited[a][b] = false;
        return false;
    }
    
    bool hasPath(char* matrix, int rows, int cols, char* str){
        if(str[0] == '\0') return true;

        this->rows = rows;
        this->cols = cols;
        this->str = str;

        this->matrix = (char * *)malloc(sizeof(char *) * rows);
        this->visited = (bool * *)malloc(sizeof(bool *) * rows);
        for (int i = 0; i < rows; i++) {
            this->matrix[i] = (char *)malloc(sizeof(char) * cols);
            this->visited[i] = (bool * )malloc(sizeof(bool) * cols);

            for (int j = 0; j < cols; j++) {
                this->matrix[i][j] = matrix[i * cols + j];
                this->visited[i][j] = false;
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if(find(i, j, 0)) return true;
            }
        }

        return false;
    }
};

/**
ABC
ESF
CSA
DEE
*/

int main(){
    char  a[] = "ABCESFCSADEE";
    int c = 3;
    int d = 4;
    char e[] = "ABCCED";

    Solution s;
    cout << s.hasPath(a, c,d, e);

    return 0;
}
