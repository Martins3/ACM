/**
 * find
 *
 * 1. there must be a judge
 * 2. for pair, if no judge, there should be only one outcome !
 *
 * which line or inconsistent :
 *
 *
 * rank: -1 1 0
 *
 * 使用数组记录胜负关系, 使用 disjointSet记录组的
 * make the three, just like the animal chain, but the algorithm is hard to understand
 *
 * 只有去除 a 没有矛盾, 那么说明 a 为judge
 *
 * 去除任何都是矛盾, 无法判断的
 *
 * 无论去除谁, 都是冲突, 说明含有多个judge情况.
 *
 *
 *
 * if 1< 2 3 < 2, then 1 3 will be the same group, how to handle it !
 *
 *
 */

#include <iostream>
#include <fstream>
using namespace std;


class DisjointSet{
public:
    const int size;
    const int N;
    int * arr; // for union
    int * rank;
    DisjointSet(int num):size(3 * num + 1), N(num){
        arr = new int[size];
        for (int i = 0; i < size ; ++i) {
            arr[i] = -1;
        }
        rank = new int[size];
        for (int i = 0; i < size ; ++i) {
            rank[i] = 0;
        }
    }

    ~DisjointSet(){
        delete [] arr;
        delete [] rank;
    }

private:
    int find(int x);

    void unite(int x, int y);

    bool isSame(int x, int y);

public:
    void lessUnite(int x, int y);
    void equalUnite(int x, int y);
    void moreUnite(int x, int y);


    bool isLess(int x, int y);
    bool isMore(int x, int y);
    bool isEqual(int x, int y);
};

int DisjointSet::find(int x) {
    if(arr[x] == -1) return x;
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

void DisjointSet::lessUnite(int x, int y) {
    unite(x, y + N);
    unite(x + N, y + 2 * N);
    unite(x + 2 * N, y);
}

void DisjointSet::equalUnite(int x, int y) {
    unite(x, y);
    unite(x + N, y + N);
    unite(x + 2 * N, y + 2 * N);
}

void DisjointSet::moreUnite(int x, int y) {
    unite(x, y + 2 * N);
    unite(x + N, y);
    unite(x + 2 * N, y + N);
}

bool DisjointSet::isLess(int x, int y) {
    return isSame(x, y + N);
}

bool DisjointSet::isMore(int x, int y) {
    return isSame(x, y + 2 * N);
}

bool DisjointSet::isEqual(int x, int y) {
    return isSame(x, y);
}

bool DisjointSet::isSame(int x, int y) {
    return find(x) == find(y);
}

class Process{
public:
    int childOne;
    char res;
    int childTwo;
};

int main(){
    freopen("input.txt", "r", stdin);
    int N, M;
    while (~scanf("%d%d", &N, &M)){


        // 缓存输入
        Process * data = new Process[M];
        for (int i = 0; i < M; ++i) {
            scanf("%d%c%d", &data[i].childOne, &data[i].res, &data[i].childTwo);
        }

        // we expect every children as the judge
        int save = 0; // find the judge when save is exactly one
        int line = -1; // which line we find the ans,
        int whichChild = 0;

        for (int j = 0; j < N; ++j) {
            // a new analyze need a new Disjoint Set to handle it
            DisjointSet set(N);

            bool conflict = false;
            for (int i = 0; i < M; ++i) {
               // for the judge, we escape it !
                int x = data[i].childOne;
                int y = data[i].childTwo;
                if(x == j || y == j) continue;

                // A
                if(data[i].res == '<'){
                    if(set.isEqual(x, y) || set.isMore(x, y)){
                        conflict = true;
                        line = max(line, i);
                        break;
                    }
                    set.lessUnite(x, y);
                }

                // B
                if(data[i].res == '>'){
                    if(set.isEqual(x, y) || set.isLess(x, y)){
                        conflict = true;
                        line = max(line, i);
                        break;
                    }
                    set.moreUnite(x, y);
                }


                // C
                if(data[i].res == '='){
                    if(set.isLess(x, y) || set.isMore(x, y)){
                        conflict = true;
                        line = max(line, i);
                        break;
                    }
                    set.equalUnite(x, y);
                }
            }

            if(!conflict){
                save ++;
                whichChild = j;
            }
        }

        if(save == 1) {
            printf("Player %d can be determined to be the judge after %d lines\n", whichChild, line + 1);
        }else if(save > 1) {
            printf("Can not determine\n");
        }else {
            printf("Impossible\n");
        }
        delete [] data;
    }

}
