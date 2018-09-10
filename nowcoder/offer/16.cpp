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
    TreeNode * bb;

    bool compare(TreeNode * a, TreeNode * b){
        if(a == NULL && b == NULL) return true;
        if(a == NULL && b != NULL) return false;
        if(a != NULL && b == NULL) return true;

        if(a->val != b->val) return false;

        return compare(a->left, b->left) && compare(a->right, b->right);
    }

    bool trans(TreeNode * a){
        if(a == NULL) return false;
        if(compare(a, bb) ) return true;

        if(trans(a->left)) return true;
        if(trans(a->right)) return true;

        return false;
    }

    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        bb = pRoot2;
        if(bb == NULL) return false;
        return trans(pRoot1);
    }
};
int main(){
    
    return 0;
}
