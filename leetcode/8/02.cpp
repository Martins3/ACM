#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

// 1. 找到环路
// 2. 当遇到进入环路的，将整个 stack 的全部标记为 可进入 环路
class Solution {
public:
  vector<int> stack;
  vector<bool> inStack; // 必须严格的按照 stack
                        // 的概念，而不是，当遇到访问过的，那么就表示构成环
  vector<int> inCircle;
  vector<int> reachCircle;
  vector<bool> accessed; // 访问过的，不要再去访问了

  void trans(vector<vector<int>> &graph, int i) {

    accessed[i] = true;
    inStack[i] = true;
    stack.push_back(i);
    for (auto j : graph[i]) {
      if (accessed[j]) {

        if(inStack[j]){
          auto iter = stack.rbegin();
          while (true) {
            inCircle[*iter] = true;
            if(*iter == j) break;
            iter++;
          }
        }

        if (inCircle[j] || reachCircle[j]) {
          auto iter = stack.rbegin();
          while (iter != stack.rend()) {
            reachCircle[*iter] = true;
            iter++;
          }
        }

      } else if (!accessed[j]) {
        trans(graph, j);
      }
    }

    inStack[i] = false;
    stack.pop_back();
  }

  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    inStack = vector<bool>(10000 + 10, false);
    accessed = vector<bool>(10000 + 10, false);
    reachCircle = vector<int>(10000 + 10, false);
    inCircle = vector<int>(10000 + 10, false);
    for (int i = 0; i < graph.size(); ++i) {
      if (!accessed[i])
        trans(graph, i);
    }
    vector<int> res;
    // 按照 incircle 处理
    for (int i = 0; i < graph.size(); ++i) {
      if(!reachCircle[i]) res.push_back(i);
    }

    return res;
  }
};

/**
 * 错误原因 : 题目意思理解完全错误
 * 措施:
 */

/**
 * 错误原因 : i j 变量使用混淆
 * 措施:
 */

/**
 * 错误原因 : 将 在环中间的，而不是 不在环中间的输出了
 * 措施:
 */

/**
 * 错误原因 : 不是在环中间的，而是可以到达环的
 * 措施:
 */

/**
 * 错误原因 : 不仅仅到达环，只要是接触到 reachCircle 的，也需要被 reachCircle
 * 措施:
 */



/**
 * 错误原因 : 新添加的变量没有初始化
 * 措施:
 */


/* 0 : [1,3,4,5,7,9],
 * 1 : [1,3,8,9],
 * 2 : [3,4,5,8],
 * 3 : [1,8],
 * 4 : [5,7,8]
 * 5 : [8,9]
 * 6 : [7,8,9]
 * 7 : [3],
 * 8 : [],
 * 9 : [] 
 * */
int main() {
  Solution s;
  vector<vector<int>> k{{1,2},{2,3},{5},{0},{5},{},{}};
  s.eventualSafeNodes(k);
  return 0; }
