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
 * push : 
 * when ] pop the util [ and get the number 
 */

class NumStr{
public:
    int a;
    int b;
    int c;
    NumStr(int a, int b, int c):a(a), b(b), c(c){}
};

class Solution {
public:
    string get(string & s, int l, int r){
        // cout << "fuck " << s.substr(l + 1, r- l + 1) << endl;
        int L;
        int O = 0;
        int N = -1;
        
        vector<NumStr> P;
        for (int i = l + 1; i < r; i++) {
            if(s[i] == '['){
                if(O == 0){
                    L = i;
                }
                O ++;
            }else if(s[i]  == ']'){
                if(O == 1){
                    P.push_back(NumStr(N, L, i));
                    N = -1;
                }
                O --;
            }else if(isdigit(s[i])){
                if(N == -1){
                    N = i;
                }
            }
        }

        if(P.empty()){
            string k = s.substr(l + 1, r - l - 1);
            // cout << "k" <<  k << endl;
            return k;
        }

        int cur = l + 1;
        string res;
        for(auto p : P){
            // printf("%d %d %d %d\n",p.a, p.b , p.c, cur);
            if(p.a != cur){
                res += s.substr(cur, p.a - cur);
            }
            int num = stoi(s.substr(p.a, p.b - p.a));
            // printf("num = %d \n", num);
            string ts = get(s, p.b, p.c);
            for (int i = 0; i < num; i++) {
                res += ts;
            }

            cur = p.c + 1;
        }

        if(cur != r) res += s.substr(cur, r - cur);

        // printf("res = [%s]\n", res.c_str());
        return res;
    }

    // 原来还可以不包含数值
    string decodeString(string s) {
        return get(s, -1, s.size());
    }
};

int main(){

    Solution s;
    string str = "3[a2[c]]";
    cout << s.decodeString(str) << endl;

    return 0;
}
