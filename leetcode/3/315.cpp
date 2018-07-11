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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/OnlineJudge/output.txt", "w", stdout);

/**
 * 动态查询和从右向左的添加：
 *      当在右侧， 并且更加小的时候， 才会被加入到其中
 */

class Node{
public:
    int left;
    int right;
    int val; // 区间的个数
    Node(int x, int y): left(x), right(y), val(0){}
    Node()=default;
};

class Solution {
public:
    Node * tree;

    void build(int i, int left, int right){
        tree[i] = Node(left, right);
        if(left == right) return;

        int mid = left + (right - left) / 2;
        build(2 * i, left, mid);
        build(2 * i + 1, mid + 1, right);
    }

    void buildTree(int size){
        tree = new Node[size * 4];
        build(1, 0, size - 1);
    }

    void update(int loc, int pos){
        /**
         * 有必要更新到最下面吗?
         */
        Node * node = tree + loc;
        if(node->left == node->right){
            node->val ++;
            return;
        }

        Node * l = tree + loc * 2;
        // 左区间
        if(l->right >= loc){
            update(loc * 2 , pos);
        }

        // 右区间
        else{
            update(loc * 2  + 1, pos);
        }

        node->val ++;
    }

    int query(int loc, int x, int y){
        Node * node = tree + loc;
        if(node->left == x && node->right == y) return node->val;

        Node * l = tree + loc * 2;
        Node * r = tree + loc * 2 + 1;
        if(y <= l->right)
            return query(loc * 2, x, y);

        if(x >= r->left)
            return query(loc * 2 + 1, x, y);

        return query(loc * 2, x, l->right) + query(loc * 2 + 1, r->left, y);
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> cond(nums);
        sort(cond.begin(), cond.end());
        for(int & i : nums){
            i = lower_bound(cond.begin(), cond.end(), i) - cond.begin();
        }
        buildTree(nums.size());

        vector<int> res(nums.size(), 0);
        for (int i = nums.size() - 1; i >= 0; --i) {
            if(nums[i] == 0)
                res[i] = 0;
            else
                res[i] = query(1, 0, nums[i] - 1);
            update(1, nums[i]);
        }

        return res;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    vector<int> nums{5, 2, 6, 1};
    for(int i : s.countSmaller(nums))
        cout << i << " ";
    return 0;
}
