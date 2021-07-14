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
  vector<TreeNode *> create(int start, int end) { // [)
    vector<TreeNode *> res;
    if (start == end) {
      res.push_back(NULL);
      return res;
    }

    for (int i = start; i < end; ++i) {
      vector<TreeNode *> left = create(start, i);
      vector<TreeNode *> right = create(i + 1, end);
      for (auto l : left) {
        for (auto r : right) {
          TreeNode *a = new TreeNode(i);
          a->left = l;
          a->right = r;
          res.push_back(a);
        }
      }
    }
    return res;
  }

  vector<TreeNode *> generateTrees(int n) { return create(1, n + 1); }
};

int main(int argc, char *argv[]) { return 0; }
