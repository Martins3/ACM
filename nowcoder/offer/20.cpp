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

    // inc
    bool order(vector<int> & P, int a, int b,  vector<int> & V, int x, int y) {
        if(a > b) return true; // 可以作为唯一的手段

        // start point
        // end point
        int M = -1;
        for (int i = x; i <= y ; i++) {
            if(P[a] == V[i]) M = i;
        }

        if(M == -1) return false;

        if(!order(P, a + 1, M - x + a, V, x, M - 1)) return false;
        if(!order(P, M - x + a + 1, b, V, M + 1, y)) return false;

        return true;
    }
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() == 0) return true;
        return order(pushV, 0, pushV.size() - 1, popV, 0, popV.size() - 1);
    }
};

int main(){

    return 0;
}
