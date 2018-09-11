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
    int FindGreatestSumOfSubArray(vector<int> array) {

        // 初始值的设置
        int sum = 0;
        int res = INT_MIN;

        for (int i = 0; i < array.size(); i++) {
            sum += array[i];
            res = max(res, sum);

            if(sum < 0) sum = 0;
        }

        return res;
    }
};

int main(){
    
    return 0;
}
