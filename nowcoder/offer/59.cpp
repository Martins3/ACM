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
    int getSize(TreeNode * s){
        if(s == NULL) return 0;
        return getSize(s->left) + getSize(s->right) + 1;
    }

    TreeNode * kth(TreeNode * node, int k){
        int l = getSize(node->left);
        if(l + 1 == k) return node;

        if(k <= l){
            return kth(node->left, k);
        }

        return kth(node->right, k - l - 1);
    }

    TreeNode* KthNode(TreeNode* pRoot, int k){
        if(k <= 0) return NULL;
        if(pRoot == NULL) return NULL;

        int len = getSize(pRoot);
        if(k > len) return NULL;

        return kth(pRoot, k);
    }
};

int main(){
    
    return 0;
}
