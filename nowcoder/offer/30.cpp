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
    vector<int> A;
    int res;

    
    /**
     *
     * 简单的递归查找
     * counter 表示前面已经含有1的数目
     * 表示类似的替代品
     *
     */
    void cal(int i, int counter, int shadow, bool restrict){
        printf("%d %d %d %d\n", i, counter, shadow, restrict);

        if(i == A.size()){
            res += counter * shadow;
            return;
        }
        if(restrict){
            if(A[i] == 0){
                cal(i + 1, counter, shadow, true);
            }else if(A[i] == 1){
                cal(i + 1, counter, shadow, false);
                cal(i + 1, counter + 1, shadow, true);
            }else{
                cal(i + 1, counter, shadow * (A[i] - 1), false);
                cal(i + 1, counter, shadow * 1, true);
                cal(i + 1, counter + 1, shadow, false); // 等于2的部分
            }
        }else{
            cal(i + 1, counter, shadow * 9, false);
            cal(i + 1, counter + 1, shadow, false);
        }
    }

    
    int NumberOf1Between1AndN_Solution(int n) {
        res = 0;
        while(n){
            A.push_back(n % 10);
            n = n / 10;
        }

        reverse(A.begin(), A.end());

        cal(0, 0, 1, true);

        return res;
    }
};
int main(){
    Solution s;
    cout << s.NumberOf1Between1AndN_Solution(13);
    return 0;
}
