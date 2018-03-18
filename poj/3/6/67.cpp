#include <iostream>
#include <fstream>
#define Rooms 80000

using namespace std;

struct Node{
    int leftLen;
    int rightLen;
    int maxLen;
    int start;
    int end;
    int lazy; // 0 的时候的表示没有任何操作, 1 lazy 清空的, -1 ....
    Node(){};
    Node(int left, int right):start(left),end(right), leftLen(right - left + 1),
                              rightLen(right - left + 1), maxLen(right - left + 1), lazy(0){}

    void checkIn(){
        maxLen = 0;
        leftLen = 0;
        rightLen = 0;
    }

    void checkOut(){
        leftLen = rightLen = maxLen = end - start + 1;
    }
};

Node Tree[Rooms * 4];

/**
 * 什么时候使用update, lazy 的数值 和 三个参数不一致的时候 !
 * @param node
 */
void updateNode(int node){
    int inOut = Tree[node].lazy;
    if(inOut == 1) Tree[node].checkOut();
    if(inOut == -1) Tree[node].checkIn();
}


/**
 *
 * @param l inclusive left end point
 * @param r inclusive right end point
 * @param node which tree node
 * @param inOut check in or check out !
 */
void check(int l, int r, int node, int inOut){
    // 叶子单独处理
    if(Tree[node].start == Tree[node].end){
        Tree[node].lazy = inOut;
        updateNode(node);
        return;
    }

    int leftChild = node * 2;
    int rightChild = node * 2 + 1;


    // lazy 下沉
    // 只有保证下层的信息正确, 才可以去除lazy, 很有可能出现这一种情况, 对于左右的lazy 下沉了, 但是没有处理更新数据

    // 更新子节点:
    if(Tree[node].lazy != 0){
        Tree[leftChild].lazy = Tree[node].lazy;
        Tree[rightChild].lazy = Tree[node].lazy;
        Tree[node].lazy = 0;
    }

    // 正好覆盖的区间
    if(l == Tree[node].start && r == Tree[node].end){
        // 设置lazy
        Tree[node].lazy = inOut;

        // 立刻更新元素, 区分是checkIn 还是 CheckOut
        if(inOut == 1) Tree[node].checkOut();
        if(inOut == -1) Tree[node].checkIn();
        return;
    }

    // 使用数据之前, 一定需要update lazy
    updateNode(leftChild);
    updateNode(rightChild);


    // update left.
    if(l <= Tree[leftChild].end) check(l, min(Tree[leftChild].end, r), leftChild, inOut);

    // update right
    if(r >= Tree[rightChild].start) check(max(Tree[rightChild].start, l), r, rightChild, inOut);



    // 合并下层信息, 实现对于更新父节点的数据
    Tree[node].maxLen = max(max(Tree[leftChild].maxLen, Tree[rightChild].maxLen), Tree[leftChild].rightLen + Tree[rightChild].leftLen);

    if(Tree[leftChild].leftLen == Tree[leftChild].end - Tree[leftChild].start + 1) {
        Tree[node].leftLen = Tree[leftChild].leftLen + Tree[rightChild].leftLen;
    }else{
        Tree[node].leftLen = Tree[leftChild].leftLen;
    }

    if(Tree[rightChild].rightLen == Tree[rightChild].end - Tree[rightChild].start + 1){
       Tree[node].rightLen = Tree[rightChild].rightLen + Tree[leftChild].rightLen;
    } else{
        Tree[node].rightLen = Tree[rightChild].rightLen;
    }
}


int query(int index, int requestLen){


    updateNode(index);
    // 叶子单独处理
    if(Tree[index].start == Tree[index].end){
        return Tree[index].start;
    }


    int leftChild = index * 2;
    int rightChild = index * 2 + 1;

    // lazy 必须下沉
    if(Tree[index].lazy != 0){
        Tree[leftChild].lazy = Tree[index].lazy;
        Tree[rightChild].lazy = Tree[index].lazy;
    }

    // update the lazy for leftChild and rightChild
    updateNode(leftChild);
    updateNode(rightChild);



    if(Tree[index].leftLen >= requestLen) return Tree[index].start;


    // 询问左区间
    if( Tree[leftChild].maxLen >= requestLen){
        return query(leftChild, requestLen);
    }

    // 询问两个区间之和
    if(Tree[leftChild].rightLen + Tree[rightChild].leftLen >= requestLen){
        return Tree[leftChild].end - Tree[leftChild].rightLen + 1;
    }

    // 询问右区间
    if(Tree[rightChild].maxLen >= requestLen){
        return query(rightChild, requestLen);
    }

    // 没有满足情况
    return 0;

}

// query and modify
int query(int queryLen){
    // before query breaks the query

    updateNode(1);
    int startIndex = query(1, queryLen);
    if(startIndex != 0) check(startIndex, startIndex + queryLen - 1, 1, -1);
    return startIndex;
}


void buildTree(int left, int right, int index){
    if(left == right){
        Tree[index] = Node(left, right);
        return;
    }

    int l = index * 2;
    int r = index * 2 + 1;

    int middle = (left + right) / 2;
    buildTree(left, middle, l);
    buildTree(middle + 1, right, r);

    Tree[index] = Node(Tree[l].start, Tree[r].end);
}

void buildTree(int len){
    buildTree(1, len, 1);
}



int main() {
    freopen("input.txt", "r", stdin);
    int N, M;
    while (~scanf("%d%d", &N, &M)) {
        buildTree(N);

        for (int i = 0; i < M; ++i) {
            int type;
            scanf("%d", &type);
            if (type == 1) {
                int len;
                scanf("%d", &len);
                printf("%d\n", query(len));
            } else {
                int start, len;
                scanf("%d%d", &start, &len);
                check(start, start + len - 1, 1, 1);
            }
        }
    }
    return 0;
}
