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
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

typedef long long int lld;

class Solution {
public:
    int res;
    vector<int> buf;

    /**
     * nums >= 2
     * sort 下标 和 长度
     */
    void divide_conquer(int left, int right, vector<int>& nums){
        if(right - left == 1){
            lld l = nums[left];
            lld r = nums[right];
            if(l > r * 2) res ++;
            if(l > r){
                nums[left] = r;
                nums[right] = l;
            }
            return;         
        }else if(right - left == 2){
            int middle = left + 1;
            lld l = nums[left];
            lld m = nums[middle];
            lld r = nums[right];

            if(l > r * 2) res ++;            
            if(l > m * 2) res ++;            
            if(m > r * 2) res ++;            

            sort(nums.begin() + left, nums.begin() + right + 1);
            return;
        }

        int middle = left + (right - left) / 2;
        divide_conquer(left, middle, nums);
        divide_conquer(middle + 1, right, nums);
       
        // 绝对没有出现更多的判断
        for(int i = middle; i >= left ; i--){
            bool none = true;
            for(int j = middle + 1; j <= right; j++){
                lld l = nums[i];
                lld r = nums[j];
                if(l > 2 * r){
                    res ++;
                    none = false;
                }else{
                    break;
                }
            }
            if(none) break;
        }

        // merge sort 元素， 减少sort 的复杂度
        

    }

    int reversePairs(vector<int>& nums) {
        this->res = 0;
        int len = nums.size();
        if(len <= 1) return 0;
        buf.assign(len, 0);
        
        divide_conquer(0, len - 1, nums);
        return this->res; 
    }
};


/**
 * divide and conquer 算法
 * [1, n] [n, len] 的查找， 寻找所有的对 , sort 一下，然后就可以查询
 */
int main(){
    REOPEN_READ
    //REOPEN_WRITE
    Solution s;
    vector<int> v{2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
    cout << s.reversePairs(v);
    
    return 0;
}