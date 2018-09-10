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

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

class Solution {
public:

    int jumpFloor(int number) {
        vector<int> dp(number + 1);
        dp[1] = 1;
        dp[0] = 1;
        for (int i = 2; i <= number; ++i) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[number];
    }
};

int main(){
    Solution s;
    cout << s.jumpFloor(10);
    
    return 0;
}
