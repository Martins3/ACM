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
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty()) return false;
        sort(numbers.begin(), numbers.end());

        int off = 0;
        while(off < numbers.size() && numbers[off] == 0 ) off ++;
        
        
        int reck = 0;
        if(off + 1 >= numbers.size()) return true;
        int last = numbers[off];


        for (int i = off + 1; i < numbers.size(); i++) {
            reck += (numbers[i] - last - 1);
            if(numbers[i] == last) return false;
            last =  numbers[i];
        }

        printf("%s %d %d\n", " aaaa", reck, off);

        if(reck > off) return false;

        return true;
    }
};
int main(){
    REOPEN_READ
    vector<int> vec;
    int d;
    while(scanf("%d", &d) == 1){
        vec.push_back(d);
    }
    Solution s;
    cout << s.IsContinuous(vec);
    
    
    return 0;
}
