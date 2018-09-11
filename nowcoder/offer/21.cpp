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
	TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        deque<TreeNode *> vec;
        std::vector<int> res;
        if(root == NULL) return res;
        vec.push_back(root);

        while(!vec.empty()){
            int len = vec.size();
            for (int i = 0; i < len; i++) {
                TreeNode * a =  vec.front();
                vec.pop_front();
                res.push_back(a->val);

                if(a->left != NULL){
                    vec.push_back(a->left);
                }

                if(a->right != NULL){
                    vec.push_back(a->right);
                }
            }
            
        }

        return res;
    }
};

int main(){
    
    return 0;
}
