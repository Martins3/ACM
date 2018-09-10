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
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode * h = pHead;
        if(h == NULL) return NULL;
        h->next = NULL;

        ListNode * cur = pHead->next;
        while(cur != NULL){
            ListNode * t = cur->next;
            cur->next = h;
            h = cur;
            cur = t;
        }
        return h;
    }
};

int main(){
    ListNode a(1);
    a.next = new ListNode(2);
    a.next->next = new ListNode(3);
    
    Solution k;
    ListNode * s = k.ReverseList(&a);
    printf("%d\n", s->val);
    printf("%d\n", s->next->val);
    printf("%d\n", s->next->next->val);

    
    return 0;
}
