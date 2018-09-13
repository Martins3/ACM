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
 * 1. 采用优先队列
 * 2. 维持右侧的数值始终大于左边
 * 3. 首先确定一定需要添加的数值
 *
 * 4. 计算TOP 的时候首先分析时候含有正确的数值
 *
 */
class Solution {
public:
    std::priority_queue<int, std::vector<int>> L;
    std::priority_queue<int, std::vector<int>, std::greater<int> >  R;

    void Insert(int num){
        if(R.empty()){
            R.push(num);
        }else{
            if(num >= R.top()) R.push(num);
            if(num < R.top()) L.push(num);
        }

        if(R.size() > L.size() - 1){
            L.push(R.top());
            R.pop();
        }

        if(R.size() < L.size()){
            R.push(L.top());
            L.pop();
        }
    }

    double GetMedian(){ 
        if(R.size() > L.size()){
            return R.top();
        }else{
            return (R.top() + L.top()) / 2.0;
        }
    }
};

int main(){
    
    return 0;
}
