
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Node{
public:
    int sum;
    int start;
    int end;
    Node():sum(0),start(0), end(0){}
};


class SegmentTree{
public:
    vector<Node> Tree;
    int count;
    void update(int left, int right, int& x, int y, int pos);
    int query(int left, int right, int x, int y, int k);
    SegmentTree(int N):Tree(40 * N), count(0){}
};

void SegmentTree::update(int left, int right, int & x, int y, int pos) {
    Tree[++count] = Tree[y], Tree[count].sum ++, x = count;

    if(left == right) return;
    int mid = (left + right) / 2;
    if(mid >= pos) update(left, mid, Tree[x].start, Tree[y].start, pos);
    else update(mid + 1, right, Tree[x].end, Tree[y].end, pos);
}

int SegmentTree::query(int left, int right, int x, int y, int k) {

    if(left == right) return left;
    int sum = Tree[Tree[y].start].sum - Tree[Tree[x].start].sum;

    int mid = (left + right) / 2;
    if(sum >= k){
        return query(left, mid, Tree[x].start, Tree[y].start, k);
    }else{
        return query(mid + 1, right, Tree[x].end, Tree[y].end, k - sum);
    }
}


int main(){
    freopen("/home/martin/AllWorkStation/Clang/OnlineJudge/input.txt", "r", stdin);
    int N, M;
    scanf("%d%d",&N, &M);


    vector<int> root(N);
    vector<int> dogs(N);

    SegmentTree tree(N);
    for (int i = 0; i < N; ++i) {
        int dogNum;
        scanf("%d", &dogNum);
        dogs[i] = dogNum;
        tree.update(1, N, root[i + 1], root[i], dogNum);
    }

    for (int j = 0; j < M; ++j) {
        int x;
        int y;
        int k;
        scanf("%d%d%d",&x, &y, &k);
        printf("%d\n", dogs[tree.query(1, N, root[x - 1], root[y], k ) - 1]);
    }
}