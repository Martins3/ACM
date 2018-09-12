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
    int Add(int num1, int num2){
        bool A[32];
        bool B[32];

        bool C[32];

        vector<int> In{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
        // vector<int> In{31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0}


        for(auto i : In){
            A[i] = num1 & (1 << i);
        }

        for(auto i : In){
            B[i] = num2 & (1 << i);
        }

        bool carry = false;
        for(auto i : In){
            C[i] = A[i] ^ B[i] ^ carry;

            if(A[i] && B[i]){
                carry = true;
                continue;
            }

            if(A[i] || B[i]){
                if(carry){
                    carry = true;
                    continue;
                }
            }

            carry = false;
        }

        int res = 0;
        for(auto i : In){
            if(C[i]){
                res = res | (1 << i);
            }
        }

        return res;
    }
};
int main(){
    Solution s;
    cout << s.Add(123, 456);
    
    
    return 0;
}
