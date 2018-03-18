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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);
#define lld long long int


class Solution {
public:
    /**
     * 贪心算法
     * 从 小 到 大 的处理， 但是没有处理结束， 
     */
    int minPatches(vector<int>& nums, int n) {
        lld range = 0;
        lld patch = 0;
       
        bool ok = false; 
        if(n <= 0) return 0;
        if(nums.empty()){
            while(range < n){
                patch ++;
            
                range += range + 1;
                cout << range << endl;
            }
            return patch;
        }

        for(lld num: nums){
           
           // 直到 使用了 当前数值 或者 没有当前已经搞定了
            while(num - 1 > range){
                patch ++;
                cout << range + 1 << endl;
                range += range + 1;


                if(range >= n){ ok = true; break; }
            }

            if(!ok){
                range += num;
                if(range >= n) break;
            } else{
                break;
            }
        }       

        // 如果所有数值使用完， 但是依旧没有达到
        while(range < n){
            patch ++;
            cout << range + 1 << endl;
            range += range + 1;

        }

        return patch;
    }
};

int main(){
    REOPEN_READ
    // REOPEN_WRITE
    Solution s;
    vector<int> v{1,7,21,31,34,37,40,43,49,87,90,92,93,98,99};
    int n = 12;
    cout << s.minPatches(v, n) << endl;

    return 0;
}

/**
 * error log:
 * 1. 没有处理的 对于所有的数值添加之后依旧无法处理
 * [1,7,21,31,34,37,40,43,49,87,90,92,93,98,99]
12
 */