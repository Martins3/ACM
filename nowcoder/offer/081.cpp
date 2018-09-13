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

// 3 4
class Solution {
public:
    int jumpFloorII(int number) {
        if(number == 0) return 0;
        vector<int> v(number + 1, 0);
        v[1] = 1;
        v[0] = 1;

        for (int i = 2; i <= number; i++) {
            for (int j = 0; j < i; j++) {
                v[i] += v[j];
            }
        }

        return v[number];
    }
};

int main(){
    Solution s;
    cout << s.jumpFloorII(3);
    return 0;
}
