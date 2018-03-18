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

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

#define maxn 1000
class Solution {
public:
    pair<long, long> digits[maxn]; 
    int how_many_two(int x){
        int res = 0;
        while(x % 2 == 0 && x != 0){
            res ++;
            x = x / 2; 
        }
        return res;
    }

    int how_many_five(int x){
        int res = 0;
        while(x % 5 == 0 && x != 0){
            res ++;
            x = x / 5; 
        }
        return res; 
    }

    void add(pair<long, long> & a, const pair<long,long> & b){
        a.first += b.first;
        a.second += b.second;
    }

    int preimageSizeFZF(int K) {
        for(int i = 1; i < maxn; i++){
            digits[i].first = 0;
            digits[i].second = 0;

            pair<int, int> a = make_pair(how_many_two(i), how_many_five(i));
            add(digits[i], a);
            if(i == 0) continue;
            add(digits[i], digits[i - 1]);
        }        
        printf("%ld\n", min(digits[maxn - 1].first, digits[maxn - 1].second));
        return 0;
    }
};

int main(){
    Solution s;
    s.preimageSizeFZF(1);
    return 0;
}