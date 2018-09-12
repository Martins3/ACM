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
    bool isUgly(int num) {
        if(num == 0) return false;

        while(num != 1){
            if(!(num % 2)){ num = num / 2; continue;}
            if(!(num % 3)){ num = num / 3; continue;}
            if(!(num % 5)){ num = num / 5; continue;}
            return false;
        }

        return true;
    }
};

int main(){
    
    return 0;
}
