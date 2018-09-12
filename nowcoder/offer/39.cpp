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
    // 两者至少含有一位不同的
    // 将该位不同划分两者
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int s = 0;
        for(auto i : data){
            s = s ^ i;
        }

        int i = 0;
        while(!(s & (1 << i))) i ++;
        int t = 1 << i;

        *num1 = 0;
        *num2 = 0;
        for(auto i : data){
            if(t & i)
                *num1 = *num1 ^ i;
            else
                *num2 = *num2 ^ i;
        }
    }

};

int main(){
    
    return 0;
}
