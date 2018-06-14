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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/OnlineJudge/output.txt", "w", stdout);

class PointX{
public:
    int dis;
    int x;
    int y;
    PointX(int dis, int x, int y): dis(dis), x(x), y(y){}
    PointX(int x, int y): x(x), y(y){}
};

struct CompareX{
    inline bool operator()(const PointX & a, const PointX & b) const{
        return (a.dis > b.dis);
    }
};

class Solution {
public:

    int width;
    int height;

    bool valid(int x, int y){
        if(x >= width) return false;
        if(x < 0) return false;
        if(y >= height) return false;
        if(y < 0) return false;
        return true;
    }

    int minPathSum(vector<vector<int> >& grid) {
        this->width = grid.size();
        if(!this->width) return 0;
        this->height = grid[0].size();
        if(!this->height) return 0;

        std::priority_queue<PointX, std::vector<PointX>, CompareX> heap;
        vector<vector<bool> > visited(width, vector<bool>(height, false));
        vector<vector<int> > dis(width, vector<int>(height, 0x3f3f3f3f));

        vector<pair<int, int> > bia;
        bia.push_back(make_pair<int, int>(1, 0));
        bia.push_back(make_pair<int, int>(0, 1));

        // push 和 dis
        heap.push(PointX(grid[0][0], 0, 0));
        dis[0][0] = grid[0][0];


        while(!heap.empty()){
            const PointX p =  heap.top();
            // 确定自己的数值
            visited[p.x][p.y] = true;
            if(p.x == width -1  &&  p.y == height - 1) break;
            // 刷新周围的数值, 当可以刷新的时候添加
            int x;
            int y;
            for(auto v : bia){
                x = p.x + v.first;
                y = p.y + v.second;
                if(valid(x, y) && !visited[x][y]){
                    if(dis[x][y] > p.dis + grid[x][y]){
                        dis[x][y] = grid[x][y] + p.dis;
                        heap.push(PointX(dis[x][y], x, y));
                    }
                }
            }
            heap.pop();
        }
        return dis[width - 1][height - 1];
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    vector<vector<int> > v;
    v.push_back(vector<int>{1, 3, 1});
    v.push_back(vector<int>{1, 5, 1});
    v.push_back(vector<int>{4, 2, 1});
    cout << s.minPathSum(v);

    return 0;
}
