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

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:

    bool sys(TreeNode* l, TreeNode * r){
        if(l == NULL && r == NULL) return true;
        if(l == NULL && r != NULL) return false;
        if(l != NULL && r == NULL) return false;

        if(l->val != r->val) return false;

        return sys(l->left, r->right) && sys(l->right, r->left);
    }
    
    bool isSymmetrical(TreeNode* pRoot){
        return sys(pRoot->left, pRoot->right);
    }
};

int main(){
    
    return 0;
}
