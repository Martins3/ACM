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
#include "../info.hpp"

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/OnlineJudge/output.txt", "w", stdout);

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        int depth = triangle.size();
        vector<int> * minValue = new vector<int>();
        vector<int> * cur = new vector<int>();

        minValue->push_back(triangle[0][0]);
        for (int i = 1; i < depth; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                int l = INT_MAX;
                int r = INT_MAX;
                if(j > 0) l =  (*minValue)[j - 1];
                if(j < i) r =  (*minValue)[j];
                int m = min(l, r) + triangle[i][j];

                if(j < cur->size())
                    (*cur)[j] = m;
                else
                    cur->push_back(m);
            }
            print_v(*cur);

            vector<int> * t = minValue;
            minValue = cur;
            cur = t;
        }

        int res = INT_MAX;
        for (unsigned i = 0; i < minValue->size(); ++i) {
            res = min(res, (*minValue)[i]);
        }
        return res;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    vector<vector<int> > v;
    v.push_back(vector<int>{2});
    v.push_back(vector<int>{3, 4});
    v.push_back(vector<int>{6, 5, 7});
    v.push_back(vector<int>{4, 1, 8, 3});
    cout << s.minimumTotal(v);
    return 0;
}
