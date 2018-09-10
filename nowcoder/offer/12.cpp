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

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

struct Cmp{
    inline bool operator ()(const int a, const int b){
        int A = a % 2 ? 1 : 0;
        int B = b % 2 ? 1 : 0;
        return A > B;
    }
};

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        sort(array.begin(), array.end(), Cmp());
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
    s.reOrderArray(vec);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    
    
    return 0;
}
