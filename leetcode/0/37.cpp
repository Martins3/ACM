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
#include <cassert>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

#define maxn 9



class Solution {
public:
    vector<pair<int, int>> f;

    vector<int> getPossible(int x, int y, vector<vector<char>>& board){
        bool not_ok[maxn];
        memset(not_ok, false, sizeof(not_ok));

        for(int i = 0; i < maxn; i++){
            if(board[x][i] != '.') not_ok[board[x][i] - '1'] = true;
        }

        for(int i = 0; i < maxn; i++){
            if(board[i][y] != '.') not_ok[board[i][y] - '1'] = true;
        }

        int m = x / 3; 
        int n = y / 3; 

        for(int i = m * 3; i < (m + 1) * 3; i++){
            for(int j = n * 3; j < (n + 1) * 3; j++){
                if(board[i][j] != '.') not_ok[board[i][j] - '1'] = true;
            }
        }

        vector<int> v;
        for(int i = 0; i < maxn; i++){
            if(!not_ok[i]) v.push_back(i);
        }

        return v;
    }

    bool find(int index, vector<vector<char>>& board){
        // cout << index << endl;
        // printf("%d\n", index);

        int x = f[index].first;
        int y = f[index].second;
        vector<int> p = getPossible(x, y, board);
        if(p.size() == 0) return false;

        for(int i: p){
            board[x][y] = i + '1';
            if(index == (f.size() - 1)) return true;

            if(find(index + 1, board)) return true;
            board[x][y] = '.';
        }
        return false; 
    }

     
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < maxn; i++){
            for(int j = 0; j < maxn; j++){
                if(board[i][j] == '.') f.push_back(make_pair(i, j));
            }
        }
        find(0, board);
    }
};

int main(){
    REOPEN_READ
    // REOPEN_WRITE
    string str = "[[.,.,9,7,4,8,.,.,.],[7,.,.,.,.,.,.,.,.],[.,2,.,1,.,9,.,.,.],[.,.,7,.,.,.,2,4,.],[.,6,4,.,1,.,5,9,.],[.,9,8,.,.,.,3,.,.],[.,.,.,8,.,3,.,2,.],[.,.,.,.,.,.,.,.,6],[.,.,.,2,7,5,9,.,.]]";
    int index = 0;
    vector<vector<char> > vec;
    for(int i = 0; i < maxn; i++){
        vector<char> v;
        for(int j = 0; j < maxn; j++){
            while(str[index] != '.' && !(isdigit(str[index]))){
                index ++;
            }
            v.push_back(str[index]);
            index ++; 
        }
        vec.push_back(v);
    }

    for(auto v: vec){
        for(char c: v){
            printf("%c ", c);
        }
        printf("\n");
    }

    Solution s;
    s.solveSudoku(vec);

    for(auto v: vec){
        for(char c: v){
            printf("%c ", c);
        }
        printf("\n");
    }

    return 0;
}