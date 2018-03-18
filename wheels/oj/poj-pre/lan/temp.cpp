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


queue<int> relax;
int vertexDis[30];
bool inQueue[Interval];


int EdgeCount;
int head[Interval + 2];
void addEdge(int x, int y, int w){
    graph[EdgeCount] = Edge(y, w, head[x]);
    head[x] = EdgeCount;
    EdgeCount ++;
}

int need[24];
int applicant[24];

void minPath() {
    // init the queue
    relax.push(0);
    vertexDis[0] = 0;
    inQueue[0] = true;

    for (int j = 0; j <= 24; ++j) {
        for (int i = head[j]; i != -1; i = graph[i].next) {
            printf("%d %d %d\n", j, graph[i].v, graph[i].w);
        }
    }

    // loop
    int lastVertex = -1;
    while (relax.size() != 0){
        int X = relax.front();
        relax.pop();
        inQueue[X] = false;
        for (int i = head[X]; i != -1; i = graph[i].next) {
            int Y = graph[i].v;
            if(Y == lastVertex) continue;
            int weight = graph[i].w;
            if(vertexDis[Y] < vertexDis[X] + weight){
                if(!inQueue[Y]) {
                    inQueue[Y] = true;
                    relax.push(Y);
                }
                vertexDis[Y] = vertexDis[X] + weight;
                printf("%d %d\n", X, Y);
            }
        }
        lastVertex = X;
    }
}



void makeGraph(int T) {

    for (int i = 7; i < 24; ++i) {
        addEdge(i - 7, i + 1, need[i]);
    }


    for (int i = 0; i < 7; ++i) {
        addEdge(i + 17, i + 1, need[i] - T);
    }


    for (int i = 0; i < 24; ++i) {
        addEdge(i + 1, i, -applicant[i]);
    }

    for (int i = 0; i < 24; ++i) {
        addEdge(i, i + 1, 0);
    }

    addEdge(0, 24, T);
    addEdge(24, 0, -T);
}

// 超额
int find(int T){
    for (int i = 0; i < 30; ++i) {
        vertexDis[i] = -100;
    }
    memset(inQueue, false, sizeof(inQueue));
    makeGraph(1);
    minPath();
    int dis = vertexDis[24];
    if(dis <= T) return 1;
    return 0;
}
int main(){
    freopen("input.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {

        memset(applicant, 0, sizeof(applicant));
        memset(need, 0, sizeof(applicant));
        memset(graph, 0, sizeof(graph));
        EdgeCount = 0;
        memset(head, -1, sizeof(head));
        for (int j = 0; j < 24; ++j)scanf("%d", &need[j]);
        int M;
        scanf("%d", &M);
        for (int k = 0; k < M; ++k) {
            int temp;
            scanf("%d", &temp);
            applicant[temp] ++;
        }

        if(!find(M)){
            printf("No Solution\n");
            continue;
        }

        int left = 1;
        int right = M;
        int middle = (left + right) / 2;
        while (left != right){
            if(find(middle)) {
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