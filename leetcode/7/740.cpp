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
 * 1. sort
 * 2. 背包问题
 *  1. 记录下所有消耗量下对应的收割量
 *
 * 查找到数值中间到达最后的位置，
 * 将数值聚集起来，当处理的时候，所以就是house robber 类似的
 */
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        std::vector<pair<int, int> > vec ;
        vec.push_back(make_pair(nums[0], 1));

        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] == vec.back().first){
                vec.back().second ++;
            }else{
                vec.push_back(make_pair(nums[i], 1));
            }
        }

        int A = 0; // 不使用
        int B = vec[0].first * vec[0].second; // 使用
        int last = vec[0].first;

        for (int i = 1; i < vec.size(); i++) {
            if(last + 1 !=  vec[i].first){
                A = max(A, B);
            }

            int a = max(A, B);
            int b = A + vec[i].first * vec[i].second;
            A = a;
            B = b;

            last = vec[i].first;
        }
        

        return max(A, B);
    }
};

int main(){
    REOPEN_READ
    vector<int> vec;
    int d;
    while(scanf("%d", &d) == 1){
        vec.push_back(d);
    }
    
    Solution s;
    cout <<  s.deleteAndEarn(vec);
    
    return 0;
}
