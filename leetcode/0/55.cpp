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

    bool canJump(vector<int>& nums) {
        if(!nums.size()) return true;

        int range = 0;
        int i = 0;
        int last = nums.size() - 1;
        while(i <= range){
            range = max(range, i + nums[i]);
            if(range >= last){ return true; }
            i ++;
        }

        return false;
    }
};
int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    return 0;
}
