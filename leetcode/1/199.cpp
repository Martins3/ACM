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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return vector<int>();
        // 每层的
        deque<TreeNode *> vec;
        vector<int> res;
        vec.push_back(root);

        while(!vec.empty()){
            int len = vec.size();
            for (int i = 0; i < len; i++) {
                if(i == len - 1) res.push_back(vec.front()->val);

                if(vec.front()->left != NULL)
                    vec.push_back(vec.front()->left);

                if(vec.front()->right != NULL)
                    vec.push_back(vec.front()->right);

                vec.pop_front();
            }
        }
        return res;
    }
};

int main(){
    TreeNode * a = new TreeNode(1);
    TreeNode * b = new TreeNode(1);
    TreeNode * c = new TreeNode(1);
    a->left = b;
    a->right = c;

    Solution s;
    vector<int>  gg = s.rightSideView(a);
    for(auto a : gg){
        cout << a << endl;
    }
    

    
    return 0;
}
