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
/**
 * 将数值从高到低排序，对于问题也是从高到 
 */

#define LEN 1010
int depth;
int width;

class Node{
public:
    int x;
    int y;
    int val;

    Node() = default;
    bool operator < (const Node & n) const{
        return val > n.val;
    }

    Node(int x, int y, int val): x(x), y(y), val(val){};
};

Node lands[LEN * LEN];

void readMaze(){
    for(int i = 0; i < depth; i++){
        for(int j = 0; j < width; j++){
            int val;
            scanf("%d", &val);
            lands[i * width + j] = Node(i, j, val);
        }
    }    
    sort(lands, lands + width * depth);
}

bool isOut(int x, int y){
    return x < 0 || y < 0 || x >= depth || y >= width;
}



const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};


int father[LEN * LEN];
int find(int x){
    if(father[x] == -1) return x;
    father[x] = find(father[x]);
    return father[x];
}

int union_node(int x, int y){
    int px = find(x);
    int py = find(y);
    if(px == py) return 0;
    father[py] = px;
    return 1;
}

bool island[LEN][LEN];
#define Query_LEN (100000 + 10)
int query[Query_LEN];
int ans[Query_LEN];

int test_case;
int main(){
    REOPEN_READ
    REOPEN_WRITE
    scanf("%d", &test_case);
    while(test_case --){
        scanf("%d %d", &depth, &width);
        readMaze();
        memset(island, false, sizeof(island)); // 开始的时候设置位置都是
        memset(father, -1, sizeof(father));


        int T;
        scanf("%d", &T);
        for(int i = T - 1; i >= 0; i--) scanf("%d", &query[i]);
            
        int p = 0;
        int cnt = 0; // 当前查询的控制的节点的数目, 增加的岛屿数目 减去 连接的数目
        for(int i = 0; i < T; i++){
            while(p < width * depth && lands[p].val > query[i]){
                int x = lands[p].x;
                int y = lands[p].y;
                island[x][y] = true;
                for(int i = 0; i < 4; i++){
                    if(isOut(x + dx[i], y + dy[i])) continue;
                    if(!island[x + dx[i]][y + dy[i]]) continue;
                    int m = width * (x + dx[i]) + (y + dy[i]);
                    int n = width * x + y;
                    cnt += union_node(m, n);
                } 
                p ++;
            }
            ans[i] = p - cnt;
        }
        
        // 打印出来的结果来
        for(int i = T - 1; i >= 0; i --){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}