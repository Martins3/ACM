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

    // 无论占据在哪一个位置，结果总是左边小
    bool verify(vector<int> & sequence, int a, int b) {
        printf("%d %d \n",a, b);
        if(a + 1 >= b) return true;
        int flag = sequence[b];

        int i = a;
        int j = b - 1;
        while(sequence[i] < flag && i < b) i ++;
        if(i == b) return true;
        while(sequence[j] > flag && j >= a) j --;
        if(j == a - 1) return true;

        if(j + 1 != i) return false;

        // j  i
        return verify(sequence, a, j) && verify(sequence, i, b - 1);
    }



    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        return verify(sequence, 0, sequence.size() - 1);
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
    cout << s.VerifySquenceOfBST(vec);

    
    return 0;
}
