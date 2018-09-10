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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::deque<TreeNode *> vec;
        vector<vector<int> > res;
        if(root == NULL)
            return res;

        vec.push_back(root);


        while(!vec.empty()){
            int len = vec.size();
            vector<int> v;

            for (int i = 0; i < len; i++) {
                v.push_back(vec.front()->val);
                if(vec.front()->left != NULL)
                    vec.push_back(vec.front()->left);

                if(vec.front()->right != NULL)
                    vec.push_back(vec.front()->right);

                vec.pop_front();
            }

            res.push_back(v);
        }

        return res;
    }
};

int main(){
    
    return 0;
}
