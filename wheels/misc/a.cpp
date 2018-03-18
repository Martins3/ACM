#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
#define VSCODE_READ freopen("../../../input.txt", "r", stdin);
#define C_READ freopen("../../input.txt", "r", stdin);

/**
 * 寻找的连续的最大的求和
 * 
 * 算法思路： 当发现local_sum求和小于0的时候，
 * left指针右边移动， 读取 negative 不可以的让当前的求和小于0， 否则left 指正右边移动
 * 
 */
int continuousMaxSum(vector<int> const & arr){
    int sum = 0;
    int right = 0;
    int localSum = 0;
    
    while(right < arr.size()){
        localSum += arr[right];
        sum = max(sum, localSum);
        if(localSum < 0){
            localSum = 0;
        }
        right++;
    }
    return sum;
}

/**
 * 当存在的时候， 返回值为第一个的下标
 * 当不存在的时候，返回值为插入的时候位置的数值,也就是第一个大于的位置
 * 
 * 算法： 和二分查找的唯一区别在于对于等于的处理
 * １. 为什么总是middel = left + 1 只是减小范围的策略而已，　没有其他的意思
 * 
 */


int my_lower_bound(vector<int> const & arr, int target){
    int len = arr.size();
    int left = 0;
    int right = len - 1;
    int middle;

    while(left < right){
        middle = left + (right - left) / 2;
        if(arr[middle] >= target)
            // 左边的数值也许有
            right = middle;
        else
            // 正确的数值一定在右边
            left = middle + 1;
    }

    return middle;
}

/**
 * 循环的日程表:
 * 算法： 递归的实现算法， 证明容易，想出来很难
 */
vector<vector<int> > & cycleCallender(vector<vector<int> > & res, int num){
    vector<int> a0{1, 2};
    vector<int> a1{2, 1};
    res.push_back(a0);
    res.push_back(a1);
    
    for(int i = 2; i <= num; i++){

        for(int j = 0; j < (int)(pow(2, i - 1)); j++){
            for(int k = 0; k < (int)(pow(2, i - 1)); k++){
                res[j].push_back(res[j][k] + (int)(pow(2, i - 1)));
            }
        }

        for(int j = 0; j < (int)(pow(2, i -1)); j++){
            vector<int> row;
            for(int k = 0; k < (int)(pow(2, i)); k++){
                if(k < (int)(pow(2, i - 1))){
                    row.push_back(res[j][k] + (int)(pow(2, i -1)));
                }else{
                    row.push_back(res[j][k] - (int)(pow(2, i -1)));
                }
            }
            res.push_back(row);
        }

    }
    
    return res; 
}

/**
 * 区间问题合集
 * 1. 选择不想交区间
 * 2. 区间选择点：对于不想交的区间，选择最少的点让区间都被选择的点命中
 * 3. 区间覆盖： 选择最少的区间覆盖区间
 * NYI
 */


/**
 * Huffman编码
 * NYI
 */




int main(){
    vector<vector<int> > res;
    cycleCallender(res, 5);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}