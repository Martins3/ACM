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
#include <bitset>
#include "../info.hpp"

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

class Solution {
public:
    vector<vector<int> > res;
    bitset<30> b;
    int L;

    void handle(vector<int> & nums, int index){
        if(index == L){
            // cout <<  b << endl;
            vector<int> v;
            for (int i = 0; i < L; i++) {
                if(b[i]){
                    v.push_back(nums[i]);
                }
            }
            res.push_back(v);
            return;
        }
        handle(nums, index + 1);
        b.set(index);
        handle(nums, index + 1);
        b.reset(index);
    }

    
    vector<vector<int>> subsets(vector<int>& nums) {
        L = nums.size();
        handle(nums, 0);
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int> > a;
    vector<int> v{1, 2, 3};
    a = s.subsets(v);
    for(auto s : a){
        print_v(s);
    }
    
    return 0;
}
