/**
 * 由于所有的节点只有一个到达的位置,
 * 所有的人只有一条线连接的起来, 所以 开始节点 建立一棵树, 然后记录所有, 对于所有子树创建出来一个
 * 写的什么 J8 狗屎代码,
 *
 * 将 树 全部转化为普通 数组:
 *  1. 查询使用while 得到, 添加边的方法变化
 *  2.
 */



#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

#define MAXN 400010
int edgeHead[MAXN];
int edgeCount;
class Edge{
public:
    int x;
    int y;
    int length;
    int next;
    Edge(int x, int y,  int length, int next):x(x), y(y), length(length), next(next){};
    Edge(int x, int y,  int length):x(x), y(y), length(length){};
    Edge(){};
};
Edge undirectedGraph[MAXN];

void initGraph(){
    edgeCount = 0;
    memset(edgeHead, -1, sizeof(edgeHead));
}

void addEdge(int x, int y, int w){
    undirectedGraph[edgeCount] = Edge(x, y, w, edgeHead[x]);
    edgeHead[x] = edgeCount ++;
}


class Question{
public:
    int x;
    int y;
    int lca;
    int index;
    int next;
    Question(int x, int y, int lca, int index) : x(x), y(y), lca(lca), index(index) {}
    Question(){};
};

Question query[MAXN];
int queryCount;
int queryHead[MAXN];

void addQuery(int x, int y, int index){
    query[queryCount] = Question(x, y, 0, index);
    query[queryCount].next = queryHead[x];
    queryHead[x] = queryCount ++;
}

void initQuery(){
    queryCount = 0;
    memset(queryHead, -1, sizeof(queryHead));
}



int dfsNum;
int leftNum[MAXN]; // 记录进去的时候节点
int rightNum[MAXN];
int depth[MAXN];



void dfs(int x, int p){
    leftNum[x] = ++dfsNum;
    depth[x] = depth[p] + 1;


    for (int i = edgeHead[x]; i != -1; i = undirectedGraph[i].next) {
        if(undirectedGraph[i].y != p){
            dfs(undirectedGraph[i].y, x);
        }
    }
    rightNum[x] = dfsNum + 1; // 添加不受管辖的节点的dfsNum
}


class BinaryIndexTree{
private:
    vector<int> arr;
    int lowBit(int x){
        return (x) & (-x);
    }
public:
    vector<int> weight; // 方便查询第 i 个元素的数值
    int sum(int x){
        int ans = 0;
        while(x != 0){
            ans += arr[x];
            x -= lowBit(x);
        }
        return ans;
    }

    void add(int x, int v){
        for(int i = x ; i < arr.size(); i += lowBit(i)){
            arr[i] += v;
        }
    }

    BinaryIndexTree(int size): arr(size + 1), weight(size + 1){
        // 由于最后一个元素也是需要占用位置
        for (int i = 0; i < size + 1; ++i) {
            arr[i] = weight[i] = 0;
        }
    }
};



Question questions[MAXN];
Edge edges[MAXN];
int QNum;
int NNum;
class DisjointSet{
public:
    const int size;
    int * arr; // for union
    int * rank;
    BinaryIndexTree bit;

    int * ancestor;
    int * visited; // 标记是否被访问


    DisjointSet(): size(MAXN), bit(MAXN){

        arr = new int[size];
        for (int i = 0; i < size ; ++i) {
            arr[i] = 0;
        }
        rank = new int[size];
        for (int i = 0; i < size ; ++i) {
            rank[i] = 0;
        }

        visited = new int[size];
        for (int j = 0; j < size; ++j) {
            visited[j] = 0;
        }

        ancestor = new int[size]; // not need to init
        for (int k = 0; k < size; ++k) {
            ancestor[k] = k;
        }

    }

    ~DisjointSet(){
        delete [] arr;
        delete [] rank;
        delete [] visited;
    }

    void tarjan(int s);

    int find(int x);

    void unite(int x, int y);


    void solve();


};

int DisjointSet::find(int x) {
    if(arr[x] == 0) return x;
    arr[x] = find(arr[x]);
    return arr[x];
}

