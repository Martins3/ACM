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

typedef long long int lld;

class Solution {
public:
    int F[40];
    int Fibonacci(int n) {
        F[0] = 0;
        F[1] = 1;
        for (int i = 2; i <= 39; i++) {
            F[i] = F[i - 1] + F[i - 2];
        }
        return F[n];
    }
};

int main(){
    Solution s;
    cout << s.Fibonacci(1);
    return 0;
}
