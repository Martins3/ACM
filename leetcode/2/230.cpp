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
#include "../info.h"

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

class Solution {
public:
    int k;
    int res;
    int which;
    
    bool find_k(TreeNode * node){
        if(node == NULL) return false;
        
        if(find_k(node->left)) return true;
        which ++;
        if(which == k) {
            res = node->val;
            return true;
        }
        if(find_k(node->right)) return true;

        return false;
    }

    int kthSmallest(TreeNode* root, int k){
        this->k = k;
        which = 0;
        find_k(root);
        return res;
    }
};
int main(){
    REOPEN_READ
    //REOPEN_WRITE


    return 0;
}