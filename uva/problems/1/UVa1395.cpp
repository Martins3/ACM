#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <forward_list>
#include <deque>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("../output.txt", "w", stdout);

/**
 *  只有对于edge 实现排序， 如果得到的结果是正确的结果，那么必定
 *  所有的取值必定在一个取值的区间中间，暴力， 计算， 中间cut branch
 * 
 *  wrong ans: 为什么，
 */

class Edge{
public:
    int x;
    int y;
    int weight;

    Edge() = default;
    Edge(int x, int y, int weight): x(x), y(y), weight(weight){};
    bool operator < (const Edge & e){
        return (weight < e.weight);
    }
};


int father[1000];
Edge edges[10000];



int find(int x){
    if(father[x] == -1) return x;
    father[x] = find(father[x]);
    return father[x];
}

int union_node(int x, int y){
    int px = find(x);
    int py = find(y);
    if(px == py) return 0;

    father[px] = py;
    return 1;
}

int v_num;
int e_num;

int x, y, weight;
int main(){
    REOPEN_READ
    REOPEN_WRITE
    while(true){

        scanf("%d %d", &v_num, &e_num);
        if(v_num == 0 && e_num == 0) break;
        
        for(int i = 0; i < e_num; i++){
            scanf("%d %d %d", &x, &y, &weight);
            edges[i] = Edge(x, y, weight);
        }

        sort(edges, edges + e_num);
        int min_v = INT_MAX;

        for(int l = 0; l < e_num; l++){
            memset(father, -1, sizeof(father));
            int gg = v_num - 1;

            for(int i = l; i < e_num; i++){
                gg -= union_node(edges[i].x , edges[i].y);
                if(edges[i].weight - edges[l].weight >= min_v) break; // 没有查看的价值
                if(!gg) min_v = min(min_v, edges[i].weight - edges[l].weight);
            }
        }

        if(min_v == INT_MAX) 
            printf("%d\n", -1);
        else
            printf("%d\n", min_v);
    }    
    return 0;
}