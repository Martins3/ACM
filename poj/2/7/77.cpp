
/**
 * 思路:
 * 如果所有的颜色都是很少的, 颜色区间的合并处理有没有更加简单的方法
 * leaf 含义很清晰, 中间的节点的含义是什么, 如何设计
 *  1. 表示区间的颜色
 *  2. 查询简单, 逐级向下进行查询可以的 !
 *  3. 修改简单, 向上修改就是可以, 向下查询的时候,修改就是可以
 *
 *
 *  // 如何构建出来一棵树,
 *  // 如何查询出来一个指定的节点
 *
 *
 *  Node: left index + right index to identity a node !
 *  left-node  left == right, this is also the standard to end the searching !
 *
 *  how to make the graph :
 *  from bottom to up: using stack ?
 *
 *
 *  关于构建Tree 的方法: 谁来释放, Node 而不是 Tree, Tree delete the head !
 *  不可以简单使用 : 添加颜色, 然后将上层的区间颜色全部实现修改
 *
 *  making the graph:
 *  using stack to handle it !
 *
 *  实际上: 实现的方法是数组的实现, 访问子节点的方法是: 2 * n  2 *n + 1
 *
 *  问题的关键, 区间的切分
 *
 *
 *  meaning of lazy: 查询的时候才会处理, 处理之后才会处理对应的数值, 首先完成之前更新, 然后延迟当前的更新 !
 *  相当于把数据实现延迟,
 *
 *  查询之前, 首先需要对于的当前数值实现更新, 然后处理下一步业务, 路径上面的所有的节点都是update的,
 *
 *  更新的含义: 之前含有update, 更新自己的处理的数值, 自己的update 放置子节点, 子节点的处理 也是lazy 的处理.
 *
 *  一个节点 仅仅含有一个lazy, 如果为lazy, 那么该节点之下所有都是, 所以lazy的时候, 如果update 的区间没有该节点的区间大
 *  所以需要处理的是, 继续update 下面的节点, 如果下面的节点, 一直到所有的
 *
 *  leaf 的单独处理
 *
 *  和 区间求和 有什么不同的位置: 返回值 update 的时候 !10 4 5
 *
 *  debug:
 *  1. query 的时候遇到的了 lazy , 由于lazy 的时候 已经处理了
 *
 *
 *  颜色管理方法:
 *  1. 合并 两个颜色, |
 *  2. 设置颜色
 *  3. 颜色的数目: 第一个 1 不算, 所以首先处理, 然后计数
 *
 *  segment tree:
 *  如何实现访问左右的子节点 2 * n  2 * n + 1
 *  如何实现询问当前的节控制的范文, getStart getEnd, 需要存储, 存储之后不在修改,
 *  如何设置节点的, start 和 end, 逐步划分的, 一直到可以left == end的时候
 *
 *  需要修改什么: 几乎全部
 *
 *  最后总结的一波:
 *  1. 完整区间检查, 区间拆分
 *  2. lazy 下放
 *  3. lazy 高于 colors(由于lazy 下放的操作)
 *  4. 更新的时候,叶子节点的首先检查 !
 *
 *
 *  显然: 线段树的问题在于的没有办法的区间的扩张和缩小 !

 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

class Node{
public:
    int lazy; // 0 表示没有lazy
    int colors;
    int start;
    int end;
    Node():lazy(0), colors(0){

    }

};



class SegmentTree{
    Node * nodes;
    int colors;
    void updateInterval(int node, int val, int left, int right);
    void query(int node, int start, int end);
    void initSegmentTree(int pos, int left, int right);
public:
    SegmentTree(int N);
    int query(int start, int end);

    void updateInterval(int val, int left, int right);
    ~SegmentTree(){
        delete[] nodes;
    }
};



void SegmentTree::initSegmentTree(int pos, int left, int right) {
    if(left == right){
        nodes[pos].start = left;
        nodes[pos].end = right;
        return;
    }
    int mid = (left + right) / 2;
    // left
    initSegmentTree(pos * 2, left, mid);

    // right
    initSegmentTree(pos * 2 + 1, mid + 1, right);

    // set the range
    nodes[pos].start = nodes[2 * pos].start;
    nodes[pos].end = nodes[2 * pos + 1].end;

}

SegmentTree::SegmentTree(int N){
    nodes = new  Node[N * 4];
    initSegmentTree(1, 1, N);
    nodes[1].lazy = 1;
}


void SegmentTree::updateInterval(int node, int val, int left, int right) {
    int rightChild = node * 2 + 1;
    int leftChild = node * 2;

    // 树的结构可以保证, 没有缺少child 那就是必定为leaf
    if(nodes[node].start == nodes[node].end){
        nodes[node].lazy = val;
        return;
    }


    if(nodes[node].lazy != 0){
         // 只有确保子树下面都是被更新的时候才是会被设置为 lazy

        // update children
        nodes[leftChild].lazy = nodes[node].lazy;
        nodes[rightChild].lazy = nodes[node].lazy;

        // update myself
        nodes[node].lazy = 0;
    }

    // 如果区间正好相等
    if(nodes[node].start == left && nodes[node].end == right){
        nodes[node].lazy = val;
        nodes[node].colors = 1 << val;
        return;
    }


    // 更新左区间
    if(left <= nodes[leftChild].end) updateInterval(leftChild, val, left, min(nodes[leftChild].end, right));


    // 更新右区间
    if(right >= nodes[rightChild].start) updateInterval(rightChild, val, max(nodes[rightChild].start, left), right);

    // 整合两个区间信息, 得到新的
    int leftColors = nodes[leftChild].colors;
    int rightColors = nodes[rightChild].colors;
    if(nodes[leftChild].lazy){
        leftColors = 1 << (nodes[leftChild].lazy);
    }
    if(nodes[rightChild].lazy){
        rightColors = 1 << (nodes[rightChild].lazy);
    }

    nodes[node].colors = leftColors | rightColors;

}


void SegmentTree::query(int node, int left, int right) {

    int rightChild = node * 2 + 1;
    int leftChild = node * 2;

    // 当前区域为lazy, 说明下面区域的都是该颜色, 没有必要继续
    if(nodes[node].lazy !=0) {
        colors = colors | (1 << nodes[node].lazy);
        return;
    }

    // 正好覆盖, 不需要继续访问下去
    if(nodes[node].start == left && nodes[node].end == right){
        colors = colors | nodes[node].colors;
        return;
    }



    // 查询左区间
    if(left <= nodes[leftChild].end) query(leftChild, left, min(nodes[leftChild].end, right));

    // 查询右区间
    if(right >= nodes[rightChild].start) query(rightChild, max(nodes[rightChild].start, left), right);

}


int SegmentTree::query(int start, int end) {
    // 使用head 调用重构函数, 然后整合结果
    colors = 0;
    query(1, start, end);
    int c;
    for (c = 0; colors; c++) colors &= colors - 1; // clear the least significant bit set
    return c;
}

void SegmentTree::updateInterval(int val, int left, int right) {
    updateInterval(1, val, left, right);
}


int main(){
    freopen("input.txt", "r", stdin);
    int L, T, O;
    scanf("%d%d%d", &L, &T, &O);getchar();
    SegmentTree tree(L);

    for (int i = 0; i < O; ++i) {
        int type = getchar();
        if(type == 'C'){
            int A, B, C;
            scanf("%d %d %d", &A, &B, &C);
            if(A <= B) {
                tree.updateInterval(C, A, B);
            }else {
                tree.updateInterval(C, B, A);
            }
        }else{
            int A, B;
            scanf("%d%d",  &A, &B);
            if(A <= B){
                printf("%d\n", tree.query(A, B));
            }else{
                printf("%d\n", tree.query(B, A));
            }
        }
        getchar(); // get the \n
    }
    return 0;
}