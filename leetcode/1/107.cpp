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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL) return res;

        stack<vector<int> > sres;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            vector<int> v;
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                TreeNode * t = q.front(); q.pop();
                if(t->left != NULL) q.push(t->left);
                if(t->right != NULL) q.push(t->right);
                v.push_back(t->val);
            }
            sres.push(v);
        }
        while(!sres.empty()){
            res.push_back(sres.top());
            sres.pop();
        }
        return res;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    return 0;
}
