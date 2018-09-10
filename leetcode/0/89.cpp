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
#include "../info.hpp"

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

/**
 * 000
 * 001
 *
 * 011
 * 010
 *
 *
 * 111
 * 110
 *
 */
class Solution {
public:


    vector<int> grayCode(int n) {
        vector<int> res(1 << n, 0);
        for (int i = 0; i < n; i++) {
            int t = 1 << i;
            for (int j = 0; j < t; j++) {
                res[t + j] = res[t - 1 - j] | t;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    s.grayCode(3);

    
    return 0;
}
