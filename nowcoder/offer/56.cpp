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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;
        if(pRoot == NULL) return res;

        queue<TreeNode *> q;
        q.push(pRoot);
        bool flag = false;
        stack<int> stk;
        while(!q.empty()){

            vector<int> vec;

            int len = q.size();
            
            for (int i = 0; i < len; i++) {
                TreeNode * t = q.front(); q.pop();
                if(t->left != NULL) q.push(t->left);
                if(t->right != NULL) q.push(t->right);

                if(flag)
                    stk.push(t->val);
                else
                    vec.push_back(t->val);
            }

            if(flag){
                while(!stk.empty()){
                    vec.push_back(stk.top());
                    stk.pop();
                }
            }

            res.push_back(vec);
            flag = !flag;
        }

        return res;
    }
    
};
int main(){
    
    return 0;
}
