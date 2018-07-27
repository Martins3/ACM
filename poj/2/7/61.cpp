/**
 * 主席树
 * 不需要的使用离散化 ? stupid
 * sum is what ?
 * 局部变量的就是会出现bad_alloc 错误
 *
 */



#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

#define range 100050
class Node{
public:
    int sum;
    int start;
    int end;
};

vector<int> root(range);
vector<int> dogs(range);
vector<int> hashNum(range);
Node Tree[range * 40];

class SegmentTree{
public:
    int count;
    int N, M;


    void update(int left, int right, int& x, int y, int pos);
    int query(int left, int right, int x, int y, int k);
    SegmentTree(int N, int M): count(0), N(N), M(M){}
    ~SegmentTree(){
        cout << endl;
    }
    int getId(int);
    void solve();
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
    if(sum >= k) {
        return query(left, mid, Tree[x].start, Tree[y].start, k);
    } else {
        return query(mid + 1, right, Tree[x].end, Tree[y].end, k - sum);
    }
}

int SegmentTree::getId(int x){
    return lower_bound(hashNum.begin() , hashNum.end(), x) - hashNum.begin() + 1;
}
void SegmentTree::solve(){
    for (int i = 0; i < N; ++i) {
        int dogValue;
        scanf("%d", &dogValue);
        dogs[i] = dogValue;
        hashNum[i] = dogValue;
    }

    sort(hashNum.begin(), hashNum.end());
    hashNum.erase(unique(hashNum.begin(), hashNum.end()), hashNum.end());


    for (int i = 0; i < N; ++i) {
        update(1, N, root[i + 1], root[i], getId(dogs[i]));
    }

    for (int j = 0; j < M; ++j) {
        int x;
        int y;
        int k;
        scanf("%d%d%d",&x, &y, &k);
        printf("%d\n", hashNum[query(1, N, root[x - 1], root[y], k ) - 1]);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    int N, M;
    scanf("%d%d",&N, &M);
    SegmentTree tree(N, M);
    tree.solve();
    return 0;
}

