//
// Created by martin on 17-12-11.
// 没有思路


#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
using namespace std;

/**
 * 使用区间跟新方法
 * 1. 实现更新必定要求: 需要实现排序的添加
 * 2. 记录含有 位置求和 posBIT 数目求和 numBIT
 * 3. 求解求和方法
 *      sum_distance * threshold
 *      = (left_sum_distance + right_sum_distance ) * threshold
 *      = (left_num * pos - left_pos_sum + right_pos_sum - right_num * pos ) * threshold
 *
 * 实现细节:
 *  1. sort by threshold, and and get the pos
 *  2. 如果含有 threshold 相同的时候, 如何处理 ? ,排序随意, 还是含有位置信息 : 随意
 *  3. 从 1 开始计数的结果是什么 !
 *  4. query add 的顺序没有什么关系 !
 * ---> 修改的过程求和
 */
class Cow{
public:
    int threshold;
    int pos;
    bool operator > (const Cow& cow) const
    {
        return (threshold < cow.threshold);
    }

    Cow(int threshold, int pos): threshold(threshold), pos(pos){

    }
};



class BinaryIndexTree{
private:
    vector<int> arr;
    int lowBit(int x){
        return (x) & (-x);
    }
public:
    int sum(int x){
        int ans = 0;
        while(x != 0){
            ans += arr[x];
            x -= lowBit(x);
        }
        return ans;
    }

    void add(int x, int v){
        for(int i = x ; i < arr.size(); i += lowBit(i)){
            arr[i] += v;
        }
    }

    BinaryIndexTree(int size): arr(size + 1){

    }
};

int main(){
    freopen("input.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    const int posRange = 20000;
    BinaryIndexTree posSumBit(posRange); // sum all the pos
    BinaryIndexTree numSumBit(posRange); // all the number
    vector<Cow> cows; // store the datas


    // read
    for (int i = 0; i < N; ++i) {
        int threshold;
        int pos;
        scanf("%d%d", &threshold, &pos);
        Cow c(threshold, pos);
        cows.push_back(c);
    }

    // sort the cow
    sort(cows.begin(), cows.end(), greater<Cow>());

    // sum up
    long long sum = 0;
    for (int j = 0; j < N; ++j) {
        int threshold = cows[j].threshold;
        int pos = cows[j].pos;

        // add
        long long left_num = numSumBit.sum(pos);
        long long left_pos_sum = posSumBit.sum(pos);
        long long right_num = j - left_num; // j + 1  why !
        long long right_pos_sum = posSumBit.sum(posRange) - left_pos_sum;

        sum += (left_num * pos - left_pos_sum + right_pos_sum - right_num * pos ) * threshold;
        // query

        posSumBit.add(pos, pos);
        numSumBit.add(pos, 1);
    }

    printf("%lld", sum);
    return 0;
}

