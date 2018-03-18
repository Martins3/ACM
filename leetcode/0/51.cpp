#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <forward_list>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

#define maxn 100

class Solution {
public:
    int vis[maxn][maxn]; //  1 left 2 right 3 down
    bool board[maxn][maxn];

    vector<vector<string> > res;
    int n;

    void setZero(int row, int col){
        memset(vis[row + 1], 0, sizeof(vis[row + 1]));
        board[row][col] = false;
        vis[row][col] = 0;
    }

    
    void makeVis(int x, int y){
        for(int i = 0; i < n; i++){
            int m = vis[x][i];
            if(m & 1 && i - 1 >= 0){
                vis[x + 1][i - 1] |= 1;
            }

            if(m & 2){
                vis[x + 1][i] |= 2;
            }

            if(m & 4 && i + 1 < n){
                vis[x + 1][i + 1] |= 4;
            }
        }
    }

    void makeBoard(){
        vector<string> v;
        for(int i = 0; i < n; i++){
            string s(n , '.');
            for(int j = 0; j < n; j++){
                if(board[i][j]) s[j] = 'Q';
            }
            v.push_back(s);
        }
        res.push_back(v);
    }
    
    void dfs(int x, int y){
        if(vis[x][y]) return;

        if(x == n - 1){
            // make a board
            board[x][y] = true;
            makeBoard();
            setZero(x, y);
            return;
        }

        // 为下一行的处理
        board[x][y] = true;
        vis[x][y] = 7;
        makeVis(x, y); 
        

        for(int i = 0; i < n; i++){
            dfs(x + 1, i);
        }
        
        // clear
        setZero(x, y);
    }

    
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;

        memset(vis, 0, sizeof(vis[0][0]) * maxn * maxn);
        memset(board, 0, sizeof(board[0][0]) * maxn * maxn);
        for(int i = 0; i < n; i++){
            dfs(0, i);
        }
        return this->res;
    }
};
int main(){
    REOPEN_READ
    // REOPEN_WRITE
    Solution s;
    vector<vector<string> >  a = s.solveNQueens(4); 
    for(int i = 0; i < a.size(); i++){
        for(int j= 0; j < a[i].size(); j++){
            cout << a[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}
/**
 * 在函数 makeVis 中间， 没有处理 当前节点的 true 标记
 * 
 * 对于算法理解出现错误， vi 制作下一行的方法错误 
 * 
 * hang 应该是 col
 * 
 * 再次发现理解错误 vis 数组
 */