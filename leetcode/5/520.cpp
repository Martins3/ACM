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
    bool detectCapitalUse(string word) {
        if(word.size() <= 1) return true;
        
        int f = isupper(word[0]);
        word = word.substr(1, word.size() - 1);
        unsigned int upper = 0;
        for(char c: word){
            if(isupper(c)){
                upper ++;
            } 
        }
        if(f){
            if(upper == 0 || upper == word.size()) return true;
            return false;
        }

        if(upper == 0) return true;
        return false; 
    }
};
int main(){
    REOPEN_READ
    //REOPEN_WRITE

    return 0;
}
/**
 * erro log:
 * 分析错误 !
 */