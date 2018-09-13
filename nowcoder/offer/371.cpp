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
 * 1. 计算函数，逐个分析
 * 2. 只是需要遍历sqrt(2S) 的部分，由于
 */
class Solution {
public:
    int sum;

    int get(int a){
        int del2 =  1 - 4 * ( -a * a  + a - 2 * sum);

        // printf("%d\n", del2);
        if(del2 < 0) return -1;

        int del = (int)(sqrt(del2) + 0.5);
        // printf("%d  %d %d\n", del, del * del, del2);

        if(del * del != del2) return -1;

        del --;

        if(del % 2) return -1;

        return del / 2;
    }
    vector<vector<int> > FindContinuousSequence(int sum) {
        this->sum = sum;

        vector<vector<int> > res;

        for (int i = 1; i < sum; i++) {
            int b = get(i);
            if(b != -1){
                vector<int> v;
                for (int j = i; j <= b; j++) {
                    v.push_back(j);
                }
                res.push_back(v);
            } 
        }

        return res;
    }
};

int main(){
    Solution s; 
    std::vector<vector<int> > a = s.FindContinuousSequence(100);

    for (int i = 0; i < a.size(); i++) {
        print_v(a[i]);
    }
    
    
    // s.sum = 100;
    // cout << s.get(18);

    return 0;
}
