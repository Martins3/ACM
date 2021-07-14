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


class Solution {
public:

    int width;
    int height;

    bool valid(int x, int y){
        if(x < 0 || y < 0 || x >= width || y >= height) return false;
        return true;
    }



    // 没有环路， 所以
    bool dfs(const vector<vector<int> > & dungeon, int sx, int sy, long long int life){
        life = life + dungeon[sx][sy];
        if(life <= 0 ) return false;

        if(sx == width - 1 && sy == height - 1) return true;
        int x = sx + 1;
        int y = sy;

        if(valid(x, y) && dfs(dungeon,  x, y, life)) return true;

        x = sx;
        y = sy + 1;
        if(valid(x, y) && dfs(dungeon,  x, y, life)) return true;

        return false;
    }

    bool dfs(const vector<vector<int> > & dungeon,  long long int life){
        return dfs(dungeon, 0, 0, life);
    }

    int my_lower_bound(const vector<vector<int> > & dungeon){
        long long int l = 1;
        long long int r = 1;
        for(const vector<int> & vec : dungeon){
            for(int a : vec){
                if(a < 0)
                    r -= a;
            }
        }
        while(l < r){
            long long int m = (r - l) / 2 + l;
            if(dfs(dungeon, m)){
                r  = m;
            }else{
                l = m + 1;
            }
        }
        return l;
    }

    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        width = dungeon.size();
        height = dungeon[0].size();
        return my_lower_bound(dungeon);
    }
};
int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    vector<vector<int> > v;
    v.push_back(vector<int>{0, -3});
    cout << s.calculateMinimumHP(v);
    return 0;
}
