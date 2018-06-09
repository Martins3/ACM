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
#include <cstddef>
#include "../info.hpp"

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/OnlineJudge/output.txt", "w", stdout);
class Solution {
public:
    TreeNode * help(vector<int>& nums, int l, int r){
        if(r - l == 0){
            return new TreeNode(nums[l]);
        }else if(r - l == 1){
            TreeNode * n = new TreeNode(nums[r]);
            TreeNode * res = new TreeNode(nums[l]);
            res->right = n;
            return res;
        }else if(r - l > 1){
            int m = (r + l) / 2;
            TreeNode * left = help(nums, l, m - 1);
            TreeNode * right = help(nums, m + 1, r);
            TreeNode * res = new TreeNode(nums[m]);
            res->left = left;
            res->right = right;
            return res;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return help(nums, 0, nums.size() - 1);
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    return 0;
}
