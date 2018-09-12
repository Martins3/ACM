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

    int Sum_Solution(int n) {
        int A = n;
        int B = n + 1;

        int Sum = 0;
        Sum += ((A &(1 << 0))) * B;
        Sum += ((A &(1 << 1))) * B;
        Sum += ((A &(1 << 2))) * B;
        Sum += ((A &(1 << 3))) * B;
        Sum += ((A &(1 << 4))) * B;
        Sum += ((A &(1 << 5))) * B;
        Sum += ((A &(1 << 6))) * B;
        Sum += ((A &(1 << 7))) * B;
        Sum += ((A &(1 << 8))) * B;
        Sum += ((A &(1 << 9))) * B;
        Sum += ((A &(1 << 10))) * B;
        Sum += ((A &(1 << 11))) * B;
        Sum += ((A &(1 << 12))) * B;
        Sum += ((A &(1 << 13))) * B;
        Sum += ((A &(1 << 14))) * B;
        Sum += ((A &(1 << 15))) * B;
        Sum += ((A &(1 << 16))) * B;
        Sum += ((A &(1 << 17))) * B;
        Sum += ((A &(1 << 18))) * B;
        Sum += ((A &(1 << 19))) * B;
        Sum += ((A &(1 << 20))) * B;
        Sum += ((A &(1 << 21))) * B;
        Sum += ((A &(1 << 22))) * B;
        Sum += ((A &(1 << 23))) * B;
        Sum += ((A &(1 << 24))) * B;
        Sum += ((A &(1 << 25))) * B;
        Sum += ((A &(1 << 26))) * B;
        Sum += ((A &(1 << 27))) * B;
        Sum += ((A &(1 << 28))) * B;
        Sum += ((A &(1 << 29))) * B;
        Sum += ((A &(1 << 30))) * B;
        Sum += ((A &(1 << 31))) * B;

        return Sum >> 1;
    }
};

int main(){
    // for (int i = 0; i < 32; i++) {
        // printf("Sum += (A &(1 << %d)) * B;\n", i);
    // }
    
    return 0;
}
