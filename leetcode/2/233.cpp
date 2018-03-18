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

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

#define lld long long int

class Solution {
public:
    // 数值个数
    lld fix[10];

    lld nums(lld n){
        lld total = (lld)(pow(10, n - 1)) * 9;
        lld invalid = (lld)(pow(9, n - 1)) * 8;
        return total - invalid;
    }

    // 7361890
    // 2
    lld countDigitOne(lld n) {
        if(n <= 0) return 0;

        for(int i = 1; i <= 9; i++){ fix[i] = nums(i); } 
        fix[0] = 0;

        string s = to_string(n);

        int res = 0;
        int size = s.size();
        for(int i = 0; i < size; i++){
            // 包含当前， 并且当前为最高位的所有数值

            for(int j = 0; j <= s[i] - '0'; j++){
                if(j == 1){
                    res += (int)pow(10, size - 1 - i);
                }else{
                    res += fix[size - 1 - i];
                }
            }

        } 
    }
};
int main(){
    REOPEN_READ
    // REOPEN_WRITE

    return 0;
}