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

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int M = array.size();
        if(M == 0) return false;

        int N = array[0].size();
        if(N == 0) return false;
        
        for (int i = 0; i < M; i++) {
            if(array[i][0] > target)
                return  false;
            if(std::binary_search(array[i].begin(), array[i].end(), target))
                return true;
        }

        return false;
    }
};

int main(){
    
    return 0;
}
