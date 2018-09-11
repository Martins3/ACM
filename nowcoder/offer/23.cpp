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

struct Cmp{
    inline bool operator()(const vector<int> & a, const vector<int> & b){
        return a.size() > b.size();
    }
};

// 注意，二叉树的递归，处理叶子，但是也是需要处理NULL

class Solution {
public:
    int sum;
    vector<int> vec;
    vector<vector<int> > res;

    void trans(TreeNode * root){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            vec.push_back(root->val);
            sum -= root->val; 
            if(!sum) res.push_back(vec);
            sum += root->val;
            vec.pop_back();
            return;
        }

        vec.push_back(root->val);
        sum -= root->val; 
        trans(root->left);
        trans(root->right);

        vec.pop_back();
        sum += root->val;
    }

    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == NULL) return res;
        sum = expectNumber;
        trans(root);
        sort(res.begin(), res.end(), Cmp());
        return res;
    }
};
int main(){
    
    return 0;
}
