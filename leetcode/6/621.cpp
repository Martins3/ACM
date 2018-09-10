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

/**
 * 原则:
 * 1. 空出来的位置添加到，但是对于下一个会产生干扰
 * 如果空缺数量不够，似乎对于多出来的会造成危险，但是并不是如此，
 */

class Solution {
public:
    // 统计数量
    // 尽可能的分散开来
    int num[26];
    priority_queue<int, vector<int>, greater<int> > min_heap;


    int leastInterval(vector<char>& tasks, int n) {
        for(int i = 0; i < 26; i++) num[i] = 0;
        for(int i = 0; i < tasks.size(); i++){
            num[tasks[i] - 'A'] ++;
        }

        sort(num, num + 26);

        int res = 0;
        for (int i = 0; i < 26; i++) {
            if(!num[i]) break;

        }

        return res;
    }
};

int main(){

    REOPEN_READ
    vector<char> vec;
    int d;
    while(scanf("%d", &d) == 1){
        vec.push_back(d);
    }

    Solution s;
    int n = 0;
    cout << s.leastInterval(vec, n);

    return 0;
}
