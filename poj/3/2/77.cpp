/**
 * 实现区间的离散化
 *  1. 将的所有的端点的数值实现的排序
 *  2. 节点去重
 *  3. 距离> 1 的插入的节点 // 本题没有这样操作的必要的
 *  4. 映射回去, 实现图的创建
 *
 * 为什么需要节点去重的, 由于不可以出现的对于相同的端点的含有的多个的映射
 * 距离大于的1 为什么, 需要插入数值, 没有必如此的, 如果有, 那也是的简单的添加的端点的映射
 * 为什么端点的映射的可以保证: 范围的控制
 *
 * 离散之后, 那如何: 变成的了区间的求和
 *
 * 最后, 注意的一个问题, 所有的数值为sum 为 long long Integer
 *
 * 什么时候的使用的:
 * 真实数值:  更新数值的时候
 *
 * 维持区间最大的高度的, 如果直接比高度高, 那么lazy, 否则继续的下沉
 * 最后query 的时候, 查询的所有的高度的
 * 创建的出来3 *
 *
 * 问题的结构:
 * pushDown: 拆分的子区间
 *
 * popUp: 子区间合并
 *
 * lazy 表示区间是否合并, 和height 一起使用,
 *
 * 只有lazy的数值为-1 的时候表示大小参差不
 *
 * 离散化为什么这么坑
 * 绝对不可以使用的操作方法: 使用区间覆盖的方法, 必须使用区间的分析方法 !
 *
 * bug:
 * 1. 递归无法结束
 * 2. 查询, 建图出现 特殊数值
 * 3. 算法含有错误
 * 4. 静态初始化 ?
 *
 */

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
//#include <sys/time.h>


using namespace std;
typedef long long int Integer;


class Node{
public:
    Integer lazy; // 0 表示没有lazy
    Integer start;
    Integer end;
};

#define Range 80000

Node nodes[6 * Range];
vector<Integer> endings(Range * 2); // 大小实现, 为节点的数值, 数值为正向映射
Integer data[2 * Range];
Integer height[Range]; // 没有什么用途


    Integer blocking;
    Integer N;






void initSegmentTree(Integer pos, Integer left, Integer right) {
    if(left + 1 == right){
        nodes[pos].start = left;
        nodes[pos].end = right;
        return;
    }
    Integer mid = (left + right) / 2;
    // left
    initSegmentTree(pos * 2, left, mid);

    // right
    initSegmentTree(pos * 2 + 1, mid, right);

    // set the range
    nodes[pos].start = nodes[2 * pos].start;
    nodes[pos].end = nodes[2 * pos + 1].end;

}


void updateInterval(Integer node, Integer val, Integer left, Integer right) {
    Integer rightChild = node * 2 + 1;
    Integer leftChild = node * 2;


    // 正好的区间

    // 只要整区间就是, 添加 !
    if(nodes[node].start == left && nodes[node].end == right){
        if(val > nodes[node].lazy)
            nodes[node].lazy =  val;
        return;
    }

    // pushDown
//    if(nodes[node].lazy >= 0){
//        nodes[leftChild].lazy = nodes[node].lazy;
//        nodes[rightChild].lazy = nodes[node].lazy;
//        nodes[node].lazy = -1;
//    }


    if(left < nodes[leftChild].end) updateInterval(leftChild, val, left, min(nodes[leftChild].end, right));

    if(right > nodes[rightChild].start) updateInterval(rightChild, val, max(nodes[rightChild].start, left), right);


    // popUP
//    if(nodes[leftChild].lazy == nodes[rightChild].lazy && nodes[node].lazy < 0){
//        nodes[node].lazy = nodes[rightChild].lazy;
//    }
}



/**
 *  离散化处理
 *  1. 使用vector来处理
 *
 *  2. 使用两个vector, 一个表示原始版本, 一个用于处理
 *  3. 首先排序, 去重
 *  4.
 *
 *  1. 在查询的时候, 询问映射数值, 使用gedId 函数
 *  2. 在"计算长度"的时候, 需要使用真实数值, 使用下标访问
 *
 *
 *  1. 如果是从0 开始计算数目和 从 1开始计算数目: 不同之处为什么 ?
 *      1. 真实数值总是从0 开始的, 所以从1开始技术需要 加上 偏移量 1
 *      2. 使用下标的时候, 然后需要减少 1
 */
Integer getId(Integer x){
    return lower_bound(endings.begin() , endings.end(), x) - endings.begin() + 1;
}

void query(Integer node, Integer num) {
    // 如果子区间更加大
    if(nodes[node].lazy < num) nodes[node].lazy = num;

    if(nodes[node].start + 1 == nodes[node].end){

        blocking += nodes[node].lazy * (endings[nodes[node].end - 1] - endings[nodes[node].start - 1]);
        return;
    }

    query(node * 2, nodes[node].lazy);
    query(node * 2 + 1, nodes[node].lazy);

}


// 输入的结束的调用
void sum() {


    // 对于映射向量排序去重
    sort(endings.begin(), endings.end());
    endings.erase(unique(endings.begin(), endings.end()), endings.end());



    Integer size = endings.size();

    initSegmentTree(1, 1, size);


    // height 的 size 就是输入的个数
    // 需要原始信息
    for (Integer k = 0; k < N; ++k) {
        Integer x = getId(data[k * 2]);
        Integer y = getId(data[k * 2 + 1]);
        Integer h = height[k];
        updateInterval(1, h, x, y);
    }

    // 将第一个节点的输出
    query(1, 0);
    printf("%lld\n", blocking);

}


int main(){
    freopen("input.txt", "r", stdin);

    // read to lists
//    struct timeval tp;
//    gettimeofday(&tp, NULL);
//    long long mslong = (long long) tp.tv_sec * 1000L + tp.tv_usec / 1000;

    Integer NB;
    scanf("%lld", &NB);
    nodes[1].lazy = 0;
    N = NB;
    for (Integer i = 0; i < N; ++i) {
        Integer x;
        Integer y;
        Integer h;
        scanf("%lld%lld%lld", &x, &y, &h);
        endings[2 * i] = x;
        endings[2 * i + 1] = y;
        data[2 * i] = x;
        data[2 * i + 1] = y;
        height[i] = h;
    }
    sum();

//    gettimeofday(&tp, NULL);
//    long long mslongA= (long long) tp.tv_sec * 1000L + tp.tv_usec / 1000;
//    cout << mslongA - mslong << endl;
}