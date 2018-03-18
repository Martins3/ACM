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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        priority_queue<int> p;
        priority_queue<int, vector<int>, greater<int> > q;
        vector<int> res;

        sort(nums.begin(), nums.begin() + k);

        // 使用右侧
        for(int i = 0; i < (k + 1) / 2 ; i++){
            p.push(nums[i]);
        }

        for(int i = (k + 1) / 2; i < k ; i++){
            q.push(nums[i]);
        }
        
        // 如何移动数据
        for(int i = 0; i < 100; i++){

        }
    }
};

int main(){
    REOPEN_READ
    REOPEN_WRITE

    return 0;
}