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


// 直接用链表模拟, 才是最方便的
class Solution {
public:
    int LastRemaining_Solution(int n, int m){
        vector<bool> A(n, true);
        int counter = n - 1;
        int i = 0;
        int j = 0;
        while(true){
            while(j != m - 1){
                while(!A[i]){
                    i = (i + 1) % n;
                }
                // printf("[%d] [%d]\n", i, j);
                i = (i + 1) % n;
                j ++;
            }

            while(!A[i])
                i = (i + 1) % n;
            A[i] = false;
            // printf("[%d]\n", i);
            // for(auto s : A){
                // cout << s  << " ";
            // }
            // cout << endl;


            if(!counter) break;
            while(!A[i])
                i = (i + 1) % n;

            j = 0;
            counter --;
        }

        return i;
    }
};


int main(){
    
    Solution s;
    cout << s.LastRemaining_Solution(5, 3);
    return 0;
}