void DisjointSet::unite(int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);
    if(x_parent == y_parent) return;

    int x_rank = rank[x];
    int y_rank = rank[y];

    if(x_rank > y_rank){
        arr[y_parent] = x_parent;
    }else{
        if(x_rank == y_rank) rank[x] ++;
        arr[x_parent] = y_parent;
    }
}


/**
 * 计算出来所有节点的公共祖先
 */
void DisjointSet::tarjan(int s) {

    for (int i = edgeHead[s]; i != -1; i = undirectedGraph[i].next) {
        int y = undirectedGraph[i].y;
        if(depth[y] < depth[s]) continue;
        tarjan(y);
        unite(s, y);
        ancestor[find(s)] = s;
    }

    visited[s] = 1; // 只有访问结束的时候才会询问

    for (int j = queryHead[s]; j != -1; j = query[j].next) {
        if(visited[query[j].y]){
            int index = query[j].index;
            questions[index].lca = ancestor[find(query[j].y)];
        }
    }
}

void DisjointSet::solve() {


    // 知道所有查询LCA
    tarjan(1);

    // 对于所有边实现添加权重, 初始化Bit 数组
    // 原始边中间, 必定含有一个节点
    // 跳过第一个, 到底是dfs 的数值, 节点的标号 ?
    for (int k = 1; k <= NNum - 1; ++k) {
        int x = edges[k].x;
        int y = edges[k].y;
        int w = edges[k].length;
        x = depth[x] > depth[y] ? x: y; // 找到depth 较大的

        bit.add(leftNum[x], w - bit.weight[x]);
        bit.add(rightNum[x], bit.weight[x] - w);
        bit.weight[x] = w;

        // 打印消息
//        printf("添加 第%d条边 之后\n", k);
//        for (int i = 1; i <= size; ++i) {
//            printf("%d : %d\n", i, bit.sum(i));
//        }
//        printf("\n");
    }


    for (int j = 0; j < QNum; ++j) {
        Question q = questions[j];

        if(q.lca == -1){
            // 修改距离
            int k = q.x; // 对于I 进行查询
            int x = edges[k].x;
            int y = edges[k].y;
            int w = q.y; // 获取新的权重
            x = depth[x] > depth[y] ? x: y; // 找到子节点的位置

            bit.add(leftNum[x], w - bit.weight[x]);
            bit.add(rightNum[x], bit.weight[x] - w);
            bit.weight[x] = w;


        }

        else{
            // 查询距离,

            int distance = bit.sum(leftNum[q.x]) + bit.sum(leftNum[q.y]) - 2 * bit.sum(leftNum[q.lca]);
            printf("%d\n", distance);
        }
    }
}


// 转化为数组

// 使用前向存储所有query 和 graph



/**
 * 共有 N 个节点,
 */
int main(){
    freopen("input.txt", "r", stdin);
    int N, Q , S;
    while (~scanf("%d %d %d", &N, &Q, &S)){

        // make the graph
        // 1 就是根节点
        dfsNum = 0;
        QNum = Q;
        NNum = N;


        initGraph();
        for (int i = 0; i < N - 1; ++i) {
            int X, Y, W;
            scanf("%d%d%d", &X, &Y, &W);
            addEdge(X, Y, W);
            addEdge(Y, X, W);
            edges[i + 1] = Edge(X, Y, W);
        }


        dfs(1, 0);



        // document all the query and distance change !
        initQuery();
        int currentPos = S;
        for (int j = 0; j < Q; ++j) {
            int type;
            scanf("%d", &type);
            if(type) {
                int I, W;
                scanf("%d%d", &I, &W); // 对于边添加, 设置lca 为 -1
                questions[j] = Question(I, W, -1, j);
            }else{
                int Des;
                scanf("%d", &Des);
                questions[j] = Question(currentPos, Des, 0, j);


                addQuery(currentPos, Des, j);
                addQuery(Des, currentPos, j);
                currentPos = Des;
            }
        }


        // calculate all the lca for Questions
        DisjointSet LCA;
        LCA.solve();
    }
    return 0;
}
