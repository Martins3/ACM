#include "../../leetcode/info.hpp"
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
    
    vector<int> multiply(const vector<int>& A) {
        vector<int> l(A.size(), 1);
        vector<int> r(A.size(), 1);

        for (int i = 0; i < A.size(); i++) {
            if(i == 0)
                l[i] = A[i];
            else
                l[i] = l[i - 1] * A[i];
        }

        for (int i = A.size() - 1; i >= 0; i--) {
            if(i == A.size() - 1)
                r[i] = A[i];
            else
                r[i] = r[i + 1] * A[i];
        }

        // go on
        print_v(l);
        print_v(r);
        
        vector<int> res(A.size());
        for (int i = 0; i < A.size(); i++) {
            int left;
            int right;

            if(i - 1 < 0)
                left = 1;
            else
                left = l[i - 1];

            if(i + 1 > A.size() - 1)
                right = 1;
            else
                right = r[i + 1];

            res[i] = left * right;
        }

        return res;
    }
};

int main(){

    REOPEN_READ
    vector<int> vec;
    int d;
    while(scanf("%d", &d) == 1){
        vec.push_back(d);
    }

    Solution s;
    print_v(s.multiply(vec));
    return 0;
}
