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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/OnlineJudge/output.txt", "w", stdout);

class Solution {
public:
    bool is_vowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    void change(string & word){
        if(!is_vowel(word[0])){
            word.push_back(word[0]);
            word.erase(0, 1);
        }
        word += "ma";
    }

    string toGoatLatin(string S) {
        string res;
        stringstream iss(S);

        string append = "a";
        string word;
        while(iss >> word){
            change(word);
            word += append;
            res += word;
            res += " ";
            append.push_back('a');
        }
        res.pop_back();
        return res;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    cout << s.toGoatLatin("I speak Goat Latin");
    return 0;
}
