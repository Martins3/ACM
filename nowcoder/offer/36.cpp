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
            if(mid < k){
                l = mid + 1;
            }else{
                r = mid;
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
            if(k < mid){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }
    
    int GetNumberOfK(vector<int> data ,int k) {
    }
};

int main(){
    
    return 0;
}
