#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *getMiddle(ListNode *head) {
    if (head == NULL)
      return NULL;
    if(head ->next == NULL)
      return head;

    ListNode *fast = head;
    ListNode *slow = head;

    // 只要进入到这个位置，那么 slow 是 fast 的
    while (true) {
      if (fast->next == NULL)
        return slow->next;
      if (fast->next->next == NULL)
        return slow->next;
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }

  ListNode * reverse(ListNode * head){
    if(head == NULL) return NULL;

    ListNode * new_head = head;
    head = head->next;
    new_head->next = NULL;

    while(head != NULL){
      ListNode * tmp = head;
      head = head->next;

      tmp->next = new_head;
      new_head = tmp;
    }

    return new_head;
  }
  
  bool isPalindrome(ListNode *head) {
    ListNode * m = getMiddle(head);
    ListNode * head2 = reverse(m);
    while(head2 != NULL){
      if(head2->val != head->val) return false;

      head2 = head2->next;
      head = head->next;
    }
    return true;
  }
};

int main(int argc, char *argv[]) { return 0; }
