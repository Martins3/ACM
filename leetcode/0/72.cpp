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

/**
 * 从 左边 到 最右边 分析， 只有的当前的操作实现了  如果的匹配那么的操作
 * 如果 没有匹配， 采用 三种的方法 插入 删除 替换 ！
 * 
 * 维持一个 指针， 记录的尚且没有匹配的元素的 index , 提供 一个 函数的位置 
 * 提供一个list
 * 提供个数 编辑的时候的总是的提供的额最佳的选项的实行的，
 * 1. 相等的时候不替换
 * 2. 只有和下一个相等的时候才使用的插入
 * 3. 。。。。。
 * 
 * 后面的若干的步骤无法看见，
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        return 1;
    }
};

int main(){
    REOPEN_READ
    //REOPEN_WRITE

    return 0;
}