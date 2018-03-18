#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <forward_list>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

#define maxn 200
class Solution {
public:
    /**
     * 使用stack 维护
     * 1. 如果比较的小， 而且可以删除， 那么持续下沉
     * 2. stack pop 的时候 计数 减去一
     * 3. 
     * 
     * 正确性 证明： 贪心
     */
    string removeDuplicateLetters(string s) {

        int counter[maxn];
        memset(counter, 0, sizeof(counter));
        for(char c : s){
            counter[c] ++;
        }

        stack<int> uni;

        bool in_stack[maxn];
        memset(in_stack, 0, sizeof(in_stack));

        for(char c: s){
            // 如果已经在stack 中间， 直接删除
            if(in_stack[c]){
                counter[c] --;
                continue;
            }

            while(!uni.empty() && uni.top() > c && counter[uni.top()] > 1){
                counter[uni.top()] --;
                in_stack[uni.top()] = false;
                uni.pop();
            }
            uni.push(c);
            in_stack[uni.top()] = true;
        }

        string res(uni.size(), 0);
        int len = uni.size();
        for(int i = len - 1; i >= 0; i--){
            res[i] = uni.top();
            uni.pop();
        } 
        return res;
    }
};


int main(){
    REOPEN_READ
    //REOPEN_WRITE
    Solution s;
    cout << s.removeDuplicateLetters("321321");
    return 0;
}