#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *first;
  TreeNode *second;
  TreeNode *p;
  TreeNode *q;
  TreeNode *res;
  vector<TreeNode *> toFirst;

  bool dfs(TreeNode *node, vector<TreeNode *> &stk) {
    if (node == NULL)
      return false;

    stk.push_back(node);

    if (first == NULL) {
      if (node == p) {
        first = p;
        second = q;
      } else if (node == q) {
        first = q;
        second = p;
      }

      if (first != NULL) {
        for (TreeNode *t : stk) {
          toFirst.push_back(t);
        }
      }

      if (dfs(node->left, stk))
        return true;
      if (dfs(node->right, stk))
        return true;
    } else {

      if (node == second) {
        int len = min(stk.size(), toFirst.size());
        for (int i = 0; i < len; ++i) {
          if (stk[i] == toFirst[i])
            res = stk[i];
          else
            break;
        }
        return true;
      }

      if (dfs(node->left, stk))
        return true;
      if (dfs(node->right, stk))
        return true;
    }

    stk.pop_back();
    return false;
  }

  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    first = NULL;
    second = NULL;
    res = NULL;
    this->p = p;
    this->q = q;

    vector<TreeNode *> stk;
    dfs(root, stk);
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
