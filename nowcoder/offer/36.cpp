#include <iostream>
#include <fstream>
#include <stack>
#include <sstream>
#include <climits>
#include <deque>
#include <vector>
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

    int low(vector<int> & vec, int k){
        int l = 0;
        int r = vec.size(); // not vec.size() - 1
        int mid;

        while(l < r){
            mid = l + (r - l) / 2;
            if(vec[mid] >= k){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        return l;
    }

    int up(vector<int> & vec, int k){
        int l = 0;
        int r = vec.size(); // not vec.size() - 1
        int mid;

        while(l < r){
            mid = l + (r - l) / 2;
            if(vec[mid] > k){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }

    int GetNumberOfK(vector<int> data ,int k) {
        int a = low(data, k);
        int b = up(data, k);
        printf("%d %d\n",a, b);
        if(a == data.size()) return 0;

        return b - a;
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
    cout << s.GetNumberOfK(vec, 3);

    
    
    return 0;
}
