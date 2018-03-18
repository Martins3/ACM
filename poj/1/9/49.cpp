#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;
#define VSCODE_READ freopen("../../../input.txt", "r", stdin);
#define C_READ freopen("input.txt", "r", stdin);


#define MAX_INPUT 10010
class Edge{
public:
    int y;
    int head;
    Edge(int y, int head):y(y), head(head){};
    Edge(){};
};

int edgeCount;
Edge graph[MAX_INPUT * 100];
int head[MAX_INPUT];
void addEdge(int x, int y){
    graph[edgeCount] = Edge(y, head[x]);
    head[x] = edgeCount;
    edgeCount ++;
}
void initGraph(){
    memset(head, -1, sizeof(head));
}

/**
 * 1. 如何保存图
 * 2. 如何动态规划: 
 *      1. 开始保存所有节点的数值为 -1
 *      2. 保存所有节点需要完成的时间
 * 3. 对于所有节点进行一次访问
 */
int res[MAX_INPUT];
int needTime[MAX_INPUT];

int dp(int i){
    if(res[i] > 0) return res[i];

    int maxRely = 0;
    for(int j = head[i]; j != -1; j = graph[j].head){
        maxRely = max(maxRely, dp(graph[j].y));
    }
    res[i] = needTime[i] + maxRely;
    return res[i];
}


int main(){
    C_READ
    
    int choresNum;
    scanf("%d", &choresNum);

    initGraph();

    for(int i = 1; i <= choresNum; i++){
        int nt;
        int requestNum;
        scanf("%d %d", &nt, &requestNum);
        needTime[i] = nt;

        for(int j = 0; j < requestNum; j++){
            int requestID;
            scanf("%d", &requestID);
            addEdge(i, requestID);
        }   
    }

    memset(res, -1, sizeof(res));
    for(int i = 1; i <= choresNum; i++){
        dp(i);
    }
    
    printf("%d", *max_element(res, res + MAX_INPUT));

    return 0;
};

