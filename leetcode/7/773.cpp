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

class Stat{
    vector<int> A;
    Stat(vector<vector<int> > & v){
        A.push_back(v[0][0]);
        A.push_back(v[0][1]);
        A.push_back(v[0][2]);

        A.push_back(v[1][0]);
        A.push_back(v[1][1]);
        A.push_back(v[1][2]);
    }

    inline bool operator < (const Stat & s) const{
        for (int i = 0; i < 6; ++i) {
            if(A[i] != s.A[i])
                return A[i] < s.A[i];
        }
        return false;
    }

    bool operator == (const Stat & s) const {
        for (int i = 0; i < 6; ++i)
            if(A[i] != s.A[i]) return false;
        return true;
};



void neighbors(vector<Stat> & nei, const Stat & s){

}


// 太暴力了
class Solution {
public:

    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> start;
        start.push_back(vector<int>{1, 2, 3});
        start.push_back(vector<int>{4, 5, 0});
        Stat begin(start);

        Stat target(board);
        set<Stat> visited;
        queue<Stat> q;
        q.push(target);
        visited.insert(target);

        int res = 0;
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Stat p = q.front();


                auto f = visited.find(); q.pop();

                if(f == visited.end()){
                    if(q.front() ==  begin){
                        return res;
                    }
                }
            }
            res ++;
        }
        return -1;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    for (int i = 0; i < 6; ++i) {
        printf("if(A[%d] != s.A[%d]) return A[%d] < s.A[%d];\n", i, i, i, i);
    }
    return 0;
}
