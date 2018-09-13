#include "../../leetcode/info.hpp"
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

/**
 * 应该使用two pointer算法
 * 　由于　正数　负数的分布，不知道最佳结果在哪里
 *
 * 但是使用2 Sum 来计算
 */
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int l = 0;
        int r = array.size() - 1;
        vector<int> res;

        int mul;
        bool fuck = true;

        while(l < r){
            while(array[l]  + array[r] > sum){
                r --;
                if(r == l) break; 
            }
            
            if(array[l] + array[r] == sum){
                if(fuck){
                    mul = array[l] * array[r];
                        res = vector<int>{array[l], array[r]};
                    fuck = false;
                }else{
                    if(mul > array[l] * array[r]){
                        res = vector<int>{array[l], array[r]};
                    }
                }

                r--;
                if(r == l) break;
            }

            if(array[l] + array[r] < sum){
                l ++;
                if(l == r) break;
            }
        }
        return res;
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
    print_v(s.FindNumbersWithSum(vec, 15));
    
    return 0;
}
