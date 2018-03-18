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
    /**
     * A + B
     * B + A
     *
     */
    bool rotateString(string A, string B) {
        if(A.size() != B.size()) return false;
        if(A.size() == 0) return true;        
        if(A.size() == 1){
            if(A == B) return true;
            return false;
        }

        // 暴力
    }
};
int main(){
    REOPEN_READ
    //REOPEN_WRITE

    return 0;
}