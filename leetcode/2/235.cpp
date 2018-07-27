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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/ACM/leetcode/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/ACM/leetcode/output.txt", "w", stdout);


class DisjointSet{
public:
    int * arr;

    DisjointSet(int size){
        arr = new int[size + 1];
        memset(arr, 0, sizeof(int) * (size + 1));
    }

    int find(int x){
        if(arr[x]) return arr[x] = find(arr[x]);
        return x;
    }

    void union_pair(int x, int y){
        x = find(x);
        y = find(y);
        arr[y] = x;
    }
};

class Solution {
public:
    vector<int> nums;
    vector<bool> visited;
    DisjointSet * Uf;
    TreeNode * res;
    TreeNode * p;
    TreeNode * q;
    TreeNode * root;

    void get_size(TreeNode * node){
        if(node == NULL) return;
        get_size(node->left);
        get_size(node->right);
        nums.push_back(node->val);
    }

    void remap(TreeNode * node){
        if(node == NULL) return;
        remap(node->left);
        remap(node->right);
        node->val = std::lower_bound(nums.begin(), nums.end(), node->val) - nums.begin() + 1;
    }

    bool lca(TreeNode * node){
        if(node->left != NULL){
            if(lca(node->left)) return true;
            Uf->union_pair(node->val, node->left->val);
        }

        if(node->right != NULL){
            if(lca(node->right) ) return true;
            Uf->union_pair(node->val, node->right->val);
        }

        visited[node->val] = true;

        if(node == p && visited[q->val]){
            int s = Uf->find(q->val);
            get_res(root, s);
            return true;
        }

        if(node == q && visited[p->val]){
            int s = Uf->find(p->val);
            get_res(root, s);
            return true;
        }
        return false;
    }

    bool get_res(TreeNode * node, int s){
        if(node == NULL) return false;
        if(node->val == s){
            res = node;
            return true;
        }
        if(get_res(node->left, s)) return true;
        if(get_res(node->right, s)) return true;
        return false;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 重新映射所有的点
        get_size(root);
        sort(nums.begin(), nums.end());
        remap(root);

        // print_tree(root);

        Uf = new DisjointSet(nums.size());
        visited = vector<bool>(nums.size(),  false);
        this->p = p;
        this->q = q;
        this->root = root;
        res = NULL;
        if(root == NULL) return NULL;
        lca(root);
        res->val = nums[res->val - 1];
        return res;

    }
};

int main(){
    // REOPEN_READ
    // REOPEN_WRITE

    vector<TreeNode *> nodes =  make_tree(vector<int>{6,2,8,0,4,7,9,-1,-1,3,5});
    TreeNode * node = nodes[1];
    print_tree(node);
    Solution s;
    int a =  s.lowestCommonAncestor(node, nodes[2], nodes[3])->val;
    cout << "res " << a;

    return 0;
}
