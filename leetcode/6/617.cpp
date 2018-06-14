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
#include "../info.hpp"

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/OnlineJudge/output.txt", "w", stdout);

class Solution {
public:
    TreeNode * help(TreeNode * t1, TreeNode * t2){
        TreeNode * node;
        if(t1 == NULL && t2 == NULL) return NULL;
        if(t1 == NULL){
            node = new TreeNode(t2->val);
            node->left = help(NULL, t2->left);
            node->right = help(NULL, t2->right);
            return node;
        }else if(t2 == NULL){
            node = new TreeNode(t1->val);
            node->left = help(t1->left, NULL);
            node->right = help(t1->right, NULL);
            return node;
        }

        node = new TreeNode(t1->val + t2->val);
        node->left = help(t1->left, t2->left);
        node->right = help(t1->right, t2->right);
        return node;

    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return help(t1, t2);
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    return 0;
}
