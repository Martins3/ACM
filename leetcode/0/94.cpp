struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

int main(int argc, char *argv[]) { return 0; }

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<TreeNode *> stk;
    vector<int> res;
    while(root != NULL  || stk.empty()){
      while(root != NULL){
        stk.push_back(root);
        root = root->left;
      }

      TreeNode * n = stk.back();
      stk.pop_back();
      res.push_back(n->val);
      root = n->right;
    }

    return res;
  }
};
