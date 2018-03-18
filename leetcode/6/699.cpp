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

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

// 离散化

// make_tree

// 维护最大值



class Solution {
public:
    vector<int> nums;

    void hash(vector<pair<int, int>>& positions){
        for(auto p: positions){
            nums.push_back(p.first);
            nums.push_back(p.second + p.first);
        }
        
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end() ), nums.end() );
    }
    
    int getHugeNum(int x){
        return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
    }

    int getHashNums(int x){
        return nums[x];
    }

    
    

    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        
    }
};
int main(){
    REOPEN_READ
    REOPEN_WRITE

    return 0;
}