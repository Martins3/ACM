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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

class Solution {
public:
    int num[26];
    priority_queue<int, vector<int>, greater<int> > min_heap;
    void init(){
        for(int i = 0; i < 26; i++) num[i] = 0;
    }

    int leastInterval(vector<char>& tasks, int n) {
        init();
        for(int i = 0; i < tasks.size(); i++){
            num[tasks[i] - 'A'] ++;
        }
        // 逐个分析对应的元素，实现处理所有
        for (int i = 0; i < 26; ++i) {
            min_heap.push(num[i]);
        }

        // 小于　如果大于，使用
    }
};

int main(){
    REOPEN_READ
    //REOPEN_WRITE

    return 0;
}
