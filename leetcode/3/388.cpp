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

// 不想做了
class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> path;
        int l = 0;
        int r = 0;
        int size = input.size();
        int res = 0;

        // 所有字符全部都是从使用\n分割开始
        while(r < size){
            while(input[r] != '\n') r ++;
            int size = r - l;
            int tab = 0;
            while(input[l] == '\t'){
                tab ++;
                l ++;
            }

            // 调整stack
            while(path.size() > tab) path.pop_back();

            // 计算长度
            int len = 0;
            for(int i: path){
                len += 1 + i;
            }
            res = max(res, len + size);

            l = r + 1;
        }
        return res;
    }
};
int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    string s = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
        Solution sol;
    sol.lengthLongestPath(s);
    cout << s.size();
    return 0;
}
