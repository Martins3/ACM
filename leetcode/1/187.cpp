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
    map<int, int> m;

    int a(string & s, int off){
        int R = 0;
        for (int i = off; i < 10 + off; i++) {
            int k = i - off;
            switch (s[i]) {
                case 'A':
                    R = R | (1 << (2 * k));
                    R = R | (1 << (2 * k + 1));
                    break;
                case 'C':
                    // R = R | (1 << (2 * i));
                    R = R | (1 << (2 * k + 1));
                    break;
                case 'G':
                    R = R | (1 << (2 * k));
                    // R = R | (1 << (2 * i + 1));
                    break;
                case 'T':
                    // R = R | (1 << (2 * i));
                    // R = R | (1 << (2 * i + 1));
                    break;
                default:
                    printf("%s\n", "Impossible");
            }
        }
        return R;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        vector<int> R;
        for (int i = 0; i <= (int)s.size() - 10; i++) {
            int n = a(s, i);
            auto s = m.find(n);
            if(s != m.end()){
                if(s->second != -1){
                    R.push_back(i);
                    s->second = -1;
                }
            }else{
                m[n] = i;
            }
        }


        vector<string> v;
        
        for(auto i : R){
            v.push_back(s.substr(i, 10));
        }
        return v;
    }
};

int main(){
    Solution s;
    auto k = s.findRepeatedDnaSequences("AAAAAAAAAAAA");
    for(auto m : k){
        cout << m << endl;
    }
    return 0;
}
