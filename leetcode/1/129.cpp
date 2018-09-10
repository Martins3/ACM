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

// 哔了狗，这种题还要测试这么长时间
class Solution {
public:
    int sum;
    string s;

    void dfs(TreeNode * n){
        if(n== NULL) return;
        if(n->left == NULL && n->right == NULL){
            s.push_back(n->val + '0');
            sum += stoi(s);
        
            s.pop_back();
            return;
        }
        s.push_back(n->val + '0');
        dfs(n->left);
        dfs(n->right);
        s.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        sum  = 0;
        dfs(root);
        return sum;
    }
};
int main(){

    string s;
    s.push_back('0' + 1);
    s.push_back('0' + 2);
    printf("%d\n", stoi(s));

    return 0;
}
