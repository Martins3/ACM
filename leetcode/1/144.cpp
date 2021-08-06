#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root == NULL)
      return res;

    vector<TreeNode *> stk;
    stk.push_back(root);

    while (!stk.empty()) {
      TreeNode *n = stk.back();
      stk.pop_back();

      res.push_back(n->val);

      if (n->right) {
        stk.push_back(n->right);
      }

      if (n->left) {
        stk.push_back(n->left);
      }

    }

    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
