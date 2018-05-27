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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

/**
 * negtive
 */
class Solution {
public:

    int getHighestOne(int num){
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if(num >> i) res = max(res, i);
        }
        return res;
    }
    int findIntegers(int num) {
        // find all the data
        vector<int> A(31, 0); // with one
        vector<int> B(31, 0); // with zero
        for (int i = 0; i < 31; ++i) {
            if(i == 0){
                A[i] = 1;
                continue;
            }

            A[i] = B[i - 1];
            B[i] = A[i - 1] + B[i - 1];
        }

        // find the ans
        int res = 0;

        // find bit length less than
        int h = getHighestOne(num);
        for (int i = 0; i < h; ++i) {
            res += A[i];
        }

        // find the length same, just care about
        return res;
    }
};
int main(int argc, char *argv[]){
    REOPEN_READ
    REOPEN_WRITE

    return 0;
}
