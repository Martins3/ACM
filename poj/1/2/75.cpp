
// 放弃清真的开端

// 没有理解的是: 为什么可以使用循环判断为 24

// 千万注意初始化的位置
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>

using namespace std;
#define Interval 5000

struct Edge{
    int v, w, next;
    Edge(){};
    Edge(int v, int w, int next):v(v), w(w), next(next){}
};

Edge graph[Interval];


int vertexDis[30];
bool inQueue[30];
int cnt[30];


int EdgeCount;
int head[Interval + 2];
void addEdge(int x, int y, int w){
    graph[EdgeCount] = Edge(y, w, head[x]);
    head[x] = EdgeCount;
    EdgeCount ++;
}

int need[30];
int applicant[30];

bool minPath() {
    queue<int> relax;
    relax.push(0);
    vertexDis[0] = 0;
    inQueue[0] = true;
    cnt[0] = 1;


    // loop
    while (!relax.empty()){
        int X = relax.front();
        relax.pop();
        inQueue[X] = false;
        for (int i = head[X]; i != -1; i = graph[i].next) {
            int Y = graph[i].v;
            int weight = graph[i].w;
            if(vertexDis[Y] < vertexDis[X] + weight){
                if(!inQueue[Y]) {
                    inQueue[Y] = true;
                    relax.push(Y);
                    cnt[Y] ++;

                    // 会出现永远都是没有办法满足的时候
                    if(cnt[Y] > 24){
                        return false;
                    }
                }
                vertexDis[Y] = vertexDis[X] + weight;
            }
        }
    }
    return true;
}



void makeGraph(int T) {
    memset(head, -1, sizeof(head));
    EdgeCount = 0;

    for (int i = 9; i <= 24; ++i) {
        addEdge(i - 8, i, need[i]);
    }


    for (int i = 1; i <= 8; ++i) {
        addEdge(i + 16, i, need[i] - T);
    }


    for(int i = 1; i <= 24; i++) {
        addEdge(i-1, i, 0);
        addEdge(i, i-1, -applicant[i]);
    }

    addEdge(0, 24, T);
}

// 超额
int find(int T){
    for (int i = 0; i < 30; ++i) {
        vertexDis[i] = -999990000;
    }

    for (int j = 0; j < 30; ++j) {
        inQueue[j] = false;
    }

    for (int j = 0; j < 30; ++j) {
        cnt[j] = 0;
    }


    makeGraph(T);
    if(!minPath()) {
        return 0;
    }
    if(vertexDis[24] == T) {
        return 1;
    }
    return 0;
}
int main(){
    freopen("input.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {

        memset(applicant, 0, sizeof(applicant));
        memset(need, 0, sizeof(need));
        for (int j = 1; j <= 24; ++j)scanf("%d", &need[j]);
        int M;
        scanf("%d", &M);
        for (int k = 0; k < M; ++k) {
            int temp;
            scanf("%d", &temp);
            applicant[temp + 1] ++;
        }

        if(!find(M)){
            printf("No Solution\n");
            continue;
        }


        int left = 1;
        int right = M;
        int middle = (left + right) / 2;
        while (left != right){
            if(find(middle)){
                right = middle;
                middle = (left + right) / 2;
            }else{
                left = middle + 1;
                middle = (left + right) / 2;
            }
        }
        printf("%d\n", middle);

    }
    return 0;
}
