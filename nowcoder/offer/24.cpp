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

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:

    RandomListNode* Clone(RandomListNode* pHead){
        if(pHead == NULL) return NULL;

        map<RandomListNode *, RandomListNode *> M;
        RandomListNode * cur = pHead;
        while(cur != NULL){
            M[cur] = new RandomListNode(cur->label);
            cur = cur->next;
        }

        cur = pHead;
        while(cur != NULL){
            M[cur]->next = M[cur->next];
            M[cur]->random = M[cur->random];
            cur = cur->next;
        }

        return M[pHead];
    }
};
int main(){
    
    return 0;
}
