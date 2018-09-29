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

    pair<TreeNode *, TreeNode *>  handle(TreeNode * n){
        if(n == NULL) return pair<TreeNode *, TreeNode *>(NULL, NULL);
        auto l = handle(n->left);
        auto r = handle(n->right);

        if(l.first == NULL){
            if(r.first == NULL){
                return pair<TreeNode *, TreeNode *>(n, n);
            }else{
                n->right = r.first;
                return pair<TreeNode *, TreeNode *>(n, r.second);
            }
        }else{
            n->left = NULL;
            if(r.first == NULL){
                n->right = l.first;
                return pair<TreeNode *, TreeNode *>(n, l.second);
            }else{
                n->right = l.first;
                l.second->right = r.first;
                return pair<TreeNode *, TreeNode *>(n, r.second);
            }
        }
    }

    void flatten(TreeNode* root) {
        handle(root);
    }
};

int main(){
    
    return 0;
}
