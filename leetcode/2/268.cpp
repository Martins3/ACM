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

typedef long long int LLD;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        LLD sum = nums.size() * (nums.size() + 1) / 2;
        for (int i = 0; i < nums.size(); i++) {
            sum -= nums[i];
        }
        return sum;
    }
};
int main(){
//    REOPEN_READ
//   REOPEN_WRITE


    return 0;
}
