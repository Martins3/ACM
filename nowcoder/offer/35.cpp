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

// 使用差值
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode * cur = pHead1;
        int len_a  = 0;
        while(cur != NULL){
            len_a ++;
            cur = cur ->next;
        }

        cur = pHead2;
        int len_b = 0;
        while(cur != NULL){
            len_b ++;
            cur = cur ->next;
        }
        
        if(len_a < len_b){
            cur = pHead1;
            pHead1 = pHead2;
            pHead2 = cur;
        }

        while(len_a > len_b){
            pHead1 = pHead1->next;
        }

        while(pHead1 != pHead2){
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }


        return pHead1;
    }
};

int main(){
    
    return 0;
}
