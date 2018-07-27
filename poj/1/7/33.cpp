//
// Created by martin on 17-12-18.
//
/**
 *
 * 带权并查集即是结点存有权值信息的并查集。
 * 当两个元素之间的关系可以量化，并且关系可以合并时，可以使用带权并查集来维护元素之间的关系。
 * 带权并查集每个元素的权通常描述其与并查集中祖先的关系，这种关系如何合并，路径压缩时就如何压缩。
 * 带权并查集可以推算集合内点的关系，而一般并查集只能判断属于某个集合。
 *
 * 离散化: set, 表现范围太大, 难以保证含有的范围, 需要的实现的数值的映射, 来查找正确的数值
 * 出现错误的时候的:
 *
 *
 * rank记录what: 和父节点的 1的个数
 * ones 中间的含有的数值的表示: father[x] 和 [x] 的 1的个数的
 *
 * 合并: 需要子树
 *
 *
 *  inclusive 带来的问题的, root 不可以包含到的, 部署的位置为
 *  为了方便运算(或者只有如此才可以运算, 所以必须如此, 保证顺序), 转化为相交区间的xor
 *
 *
 * index 的处理: 如果的处理的index,
 *
 *
 * 路径压缩的过程的中间的处理:
 *
 * find 的过程中间的路径压缩:
 * find的过程中间的需要实现的修改了父节点的, 所以的需要实现原来的父节点的数值的变化
 *
 * 两个点不在相同子树: 没有区间没有重合的端点
 *
 *
 * inclusive的处理, 只有输入的时候处理 !
 *
 * site: http://www.cnblogs.com/kuangbin/archive/2013/04/05/3000741.html
 *
 */

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int Integer;


class DisjointSet{
public:
    const int size;
    int * arr; // for union
    bool * ones; // (father[x] , x]  左边开区间

    DisjointSet(int num):size(num + 1){
        arr = new int[size];
        for (int i = 0; i < size ; ++i) {
            arr[i] = 0;
        }

        ones = new bool[size]; // 无需赋初值
        for (int j = 0; j < size ; ++j) {
            ones[j] = false;
        }
    }

    ~DisjointSet(){
        delete [] arr;
        delete [] ones;
    }


    int find(int x);

    void unite(int x, int y, bool xyOnes);

};

int DisjointSet::find(int x) {
    if(arr[x] == 0) return x;
    int newFather = find(arr[x]);

    // arr[x] exFather ; exFather的距离修正了
    ones[x] = ones[x] ^ ones[arr[x]];

    arr[x] = newFather;
    return newFather;
}


void DisjointSet::unite(int x, int y, bool xyOnes) {
    int rootX = find(x);
    int rootY = find(y);

    if(rootX == rootY) return;

    // 将较小值设置为root
    if(rootX > rootY){
        swap(rootX, rootY);
    }

    // 只是需要修改rootY 的权重, Y 的权重之后查询的时候修改
    ones[rootY] = ones[x] ^ ones[y] ^ xyOnes;
    arr[rootY] = rootX;

}
class Data{
public:
    Integer x;
    Integer y;
    bool one;
    Data():one(false){

    }
};

int main(){
    freopen("input.txt", "r", stdin);
    Integer N;
    int M;
    scanf("%lld%d", &N, &M);
    // 离散化处理
    vector<Integer> realNum(2 * M);
    map<Integer, int> hashNum;
    vector<Data> data(M);

    for (int i = 0; i < M; ++i) {
        Integer start;
        Integer end;
        char ans[10];
        scanf("%lld %lld %s",&start, &end, ans);
        data[i].x = start - 1;
        data[i].y = end;
        if(ans[0] == 'o') data[i].one = true;

        realNum[2 * i] = start - 1;
        realNum[2 * i + 1] = end;
    }

    // resolute the hash
    vector<Integer> &vec = realNum;
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());


    for (int j = 0; j < realNum.size(); ++j) {
        hashNum[realNum[j]] = j + 1; // disjoint set 的接口的实现要求
    }


    DisjointSet set(realNum.size());


    // analyze the number !
    int i;
    for (i = 0; i < M; ++i) {
        int x = hashNum[data[i].x];
        int y = hashNum[data[i].y];


        if(set.find(x) != set.find(y)){
            set.unite(x, y, data[i].one);
        }else{
            if(set.ones[x] ^ set.ones[y] ^ data[i].one){
                break;
            }
        }
    }
    printf("%d", i);
    return 0;
}