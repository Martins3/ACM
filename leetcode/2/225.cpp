#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);


int main(int argc, char *argv[]){
  return 0;
}
class MyStack {
    queue<int> a;
    queue<int> b;
    queue<int> * push_to;
    queue<int> * empty_one;
public:
    /** Initialize your data structure here. */
    MyStack():push_to(&a), empty_one(&b) {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
      push_to->push(x);
    }

    int switch_queue(bool dont_remove) {
      int last_one;
      while(!push_to->empty()){
        last_one = push_to->front();
        push_to->pop();
        if(!push_to->empty() || dont_remove) // 这是最后一个，不要动
          empty_one->push(last_one);
      }
      queue<int> * tmp = push_to;
      push_to = empty_one;
      empty_one = tmp;

      return last_one;
    }

    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
      return switch_queue(false);
    }
    
    /** Get the top element. */
    int top() {
      return switch_queue(true);
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
      return push_to->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
