#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <forward_list>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

/**
 * 随便的找到一个不相同的bit, 然后将原来的数值划分为两个部分，
 * 然后转换成为的原来的问题
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int A_xor_B = 0;
        for(int num : nums){ A_xor_B = A_xor_B ^ num; }
        int m = 0;
        while(!(A_xor_B & (1 << m))) m ++;
        m = 1 << m;

        int A = 0;
        int B = 0;

        for(int num: nums){
            if(m & num)
                A = A ^ num;
            else
                B = B ^ num;
        }

        return vector<int>{A, B};
    }
};
int main(int argc, char *argv[]){
    Solution s;
    vector<int> vec{134, 134, 567, 567, 321, 123};

    for(auto a : s.singleNumber(vec)){
        cout << a << endl;
    }
    return 0;
}
