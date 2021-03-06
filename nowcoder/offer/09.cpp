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

class Solution {
public:
    int rectCover(int number) {
        if(number == 0) return 0;
        // 横竖
        vector<int> H(number + 1, 0);
        vector<int> S(number + 1, 0);

        H[1] = 1;
        S[0] = 1;

        for (int i = 2; i <= number; i++) {
            H[i] = H[i - 1] + S[i - 1];
            S[i] = S[i - 2] + H[i - 2]; 
        }

        return H[number] + S[number];
    }
};


int main(){
    return 0;
}
