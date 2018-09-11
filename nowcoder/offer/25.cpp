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
    pair<TreeNode*, TreeNode *> handle(TreeNode* pRootOfTree){

        pair<TreeNode *, TreeNode * > r;

        TreeNode * left;
        TreeNode * right;

        if(pRootOfTree->right == NULL){
            right = pRootOfTree;
        }else{
            r = handle(pRootOfTree->right);
            right = r.second;

            pRootOfTree->right = r.first;
            r.first->left = pRootOfTree;
        }

        if(pRootOfTree->left == NULL){
            left = pRootOfTree;
        }else{
            r = handle(pRootOfTree->left);
            left = r.first;

            pRootOfTree->left = r.second;
            r.second->right = pRootOfTree;
        }

        return pair<TreeNode *, TreeNode *>(left, right);
    }

    TreeNode* Convert(TreeNode* pRootOfTree){
        if(pRootOfTree == NULL) return NULL;
        return handle(pRootOfTree).first;
    }
};
int main(){
    Solution s;
    TreeNode * a = new TreeNode(2);
    TreeNode * b = new TreeNode(1);
    TreeNode * c = new TreeNode(3);
    a->right = c;
    a->left = b;
    TreeNode * res = s.Convert(a);
    int i = 0;
    while(res != NULL){
        if(i++ > 10) break;
        printf("%d\n", res->val);
        res = res->right;
    }

    return 0;
}
