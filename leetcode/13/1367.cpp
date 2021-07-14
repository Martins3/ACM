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

class Solution {
public:
    bool test(ListNode * list, TreeNode * tree){
      if(list == NULL) return true;
      if(tree == NULL) return false;

      if(list->val == tree->val){
        if(test(list->next, tree->left)) return true;
        if(test(list->next, tree->right)) return true;
      }

      return false;
    }
  

    bool isSubPath(ListNode* head, TreeNode* root) {
      if(root == NULL) return false;
      if(test(head, root)) return true;


      if(isSubPath(head, root->left)) return true;
      if(isSubPath(head, root->right)) return true;
      return false;
    }
};

int main(){
  
  return 0;
}
