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
#include "../info.hpp"

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // move nums1 to the end !
        int L1 = nums1.size();
        for (int i = m - 1; i >= 0; i--) {
            nums1[L1 - m + i] = nums1[i];
        }

        int a = L1 - m;
        int b = 0;

        int x = 0;
        while(a < L1 || b < n){
            if(a == L1){
                nums1[x] = nums2[b++];
            }else if(b == n){
                nums1[x] = nums1[a++];
            }else if(nums1[a] < nums2[b]){
                nums1[x] = nums1[a++];
            }else{
                nums1[x] = nums2[b++];
            }
            x ++;
            // print_v(nums1);
            // printf("%d %d %d\n",a , b, x);
        }
    }
};

int main(){
    Solution s;
    vector<int> a{1,2,3,0,0,0};
    vector<int> b{2, 5, 6};
    s.merge(a, 3, b, 3);
    print_v(a);
    return 0;
}
