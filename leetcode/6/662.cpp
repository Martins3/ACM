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

class Loc{
public:
    TreeNode * node;
    int pos;
    Loc(TreeNode * node, int pos): node(node), pos(pos){}
};

class Solution {
public:
    int res;


    int widthOfBinaryTree(TreeNode* root) {
        queue<Loc> q;
        q.push(Loc(root, 0));

        int res = 0;
        while(!q.empty()){

            int size = q.size();
            int left = q.front().pos;
            int posi = 0;
            for (int i = 0; i < size; ++i) {
                Loc l = q.front(); q.pop();
                TreeNode * node = l.node;
                posi = l.pos;
                if(node ->left != NULL){
                    q.push(Loc(node->left, posi * 2));
                }

                if(node ->right != NULL){
                    q.push(Loc(node->right, posi * 2 + 1));
                }
            }
            res = max(res, posi - left + 1);
        }
        return res;
    }
};
int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    return 0;
}
