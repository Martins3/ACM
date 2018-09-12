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
    int GetUglyNumber_Solution(int n) {
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

     
        return a[n];
    }
};

