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


//
// 50000 但是只有32bit 而已
// 注意 是随意合成
// divide and conquer  
//

class Solution {
public:
    int dp(vector<int>& A){
        size_t size = A.size();

        vector<int> dp(A);
        set<int> res;

        // len
        for (int i = 0; i < size; i++) {
            // start
            for (int j = 0; j + i < size; j++) {
                // [i, i + j]
                dp[j] = dp[j] | A[ i + j];
                res.insert(dp[j]);
            }
        }
        return res.size();
    }


    set<int> res_set;

    void handle(vector<int> & A, int l, int r){
        if(l == r){
            res_set.insert(A[l]);
            return;
        }

        int mid = l + (r - l) / 2;
        
        handle(A, l, mid);
        handle(A, mid + 1, r);

        
        set<int> l_res;
        set<int> r_res;
        int res;


        res = A[l];
        l_res.insert(res);
        for (int i = l; i <= mid; i++) {
            if((A[i] | res) != res){
                res = A[i] | res;
                l_res.insert(res);
            }
        }

        res = A[mid + 1];
        r_res.insert(res);
        for (int i = mid + 1; i <= r ; i++) {
            if((A[i]| res) != res){
                res = A[i] | res;
                r_res.insert(res);
            }
        }

        for(auto i : l_res){
            for(auto j : r_res){
                res_set.insert(i | j);
            }
        }
    }

    int subarrayBitwiseORs(vector<int>& A) {
        handle(A, 0, A.size() - 1);
        return res_set.size();
    }
};

int main(){
    REOPEN_READ
    

    vector<int> A;
    int a;
    while(scanf("%d", &a) == 1){
        A.push_back(a);
        // cout << a << " " << endl;
    }

    Solution s;
    // A.clear();
    // A.push_back(1);
    // A.push_back(1);
    // A.push_back(2);

    cout << s.subarrayBitwiseORs(A) << endl;
    // cout << s.dp(A);

    return 0;
}
