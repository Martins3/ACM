#include <bits/stdc++.h>
#include "../info.hpp"
using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      if(root != NULL){
        auto left = invertTree(root->left);
        auto right = invertTree(root->right);
        root->left = right;
        root->right = left;
      }
      return root;

    }
};

#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);
int main(int argc, char *argv[]){
  
  return 0;
}
