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

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    struct TreeNode * build(vector<int> & pre, vector<int> & mid, int a, int b, int x, int y){
        if(a == b)
            return new TreeNode(pre[a]);
        if(a > b)
            return NULL;

        struct TreeNode * m = new TreeNode(pre[a]);
        int i;
        for (i = x; i <= y; ++i) {
            if(pre[a] == mid[i])
                break;
        }

        m->left = build(pre, mid ,a + 1, a + 1 + (i - 1) - x, x, i - 1);
        m ->right = build(pre, mid, a + 1 + (i - 1) - x + 1, b,  i + 1, y);
        return m;
    }

    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return build(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
    }
};

int main(){
    
    return 0;
}
