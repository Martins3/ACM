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
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

/**
 *统计所有位置上面的１的个数
 */

class Solution {
public:
    int counter[32];
    int singleNumber(vector<int>& nums) {
        for (int i = 0; i < 32; ++i) {
            counter[i] = 0;
        }
        for (int i = 0; i < nums.size(); ++i) {
           for (int j = 0; j < 32; j++) {
                if(nums[i] & (1 << j)) counter[j] ++;
           }
        }

        int res = 0;
        for (int i = 0; i < 32; ++i) {
           counter[i] = counter[i] % 3;
           if(counter[i]){
               res = res | (1 << i);
           }
        }

        return res;
    }
};

int main(int argc, char *argv[]){
    Solution s;
    vector<int> vec{137, 137, 137, 899};
    cout << s.singleNumber(vec);
    return 0;
}
