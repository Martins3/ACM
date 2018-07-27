//
// Created by martin on 17-11-24.
//

#include <iostream>
#include <fstream>


/**
 * 所有的动物 含有三个元素 描述元素 X 属于哪一个种类
 * 元素表示同时发生 或者不同时发生
 *
 * 简化原则: 合并的时候信息同步跟新, 所以检查的时候, 只是需要一次的分析
 */
using namespace std;

class DisjointSet{
public:
    const int size;
    int * arr; // for union
    int * rank;
    DisjointSet(int num):size(num + 1){
        arr = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = 0;
        }

        for (int j = 0; j < size; ++j) {
            rank[j] = 0;
        }
    }

    ~DisjointSet(){
        delete [] arr;
        delete [] rank;
    }


    int find(int x);

    void unite(int x, int y);

    bool isSame(int x, int y);
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

bool DisjointSet::isSame(int x, int y) {
    return find(x) == find(y);
}

int main(){

    freopen("input.txt", "r", stdin);
    int N, K;
    scanf("%d%d", &N, &K);
        DisjointSet animals(N * 3);
        int res = 0;
        for (int i = 0; i < K; ++i) {
            int type, x, y;
            scanf("%d%d%d", &type, &x, &y);
            if (x > N || y > N || x < 1 || y < 1) {
                res++;
                continue;
            }
            // 相同
            int xa = x;
            int xb = x + N;
            int xc = x + 2 * N;
            int ya = y;
            int yb = y + N;
            int yc = y + 2 * N;
            if (type == 1) {
                if (animals.isSame(xa, yb) || animals.isSame(xa, yc)) {
                    res++;
                } else {
                    animals.unite(xa, ya);
                    animals.unite(xb, yb);
                    animals.unite(xc, yc);
                }
            } else {
                if (animals.isSame(xa, ya) || animals.isSame(xa, yc)) {
                    res++;
                } else {
                    animals.unite(xa, yb);
                    animals.unite(xb, yc);
                    animals.unite(xc, ya);
                }
            }

        }
        printf("%d", res);
    return 0;
}

