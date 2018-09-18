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

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

/**
 *
 * 需要借助大小关系
 * 前序计算，添加#
 * 
 * 1. empty tree
 * 2. 
 */
class Solution {
public:
    int da(TreeNode * n){
        if(n == NULL) return 0;
        return da(n->left) + 1 + da(n->right);
    }

    char * h;
    int loc;

    void trans(TreeNode * node){
        if(node  == NULL){
            h[loc++] = '#';
            h[loc++] = ' ';
        }else{
            int t = node->val;
            while(t){
                h[loc++] = t %10 + '0';
                t = t / 10;
            }
            h[loc++] = ' ';
            trans(node->left);
            trans(node->right);
        }
    }

    

    char* Serialize(TreeNode *root) {    
        int s = da(root);
        s += 100;
        loc = 0;
        h = (char *)malloc(sizeof(char) * (s * 20 + 1000));
        trans(root);
        h[loc - 1] = '\0';
        return h;
    }

    char * str;
    TreeNode * verse(){
        queue<int> s;
        while(true){
            if(str[loc] == ' ') {
                // 数值输入完毕
                loc ++;
                break;
            }else if(str[loc] == '#') {
                loc = loc + 2;
                return NULL;
            }else{
                s.push(str[loc] - '0'); 
                loc ++;
            }
        }

        int t = 0;
        int pow = 1;
        while(!s.empty()){
            t += pow * s.front();
            s.pop();
            pow = pow * 10;
        }

        TreeNode * a = new TreeNode(t);
        a->left = verse();
        a->right = verse();
        return a;
    }

    TreeNode* Deserialize(char *str) {
        this->str = str;
        loc = 0;
        return verse();
    }
};

int main(){
    Solution s;
    TreeNode * node = new TreeNode(100);
    node->left = new TreeNode(324);
    node->right = new TreeNode(789);
    char * k = s.Serialize(node);
    printf("%s\n", k);

    TreeNode * x =  s.Deserialize(k);
    printf("%s\n", s.Serialize(x));
    
    return 0;
}
