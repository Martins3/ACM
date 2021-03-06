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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL && pHead2 == NULL) return NULL;

        ListNode * h;
        ListNode * cur;

        if(pHead1 == NULL){
            h = pHead2;
            pHead2  = pHead2->next;
        }else if(pHead2 == NULL){
            h = pHead1;
            pHead1 = pHead1->next;
        }else{
            if(pHead1->val < pHead2->val){
                h = pHead1;
                pHead1  = pHead1->next;
            }else{
                h = pHead2;
                pHead2  = pHead2->next;
            }
        }
        cur = h;

        while(pHead1 != NULL || pHead2 != NULL){
            if(pHead1 == NULL){
                cur->next = pHead2;
                pHead2  = pHead2->next;
            }else if(pHead2 == NULL){
                cur->next = pHead1;
                pHead1  = pHead1->next;
            }else{
                if(pHead1->val < pHead2->val){
                    cur->next = pHead1;
                    pHead1  = pHead1->next;
                }else{
                    cur->next = pHead2;
                    pHead2  = pHead2->next;
                }
            }
            cur = cur->next;
        }
        return h;
    }
};

int main(){

    ListNode * c =  new ListNode(3);
    ListNode * b =  new ListNode(2);b->next = c;
    ListNode * a =  new ListNode(1);a ->next = b;

    ListNode * g =  new ListNode(6);
    ListNode * f =  new ListNode(5); f->next = g;
    ListNode * e =  new ListNode(4); e->next = f;

    Solution s;
    ListNode * cur = s.Merge(a, e);
    while(cur!= NULL){
        printf("%d\n",cur->val);
        cur = cur->next;
    }

    
    return 0;
}
