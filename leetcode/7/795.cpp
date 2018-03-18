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

class Solution {
public:
    /**
     * 简单循环
     * 1. 如果 遇到遇到 大于 R 终止， 重新 ， 两个区间之间
     * 2. 区间的里面的， 只要包含了valid 都是可以的， 左端点的， 删除的在valid 中间的所有的的
     * 组合即可
     * 3. 计算长度为 n
     * len 
     * 1
     */
    int Cn(int len){
        return (1 + len) * len / 2;  
    }

    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int res = 0;
        int len = 0;
        int local_len = 0;

        int invalid_nums = 0;

        A.push_back(R + 1); // 添加的fake tail
        for(int i = 0; i < A.size(); i++){
            if(A[i] > R){
                res += Cn(len);
                invalid_nums += Cn(local_len);
                res -= invalid_nums;

                len = 0;
                local_len = 0;
                invalid_nums = 0;
            }else if(A[i] >= L && A[i] <= R){
                len ++;
                
                invalid_nums += Cn(local_len);
                local_len = 0; 
            }else{
                len ++;
                local_len ++;
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int>A = {2, 1, 4, 3};
    cout  << s.numSubarrayBoundedMax(A, 2, 3);
    return 0;
}