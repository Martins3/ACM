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
    bool isPerfectSquare(int num) {
        if(num == 0) return true;
        if(num == 1) return true;
        // binay search
        int right = 1;
        while(right * right < num){
            right *= 2;
        }        

        int left = right; 
        int middle = left + (right - left) / 2;
        // 有没有等于号

        // 如果没有搜索到， 如何处理的
        while(left < right){
            int sqrt_num = middle * middle;
            if(sqrt_num > num){
                left = middle;
            }else if(sqrt_num < num){
                right = middle;
            }else{
                // find it !
                break;
            }
            
            middle = left + (right - left) / 2;
        }
    }
};

int main(){
    REOPEN_READ
    //REOPEN_WRITE

    return 0;
}