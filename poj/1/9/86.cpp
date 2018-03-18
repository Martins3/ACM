//
// Created by martin on 17-12-19.
//
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Edge{
public:
    int node;
    int length;
    Edge(int node, int length):node(node), length(length){};
};

class Question{
public:
    int companion;
    int index;

    Question(int companion, int index):companion(companion), index(index){};
};

class DisjointSet{
public:
    const int size;
    int * arr; // for union
    int * rank;


    vector<int> ancestor;
    int * visited; // 标记是否被访问

    vector<vector<Edge> > tree; // make the tree
    vector<vector<Question> > query;

    int * res;
    int * distance;
    bool * dfsVisited;
    DisjointSet(int num): size(num + 1), tree(num + 1), query(num + 1){
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

        // 存储结果
        res = new int[40010];

        ancestor = vector<int>(size); // not need to init
        for (int k = 0; k < size; ++k) {
            ancestor[k] = k;
        }

        // init the tree
        for (int l = 1; l < size; ++l) {
            tree[l] = vector<Edge>();
        }

        for (int m = 1; m < size; ++m) {
            query[m] = vector<Question>();
        }

        // 新添加的表示到达的距离, 设置1的为0
        distance = new int[size];
        distance[1] = 0;

        // 添加visited 用于dfs的访问
        dfsVisited = new bool[size];
        for (int n = 0; n < size; ++n) {
            dfsVisited[n] = false;
        }
    }

    ~DisjointSet(){
        delete [] arr;
        delete [] rank;
        delete [] res;
        delete [] visited;
    }

    void tarjan(int s);

    int find(int x);

    void unite(int x, int y);

    void dfs(int x);

    void clear();

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

void DisjointSet::tarjan(int s) {
    dfsVisited[s] = true;
    for (int i = 0; i < tree[s].size(); ++i) {
        // 向下遍历
        if(!dfsVisited[tree[s][i].node]) {
            tarjan(tree[s][i].node);
            // 合并子节点到 s 上面
            unite(s, tree[s][i].node);

            // ancestor 的更新的关系是什么 ? ancestor 逐级提高
            ancestor[find(s)] = s;
        }
    }

    visited[s] = 1; // 只有访问结束的时候才会询问,

    // 询问含有关系的节点, 一对关系, 相互声明, 只会被访问一次
    // 添加的时候, 对于自己仅仅添加一次
    for (int j = 0; j < query[s].size(); ++j) {
        if(visited[query[s][j].companion]){
            // 到底查询谁父节点
            // 为什么添加visited: 没有visited没有办法得到正确的结果
            int father = ancestor[find(query[s][j].companion)];
            res[query[s][j].index] = distance[query[s][j].companion] + distance[s] - 2 * distance[father];
        }
    }

}

void DisjointSet::dfs(int x) {
    dfsVisited[x] = true;
    for (int i = 0; i < tree[x].size(); ++i) {
        if(!dfsVisited[tree[x][i].node]) {
            distance[tree[x][i].node] = distance[x] + tree[x][i].length;
            dfs(tree[x][i].node);
        }
    }
}

void DisjointSet::clear() {
    for (int n = 0; n < size; ++n) {
        dfsVisited[n] = false;
    }
}



int main(){
    freopen("input.txt", "r", stdin);
    int N, K;
    // make the tree
    scanf("%d %d", &N, &K);
    DisjointSet LCA(N);
    // build node
    for (int j = 0; j < K; ++j) {
        int x, y, length;
        char direction[10];
        scanf("%d%d%d%s", &x, &y, &length, direction);
        LCA.tree[x].push_back(Edge(y, length));
        LCA.tree[y].push_back(Edge(x, length));
    }

    int M;
    scanf("%d",&M);
    for (int k = 0; k < M; ++k) {
        int x;
        int y;
        scanf("%d%d", &x, &y);
        LCA.query[x].push_back(Question(y, k));
        if(x != y) LCA.query[y].push_back(Question(x, k));
    }

    // 从 1 的位置跑一个dfs, 跑的过程的记录所有到达所有的位置长度
    LCA.dfs(1);

    // 跑一个tarjan 也需要小心
    LCA.clear();

    // 跑一个LCA
    LCA.tarjan(1);

    // 打印结果
    for (int i = 0; i < M; ++i) {
        printf("%d\n", LCA.res[i]);
    }
    return 0;
};

