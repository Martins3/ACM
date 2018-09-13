#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <forward_list>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

class Solution {
public:
    /**
     * 想法1:
     * 1. 首先选择较大的数值
     * 2. 然后依旧采用stack 的策略分析
     *
     * 想法2:
     * 1. 在第一个数值可以出现的位置，查找最大值
     *
     *
     * 想法3:
     * https://www.cnblogs.com/CarryPotMan/p/5384172.html
     * 1. 简单一点的问题 从一个数组里挑出k个数字组成最大的数
     *      1. 对于两个数组都是需要操作一下
     *      2. 之所以需要如此的原因是，采取剩下的数值不会更好
     *
     * 1.1 中间含有关键的一步，那就是位置长度相加的长度为k
     *
     * 2. 现在获取两个长度都是k 的数组，只是需要将两个数组中间逐个选取数值
     *      1. 当数值相同的时候，选取哪一个数组的数值 ?
     *      2. 但是如果两个数值必定需要采用一个
     *      3. 希望在更加早到达的时候，获取的数值更大
     *      
     *
     */
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

    }
};

int main(){
    REOPEN_READ
    //REOPEN_WRITE

    return 0;
}
