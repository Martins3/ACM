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


class Solution {
public:
    int res = 1;
    int trans(TreeNode * node){
        if(node == NULL) return 0;
        int l = trans(node->left);
        int r = trans(node->right);
        if(l != 0)
            if(node->val !=  node->left->val) l = 0;

        if(r != 0)
            if(node->val !=  node->right->val) r = 0;

        res = max(1 + l + r, res);
        return 1 + max(l, r);
    }

    int longestUnivaluePath(TreeNode* root) {
        trans(root);
        return res - 1;
    }
};
