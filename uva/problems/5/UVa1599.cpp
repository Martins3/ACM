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

# define VERTEX_NUM (100000 + 100)
# define EDGE_NUM (400000 + 1000)

class Edge{
   public:
       int x;
       int y;
       int head;
       int weight;
       Edge(){};
       Edge(int x, int y, int head, int weight):x(x), y(y), head(head), weight(weight){}

   };
int nodeHead[VERTEX_NUM];
int nodePointer;
Edge graph[EDGE_NUM];

void addWeightedEdge(int x, int y, int weight){
       graph[nodePointer] = Edge(x, y, nodeHead[x], weight);
       nodeHead[x] = nodePointer;
       nodePointer ++;
   }



int N, M;
int bfs_num[VERTEX_NUM];
int vis_num;
void read_graph();

void bfs(){
    queue<int> q;

    // make the first one
    // 需要保证出来的必定合法
    q.push(N);
    vis_num = N;
    bfs_num[N] = N;

    while(!q.empty()){
        int size = q.size();
        vis_num --;

        for(int i = 0; i < size; i++){
            int x = q.front();
            q.pop();

            for(int j = nodeHead[x]; j != -1; j = graph[j].head){
                int y = graph[j].y;
                if(bfs_num[y]) continue;
                bfs_num[y] = vis_num; 
                q.push(y);
            }  
        }
    }
}

void find_min(){
    queue<int> route;
    
}

/**
 * 使用记录 访问节点的时候保证数值对应才可以, 使用反向dfs, 然后正向的时候总是查询的编号
 * d - 1， 从而实现对于
 * 
 * 处理多个都是最近，而且颜色权重相同的时候， 如果处理， 那么需要记录最小的边实现处理对应节点
 * 
 */
void initGraph() {
    memset(nodeHead, -1, sizeof(nodeHead));
    nodePointer = 0;
    memset(bfs_num, 0, sizeof(bfs_num));
    vis_num = 1;
}
int main(){
    return 0;
}