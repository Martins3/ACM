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



class Solution {
public:
     int  NumberOf1(int n) {
         int res = 0;
         if(n < 0){
             n = n & 0x7fffffff;
             res ++;
         } 

        while(n){
            if(n & 1) res ++;
            n = n >> 1;
        }
        return res;
     }
};

int main(){
    Solution s;
    cout << s.NumberOf1(-1);
    
    return 0;
}
