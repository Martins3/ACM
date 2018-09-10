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


    bool isValid(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int a = p1[0] - p2[0];
        int b = p1[1] - p2[1];
        int c = p3[0] - p4[0];
        int d = p3[1] - p4[1];

        int E = a * a + b * b;
        int F = c * c + d * d;

        if(E == 0 || F == 0) return false;

        int A = p1[0] + p2[0];
        int B = p1[1] + p2[1];
        int C = p3[0] + p4[0];
        int D = p3[1] + p4[1];
        if(A != C || B != D) return false;



        if(E == F && a * c + b * d == 0) return true; 

        return false;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(isValid(p1, p2, p3, p4)) return true;
        if(isValid(p1, p3, p2, p4)) return true;
        if(isValid(p1, p4, p2, p3)) return true;
        return false;
    }
};
int main(){
    
    return 0;
}
