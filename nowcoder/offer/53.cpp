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

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    // 如果所有都是含有相同的，如何处理
    ListNode* deleteDuplication(ListNode* pHead){
        if(pHead == NULL) return NULL;
        vector<int> vec;
        ListNode * cur = pHead;
        while(cur != NULL){
            vec.push_back(cur->val);
            cur = cur->next;
        }

        int last = vec[0];
        vector<bool> go(true, vec.size());

        for (int i = 1; i < vec.size(); i++) {
            if(vec[i] == last){
                go[i - 1] = false;
                go[i] = false;
            }
            last = vec[i];
        }

        vector<ListNode *> v;
        cur = pHead;
        for (int i = 0; i < vec.size(); i++) {
            if(go[i]){
                v.push_back(cur);
            }
            cur = cur->next;
        }

        if(v.empty()) return NULL;
        v.push_back(NULL);

        for (int i = 0; i < v.size() - 1; i++) {
            v[i]->next = v[i + 1];
        }

        return v[0];
    }
};
int main(){
    
    return 0;
}
