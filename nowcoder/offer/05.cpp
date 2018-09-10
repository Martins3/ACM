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

//
// 两种操作全部理解一下
// 都是需要移动两次搬动所有的数据
//

class Solution {
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()){
            while(!stack1.empty())
                stack2.push(stack1.top()); stack1.pop();
        }
        int a = stack2.top(); stack2.pop();
        return a;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(){
    
    return 0;
}
