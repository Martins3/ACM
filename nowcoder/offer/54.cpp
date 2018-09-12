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
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    bool fuck;
    TreeLinkNode* GetNext(TreeLinkNode* pNode){
        fuck = false;

        TreeLinkNode * s = next(pNode);
        if(s == NULL) return NULL;
        
        if(fuck) return s;

        while(s->left != NULL){
            s = s->left;
        }
        return s;
    }

    TreeLinkNode* next(TreeLinkNode* pNode){
        if(pNode == NULL) return NULL;

        if(pNode->right != NULL) return pNode->right;

        while(pNode->next != NULL){
            if(pNode->next->left == pNode){
               
                    fuck = true;
                    return pNode->next;
            }
            pNode = pNode->next;
        }
        return NULL;
    }
};
