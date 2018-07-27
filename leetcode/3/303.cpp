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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/ACM/leetcode/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/ACM/leetcode/output.txt", "w", stdout);


class BinaryIndexTree{
private:
    std::vector<int> arr;
    int lowBit(int x){
        return (x) & (-x);
    }

public:
    int sum(int x){
        int ans = 0;
        while(x != 0){
            ans += arr[x];
            x -= lowBit(x);
        }
        return ans;
    }

    void add(int x, int v){
        for(int i = x ; i < arr.size(); i += lowBit(i)){
            arr[i] += v;
        }
    }

    BinaryIndexTree(int size): arr(size + 1){}
};

class NumArray {
public:
    BinaryIndexTree * b;
    NumArray(vector<int> nums) {
        b = new BinaryIndexTree(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            b->add(i + 1, nums[i]);
        }
    }

    int sumRange(int i, int j) {
        if(i == 0) return b->sum(j + 1);
        return b->sum(j + 1) - b->sum(i + 1 - 1);
    }
};

int main(){
    // REOPEN_READ
    // REOPEN_WRITE

    return 0;
}
