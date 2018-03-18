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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);
/**
 * 1. 数目关系 x - o =  1  : 0
 * 2. 如果 x 胜利， 那么 1 
 * 3. o w => 0
 */
class Solution {
public:
    int check_num(vector<string>& board){
        int X = 0;
        int O = 0;
        for(auto line : board){
            for(char c : line){
                if(c == 'X') X ++;
                if(c == 'O') O ++;
            }
        } 
        if(X - O == 0) return 0;
        if(X - O == 1) return 1;
        return -1;
    }

    int check_win(vector<string>& board, char who){
        int way = 0;
        // 行
        for(int i = 0; i < 3; i++){
            if(board[i][0] == who &&  board[i][1] == who &&  board[i][2] == who){
                way ++;
            }    
        }

        // 列
        for(int i = 0; i < 3; i++){
            if(board[0][i] == who &&  board[1][i] == who &&  board[2][i] == who){
                way ++;
            }    
        }

        // 左
        if(board[0][0] == who &&  board[1][1] == who &&  board[2][2] == who){
            way ++;
        }    
        
        // 右
        if(board[0][2] == who &&  board[1][1] == who &&  board[2][0] == who){
            way ++;
        }    
        return way;
    }

    bool validTicTacToe(vector<string>& board) {
        int num = check_num(board);
        if(num == -1) return false;
        int xw = check_win(board, 'X');
        int ow = check_win(board, 'O');
        if(xw > 1 || ow > 1) return false;


        if(xw == 1){
            if(num == 0) return false;
        }

        if(ow == 1){
            if(num == 1) return false;
        } 
        return true;
    }
};


int main(){
    Solution s;
    vector<string> board;
    board.push_back("X  ");
    board.push_back("   ");
    board.push_back("   ");

    cout << s.validTicTacToe(board);

    return 0;
}