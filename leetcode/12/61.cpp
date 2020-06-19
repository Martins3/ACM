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
#include <unordered_map>
#include "../info.hpp"

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);


class FindElements {
public:
    unordered_set<int> s;

    void trans(TreeNode * node, int val){
      if(node == NULL) return;
      s.insert(val);

      trans(node->left, val * 2 + 1);
      trans(node->right, val * 2 + 2);
    }

    FindElements(TreeNode* root) {
      trans(root, 0);
    }
    
    bool find(int target) {
      return s.find(target) == s.end();
    }
};

int main(){
  
  return 0;
}

/**
 * 错误原因 : 返回结果符号判断错误
 * 措施:
 */
