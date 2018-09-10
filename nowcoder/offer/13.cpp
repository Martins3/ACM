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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        int len = 0;
        ListNode * cur = pListHead;
        while(cur != NULL){
            cur = cur->next;
            len ++;
        }

        len = len - k;
        // len 为 0的时候命中
        
        cur = pListHead;
        while(len > 0){
            cur = cur->next;
            len --;
        }

        if(len < 0) return NULL;

        return cur;
    }
};

int main(){
    return 0;
}
