#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <forward_list>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

class Solution {
public:
    int countSegments(string s) {
        bool in_space = true;
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            if(!isspace(s[i]) && in_space){
                res ++;
                in_space = false;
            }else if(!in_space && isspace(s[i])){
                in_space = true;
            }
        }        
        return res;
    }
};

int main(){
    REOPEN_READ
    //REOPEN_WRITE
    Solution s;
    cout << s.countSegments(" a    a      a        a    ");
    return 0;
}