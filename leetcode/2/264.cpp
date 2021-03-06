#include "../info.hpp"
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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/OnlineJudge/output.txt", "w", stdout);

/**
 *  使用merge sort的策略
 *  2 * ugly[0]  2 * ugly[1]
 *
 *  前面的ugly数值不够使用, 如何处理 ?
 *  不可能的事情，事先注入数值４，每次消耗都会添加
 *
 *  含有一个小问题:　可能会出现相同的数值
 *
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> a(n + 1);
        a[1] = 1;

        int index_2 = 1;
        int index_3 = 1;
        int index_5 = 1;

        int M = 1;

        for (int i = 2; i <= n; i++) {
            while(true){
                if(a[index_2] * 2 == M) {index_2 ++; continue;}
                if(a[index_3] * 3 == M) {index_3 ++; continue;}
                if(a[index_5] * 5 == M) {index_5 ++; continue;}
                break;
            }

            int v = a[index_2] * 2;
            int off = 2;

            if(a[index_3] * 3 < v){
                v = a[index_3] * 3;
                off = 3;
            }

            if(a[index_5] * 5< v){
                v = a[index_5] * 5;
                off = 5;
            }

            switch(off){
                case 2:
                    a[i] = a[index_2] * 2;
                    index_2 ++;
                    break;
                case 3:
                    a[i] = a[index_3] * 3;
                    index_3 ++;
                    break;
                case 5:
                    a[i] = a[index_5] * 5;
                    index_5 ++;
                    break;
            }
            
            M = a[i];
        }

        print_v(a);
        return a[n];
    }
};

int main(){
    Solution s;
    cout << s.nthUglyNumber(10);
    return 0;
}
