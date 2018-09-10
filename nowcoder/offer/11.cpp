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
    double Power(double base, int exponent) {
        if(base == 0) return 0;
        double sum = 1;
        
        if(exponent == 0) return 1;
        if(exponent < 0){
            exponent = -exponent;
            base = 1 / base;
        }

        while(exponent --){
            sum *= base;
        }
        return sum;
    }
};

int main(){
    
    return 0;
}
