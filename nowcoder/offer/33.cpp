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
    

    int FirstNotRepeatingChar(string str) {
        int a[26];
        int A[26];
        memset(a, 0, sizeof(int) * 26);
        memset(A, 0, sizeof(int) * 26);

        if(str.empty()) return -1;

        for(char c : str){
            if(c >= 'a' && c <= 'z'){
                a[c - 'a'] ++;
            }else{
                A[c - 'A'] ++;
            }
        }

        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            if(c >= 'a' && c <= 'z'){
                if(a[c - 'a'] == 1) return i;
            }else{
                if(A[c - 'A'] == 1) return i;
            }
        }

        return -1;
    }
};

int main(){
    
    return 0;
}
