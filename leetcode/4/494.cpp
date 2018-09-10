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

class Solution {
public:
    map<int, int> left;
    map<int,int > right;

    void sta(int x, int y, int sum, vector<int> & V, map<int, int> & M){
        if(x == y){
            // add to map
            auto f = M.find(sum);
            if(f == M.end())
                M[sum] = 1;
            else
                M[sum] ++;
        }else{
            sta(x + 1, y, sum + V[x], V, M);
            sta(x + 1, y, sum - V[x], V, M);
        }
    }

    // [x, y)
    void handle(int x, int y, vector<int> & V, map<int, int> & M){
        sta(x, y, 0, V, M);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0) return  0;
        if(nums.size() == 1) return nums[0] == S | nums[0] == -S ? 1 : 0;

        handle(0, nums.size() / 2, nums, left);
        handle(nums.size() / 2, nums.size(), nums, right);

        int sum  = 0;

        for(auto i = left.begin(); i != left.end(); i++){
            for(auto j = right.begin(); j != right.end(); j++){
                printf("%d %d %d %d\n",i->first, i->second, j->first, j->second);
                if(i->first + j->first == S) sum += i->second * j->second;
            }
        }
        return sum;
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
    int S = 3;
    cout << s.findTargetSumWays(vec, S);
    return 0;
}
