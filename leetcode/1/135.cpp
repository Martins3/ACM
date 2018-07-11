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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/OnlineJudge/output.txt", "w", stdout);

class Solution {
public:

    void dfs(vector<vector<int> > & edges,  vector<int> & nums, int i){
        if(nums[i]) return;
        int num = 0;
        for(int w : edges[i]){
            dfs(edges, nums, w);
            num = max(num, nums[w]);
        }
        nums[i] = num + 1;
    }

    int candy(vector<int>& ratings) {
        int nodeNum = ratings.size();
        vector<vector<int> > edges(nodeNum, vector<int>());

        // make graph
        for (int i = 0; i < nodeNum - 1; ++i) {
            if(ratings[i] > ratings[i + 1]) edges[i].push_back(i + 1);
            if(ratings[i] < ratings[i + 1]) edges[i + 1].push_back(i);
        }

        vector<int> nums(nodeNum, 0);
        for (int i = 0; i < nodeNum; ++i) {
            if(!nums[i]) dfs(edges, nums, i);
        }

        int res = 0;
        for(int i : nums){
            res += i;
        }

        return res;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    vector<int> v{1, 0, 2};
    cout << s.candy(v);
    return 0;
}
