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
    int longestMountain(vector<int>& A) {
        if(A.size() <= 2) return 0;
        int last  = -1;
        int res = 0;
        if(A[1] > A[0]) last = 0;
        for (int i = 1; i < A.size() - 1; ++i) {
            if(A[i] < A[i - 1] && A[i] < A[i + 1]){
                if(last == -1){
                    last = i;
                }else{
                    res = max(res, i - last  + 1);
                }
            }
        }

        // 7
        if(last != -1){
            if(A[A.size() - 1] < A[A.size() - 2])
                res = max(res, (int)(A.size() - 1 - last  + 1));
        }

        return res;
    }
};
int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    return 0;
}
