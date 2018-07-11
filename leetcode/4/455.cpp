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

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int res = 0;
        vector<int>::iterator pos_find = s.begin();
        for(int i : g){
            pos_find = std::lower_bound(pos_find, s.end(), i);
            if(pos_find == s.end()){
                break;
            }else{
                pos_find ++;
                res ++;
            }
        }
        return res;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    vector<int> a{1, 2, 3};
    vector<int> b{1, 1};
    cout << s.findContentChildren(a, b);
    return 0;
}
