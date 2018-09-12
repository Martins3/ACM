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

typedef long long int lld;
class Solution {
public:
    lld res;
    /**
     * nums >= 2
     * sort 下标 和 长度
     */
    void divide_conquer(int left, int right, vector<lld>& nums){
        if(right - left == 1){
            lld l = nums[left];
            lld r = nums[right];
            if(l > r) res ++;
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

            if(l > r) res ++;            
            if(l > m) res ++;            
            if(m > r) res ++;            

            sort(nums.begin() + left, nums.begin() + right + 1);
            return;
        }

        int middle = left + (right - left) / 2;
        divide_conquer(left, middle, nums);
        divide_conquer(middle + 1, right, nums);
       
        // 直接查询所有的数值
        // lower_bound 大于等于第一个
        // printf("%d\n", res);

        for(int i = middle + 1; i <= right ; i++){
            auto f = std::upper_bound(nums.begin() + left, nums.begin() + middle + 1, nums[i]);

            if(f == nums.begin() + middle + 1){
                continue;
            }
            if(*f == nums[i]) f ++;
            if(f != nums.begin() + middle + 1){
                res += ((nums.begin() + middle + 1) - f);
                // printf("%d --- %d --- %d\n", left, middle, right);
                // printf("[%d] [%d]\n",*f, nums[i]);
            }
        }
        


        vector<int> s(right - left + 1);
        for (int i = left; i <= right; i++) {
            s[i - left] = nums[i];
        }
        // print_v(s);

        int i = left;
        int x = 0; // mid
        int y = middle + 1 - left; // right
        while(i <= right){
            // print_v(nums);
            if(x > middle - left){
                nums[i] = s[y];
                y ++;
            }else if(y > right - left){
                nums[i] = s[x];
                x ++;
            }else{
                if(s[x] > s[y]){
                    nums[i] = s[y];
                    y ++;
                }else{
                    nums[i] = s[x];
                    x ++;
                }
            }
            i ++;
        }

    }

    int InversePairs(vector<int> nums) {
        this->res = 0;
        int len = nums.size();

        vector<lld> Num;
        for(auto n : nums){
            Num.push_back(n);
        }
        divide_conquer(0, len - 1, Num);

        // print_v(nums);
        return this->res % 1000000007; 
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
    cout <<  s.InversePairs(vec);
    
    
    return 0;
}


