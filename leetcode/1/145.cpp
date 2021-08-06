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

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> res;
    void t(TreeNode* n){
        if(n->left != NULL)
        if(n->left != NULL) t(n->left);
        if(n->right != NULL) t(n->right);
        if(n != NULL) res.push_back(n->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        t(root);
        return res;        
    }
};

class Solution2 {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == NULL)
      return res;

    vector<TreeNode *> stk;
    stk.push_back(root);

    while (!stk.empty()) {
      TreeNode *n = stk.back();
      stk.pop_back();

      res.push_back(n->val);

      if (n->left) {
        stk.push_back(n->left);
      }

      if (n->right) {
        stk.push_back(n->right);
      }
    }

    reverse(res.begin(), res.end());
    return res;
  }
};
int main(){
    REOPEN_READ
    REOPEN_WRITE

    return 0;
}
