//
// Created by martin on 17-12-13.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class DisjointSet{
public:
    const int size;
    int * arr; // for union
    int * rank;


    int * ancestor;
    int * visited; // 标记是否被访问

    vector<vector<int> > tree; // make the tree
    vector<vector<int> > query;

    int * res;

    DisjointSet(int num):size(num + 1), tree(num + 1), query(num + 1){
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

        res = new int[size];
        for (int k = 0; k < size; ++k) {
            res[k] = 0;
        }

        ancestor = new int[size]; // not need to init

        // init the tree
        for (int l = 1; l < size; ++l) {
           tree[l] = vector<int>();
        }

        for (int m = 1; m < size; ++m) {
            query[m] = vector<int>();
        }
    }

    ~DisjointSet(){
        delete [] arr;
        delete [] rank;
        delete [] ancestor;
        delete [] res;
        delete [] visited;
    }

    void tarjan(int s);

    int find(int x);

    void unite(int x, int y);

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
 * unite 的操作是什么:
 * 当子节点访问结束之后, 和子节点的合并
 * size 超过 1的最多只有两个集合
 *
 * (x, x) 需不需要特殊的处理 !
 *
 *
 *
 * @param s tree's root
 */
void DisjointSet::tarjan(int s) {

    for (int i = 0; i < tree[s].size(); ++i) {
        // 向下遍历
        tarjan(tree[s][i]);
        // 合并子节点到 s 上面
        unite(s, tree[s][i]);

        // ancestor 的更新的关系是什么 ? ancestor 逐级提高
        ancestor[find(s)] = s;
    }

    visited[s] = 1; // 只有访问结束的时候才会询问,

    // 询问含有关系的节点, 一对关系, 相互声明, 只会被访问一次
    // 添加的时候, 对于自己仅仅添加一次
    for (int j = 0; j < query[s].size(); ++j) {
       if(visited[query[s][j]]){
           // 到底查询谁父节点
           // 为什么添加visited: 没有visited没有办法得到正确的结果
           res[ancestor[find(query[s][j])]]++;
       }
    }

}


int main(){
    freopen("input.txt", "r", stdin);
    int N;
    // make the tree
    while (~scanf("%d", &N)){
        DisjointSet LCA(N);
        // build  node
        for (int j = 0; j < N; ++j) {
            int node;
            int num;
            scanf("%d", &node);
            while (getchar() != '(');
            scanf("%d", &num);
            while (getchar() != ')');
            for (int i = 0; i < num; ++i) {
                int child;
                scanf("%d", &child);
                    LCA.tree[node].push_back(child);
            }
        }

        int M;
        scanf("%d",&M);
        for (int k = 0; k < M; ++k) {
            int x;
            int y;
            while (getchar() != '(');
            scanf("%d%d", &x, &y);
            while (getchar() != ')');
            LCA.query[x].push_back(y);
            if(x != y) LCA.query[y].push_back(x);
        }

        // find the root
        int root;
        bool findRoot[900 + 1];
        for (int m = 1; m <= N ; ++m) findRoot[m] = true;
        for (int n = 1; n <= N; ++n){
            for (int i = 0; i < LCA.tree[n].size(); ++i) {
                findRoot[LCA.tree[n][i]] = false;
            }
        }
        for (int m = 1; m <= N ; ++m){
            if(findRoot[m]) root = m;
        }

        LCA.tarjan(root);
        // print the res

        for (int l = 1; l <= N; ++l) {
            if(LCA.res[l] > 0) printf("%d:%d\n",l, LCA.res[l]);
        }
    }
    return 0;
};
