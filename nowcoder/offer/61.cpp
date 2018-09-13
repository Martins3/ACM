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


/**
 * 虽然采用的是双端队列，但是其中包含有重要的策略
 * 当一个元素进入到deque中间的时候，需要清除所有小于的数值
 */
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size){
        vector<int> res;
        if(num.size() <= size) return res;

        deque<int> dq;
        for (int i = 0; i < size; i++) {
            while(!dq.empty() && dq.back() < num[i]) dq.pop_back();
            dq.push_back(num[i]);
        }
        res.push_back(dq.front());

        for (int i = size; i < num.size(); i++) {
            if(num[i - size] == dq.front()){
                dq.pop_front();
            }

            while(!dq.empty() && dq.back() < num[i]) dq.pop_back();
            dq.push_back(num[i]);

            res.push_back(dq.front());
        }

        return res;
    }
};

int main(){
    
    return 0;
}
