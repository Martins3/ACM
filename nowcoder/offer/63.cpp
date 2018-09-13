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
 *
 * 列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
 * 好吧，就是暴力而已
 */
class Solution {
public:

    int K;
    bool ** visited;
    int rows;
    int cols;

    int counter;

    bool go(int a, int b){
        if(a < 0 || b < 0 || a >= rows || b >= cols)
            return false;

     if(visited[a][b]) return false;

        int res = 0;
        while(a){
            res += a % 10;
            a = a / 10;
        }

        while(b){
            res += b % 10;
            b = b / 10;
        }
        if(res > K) return false;
        return true;
    }

    void trans(int a, int b){
        if(!go(a, b)) return;
        visited[a][b] = true;
        counter ++;

        trans(a - 1, b);
        trans(a + 1, b);
        trans(a, b - 1);
        trans(a, b + 1);
    }

    int movingCount(int threshold, int rows, int cols){
        K = threshold;
        this->rows = rows;
        this->cols = cols;
        counter = false;

        visited = (bool **)malloc(sizeof(bool *) * rows);
        for (int i = 0; i < rows; i++) {
            visited[i] = (bool *) malloc(sizeof(bool) * cols);
            for (int j = 0; j < cols; j++) {
                visited[i][j] = false;
            }
        }
        trans(0, 0);
        return counter;
    }
};

int main(){
    
    return 0;
}
