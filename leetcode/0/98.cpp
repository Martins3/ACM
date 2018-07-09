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
    bool valid;

    pair<int,int> check(TreeNode * node){
        int small = INT_MAX;
        int big = INT_MIN;

        if(node->left != NULL){
            pair<int, int> p = check(node->left);
            if(!valid || node->val <= p.second){
                valid = false;
                return make_pair(0, 0);
            }
            small = p.first;
        }

        if(node->right != NULL){
            pair<int, int> p = check(node->right);
            if(!valid || node->val >= p.first){
                valid = false;
                return make_pair(0, 0);
            }
            big = p.second;
        }

        small = min(small, node->val);
        big = max(big, node->val);
        auto a = make_pair(small, big);
        return a;
    }

    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        valid = true;
        check(root);
        return valid;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    return 0;
}
