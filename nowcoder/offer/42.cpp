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
    string ReverseSentence(string str) {
        int i = str.size() - 1;
        int j = str.size() - 1;
        string res;


        while(j >= 0){
            if(str[j] != ' '){
                while(str[j] != ' ' && j >= 0) j --;
            }else{
                while(str[j] == ' ' && j >= 0) j --;
            }
            j ++;
            // printf("%d %d\n",j , i );
            res += str.substr(j, i - j + 1);

            i = --j;
        }

        return res;
    }
};
int main(){
    Solution s;
    cout << s.ReverseSentence("I   am a student.");

    return 0;
}
