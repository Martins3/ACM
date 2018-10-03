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
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

# define  LEN 30


int depth;
int width;
int Sx, Sy;
int Tx, Ty;


bool maze[LEN][LEN];

void readMaze(){
    memset(maze, true, sizeof(maze));
    for(int i = 0; i < depth; i++){
        for(int j = 0; j < width; j++){
            char c = '\n';
            while(c == '\n'){
                c = getchar();
            }
            if(c == '#') maze[i][j] = false;

            if(c == 'S') {
                Sx = i;
                Sy = j;
            }
            if(c == 'T') {
                Tx = i;
                Ty = j;
            }
        }
    }    
}

bool isOut(int x, int y){
    if(x < 0 || y < 0 || x >= depth || y >= width || !maze[x][y]){
        return true;
    }    
    return false;
}


class Clone{
public:
    int x;
    int y;
    int color; // 0 1 2 3 4
    int direction; // 0 1 2 3  0 up 3 down || 1 left 2 right
    Clone(int x, int y, int color, int direction):
    x(x), y(y), color(color), direction(direction){};
};

bool vis[LEN][LEN][5][4];


int case_num;
void solve(){
    memset(vis, false, sizeof(vis[0][0][0][0]) * LEN * LEN * 5 * 4);
    queue<Clone> Q;
    Clone c(Sx, Sy, 0, 0);
    vis[Sx][Sy][0][0] = true;
    Q.push(c);

    int epoch = 0;
    bool ok = false;
    while(!Q.empty()){
        epoch ++;
        // printf("this is the %d epoch\n", epoch);
        int size = Q.size();
        for(int kk = 0; kk < size; kk++){
            Clone  t = Q.front();
            Q.pop();
            

            int x = t.x;
            int y = t.y; 
            int color = t.color;
            int dirc = t.direction;

            if(x == Tx && y == Ty && color == 0){
                ok = true;
                break;
            }
        
            // turn direction
            int l_dirc;
            int r_dirc;
            if(dirc == 0 || dirc == 3){
                l_dirc = 1;
                r_dirc = 2;
            }else{
                l_dirc = 0;
                r_dirc = 3;
            }

            // 原地转动方向的
            if(!vis[x][y][color][l_dirc]) {
                Q.push(Clone(x, y, color, l_dirc));
                vis[x][y][color][l_dirc] = true;
            }
            if(!vis[x][y][color][r_dirc]) {
                Q.push(Clone(x, y, color, r_dirc));
                vis[x][y][color][r_dirc] = true;
            }

            // 向前移动
            int fx = x , fy = y ;
            if(dirc == 0) fx = x - 1;
            if(dirc == 3) fx = x + 1;
            if(dirc == 1) fy = y - 1;
            if(dirc == 2) fy = y + 1;
            if(isOut(fx, fy)) continue;

            if(!vis[fx][fy][(color + 1) % 5][dirc]){
                Q.push(Clone(fx, fy, (color + 1) % 5, dirc));
                vis[fx][fy][(color + 1) % 5][dirc] = true;
            }

            
        }
        if(ok) break;
    }
    
    printf("Case #%d\n", ++case_num);
    if(ok)
        printf("minimum time = %d sec\n", --epoch);
    else
        printf("%s\n", "destination not reachable");
}


int main(){
    REOPEN_READ
    REOPEN_WRITE
    while(true){
        scanf("%d %d", &depth, &width);
        if(depth == 0 || width == 0) break;
        if(case_num) printf("\n");
        readMaze();
        solve();
    }   
    return 0;
}