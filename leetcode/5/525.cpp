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
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, vector<int> > m;
        int sum = 0;
        m[sum] = vector<int>{-1};

        for (int i = 0; i < nums.size(); i++) {
            int s = nums[i]; 
            sum += ((s == 1) ? 1 : - 1);
            auto f = m.find(sum);
            if(f == m.end()){
                m[sum] = vector<int>{i};
            }else{
                m[sum].push_back(i);
            }
        }

        int res = 0;
        for(auto v : m){
            if(v.second.size() > 1){
                res = max(res, v.second.back() - v.second.front());
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    REOPEN_READ
    vector<int> vec;
    int d;
    while(scanf("%d", &d) == 1){
        vec.push_back(d);
    }
    cout << s.findMaxLength(vec);
    return 0;
}
