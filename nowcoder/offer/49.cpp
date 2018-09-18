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

/**
 *
 * 只有一个问题，长度是否相同的问题发
 *
 * 暴力
 */
class Solution {
public:
    char * str;
    char * pattern;

    bool match(int a, int b){
        if(str[a] == '\0' && str[b] == '\0') return true;

        if(str[a] == '\0'){

        }
    }

    bool match(char* str, char* pattern){
        this->str = str;
        this->pattern = pattern;

        return match(0, 0);
    }
};
int main(){
    
    return 0;
}
