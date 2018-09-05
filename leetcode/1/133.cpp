#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
#include <cassert>
#include <unordered_set>
#include "../info.hpp"

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

/**
 * 1. 指针显然是更加好的标志
 * 2. 访问　是指　已经复制了，只有都是地址，只有malloc
 * 3. 标记的含义 : 创建 将未加入的添加到stack 中间
 * 4. 出stack 的含义: 　初始化周边
 * 5. 进入stack :　没有添加周边
 * 6. 节点含有三个状态
 *
 * 1. 直接创建从　pointer 到 pointer 的映射
 */


class Solution {
public:
    // bfs
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr; 


        return start;
    }
};

int main(){
    
    return 0;
}
