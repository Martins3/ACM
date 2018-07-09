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

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/OnlineJudge/output.txt", "w", stdout);

class Solution {
public:
    int process(int n){
        int res = 0;
        while(n){
            res += (n % 10) * (n % 10);
            n = n / 10;
        }
        return res;
    }

    bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);
        while(true){
            n =  process(n);
            cout << n << endl;
            if(n == 1) return true;
            auto f = s.find(n);
            if(f != s.end()){
                return false;
            }
            s.insert(n);
        }
        return false;
    }
};

int main(){
    Solution s;
    cout << s.isHappy(2);
    

    return 0;
}
