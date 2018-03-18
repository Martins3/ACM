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

class Max{
public:
    int maxn;    
    vector<int> A;
    pair<int, int> * * dp;
    Max(vector<int>& vec, int size):maxn(size + 1){
        A.push_back(0);
        A.insert(A.end(), vec.begin(), vec.end());

        dp = new pair<int, int> * [maxn];
        for(int i = 0; i < maxn; i++){
            dp[i]  = new pair<int, int>[(int)log(maxn) + 3];
        }
        ST(A.size());
    }

    ~Max(){
        for(int i = 0; i < maxn; i++){
            delete dp[i];
        }
    }

    void ST(int n) {  
        for (int i = 1; i <= n; i++)  
            dp[i][0] = make_pair(A[i], i);  
        for (int j = 1; (1 << j) <= n; j++) {  
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {  
                    int l = dp[i][j - 1].first;
                    int l_i = dp[i][j - 1].second;
                    int r = dp[i + (1 << (j - 1))][j - 1].first;
                    int r_i = dp[i + (1 << (j - 1))][j - 1].second;
                    if(l >= r){
                        dp[i][j] = make_pair(l, l_i);
                    }else{
                        dp[i][j] = make_pair(r, r_i);
                    }
            }  
        }  
    }  

    pair<int, int> RMQ(int l, int r) {  

        int k = 0;  
        while ((1 << (k + 1)) <= r - l + 1) k++;  


        int ll = dp[l][k].first;
        int ll_i = dp[l][k].second;
        int rr = dp[r - (1 << k) + 1][k].first;
        int rr_i = dp[r - (1 << k) + 1][k].second;
        if(ll >= rr)
            return make_pair(ll, ll_i);
        return make_pair(rr, rr_i);
    }  

};

class Solution {
public:
    /**
     * 贪心
     * 1. 前导 0 的处理
     * 2. 提前的结束的处理
     *  1. 需要的删除的元素大于剩下元素之和
     * 
     * 只要res size 满足的就 ok !
     * 
     * 都是 -1 删除的深度比较
     * 元素的数目相同， 到底删除哪一个 ？
     * tryed !
     * @param nums1: an integer array of length m with digits 0-9
     * @param nums2: an integer array of length n with digits 0-9
     * @param k: an integer and k <= m + n
     * @return: an integer array
     */
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        Max a(nums1, sizeof(nums1));
        Max b(nums2, sizeof(nums2));
        int D = sizeof(nums1) + sizeof(nums2) - k;

        int a_s = 0;
        int b_s = 0;
        vector<int> res;
        while(res.size() != k){
            int max_a = a_s + D <= nums1.size() ? a.RMQ(a_s, a_s + D).second : -1; 
            int max_b = b_s + D <= nums2.size() ? b.RMQ(b_s, b_s + D).second : -1; 
        }
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1, 9, 4, 7, 8};
    vector<int> nums2;
    s.maxNumber(nums1, nums2, 0);
    return 0;
}