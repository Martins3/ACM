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
 * 1. 对于数值非常大的情况的处理
 * 3. 算法错误: 直接跟踪结果
 *
 * 居然是使用GCD
 * 1. 如果不是gcd(x, y) 显然是没有办法得到正确的数值的
 * 2. 当两个数值互质，可以得到任何数值
 * 
 * 由于1 = ax + by
 * 那么 z = azx + bzy
 *
 * 接下来需要证明就是指定数量 : 一定含有这样的路径吗 ?
 *
 */ 

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        queue<int> Q;
        set<int> visited;

        Q.push(0);
        visited.insert(0);

        while(!Q.empty()){
            int len = Q.size();
            for (int i = 0; i < len; i++) {
                // 访问
                
                int n = Q.front(); Q.pop();
                if(n == z) return true;

                vector<int> candidates;
                if (n + x <= x + y)
                    candidates.push_back(n + x);
                if (n + y <= x + y)
                    candidates.push_back(n + y);
                if (n - x >= 0)
                    candidates.push_back(n - x);
                if (n - y >= 0)
                    candidates.push_back(n - y);


                for(auto a : candidates){
                    auto f = visited.find(a);
                    if(f == visited.end()){
                        visited.insert(a);
                        Q.push(a);
                    }
                }
            }
            
        }
        return false;
    }
};

int main(){
    Solution s;

    cout << s.canMeasureWater(104693,104701,324244);
    return 0;
}
