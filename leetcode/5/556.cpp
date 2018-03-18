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

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if(s.size() < 2) return -1;

        int last_num = s[s.size() - 1];
        int target = -1;
        int index = -1;
        for(int i = s.size() - 2; i >= 0; i--){
            int num = s[i];
            if(num < last_num){
                target = num;
                index = i;
                break;
            }else{
                last_num = num;
            }
        }

        if(index == -1) return -1;
    

        for(int i = s.size() - 1; i >= 0; i--){
            int num = s[i];
            if(num > target){
                char t = s[i];
                s[i] = s[index];
                s[index] = t;
                break;
            }
        }

        sort(s.begin() + index + 1, s.end());


        int res;
        try {
            res = stoi(s);
        } catch(...) {
            return -1;
        } 
        return res;
    }
};

int main(){
    REOPEN_READ
    //REOPEN_WRITE
    Solution s;
    cout << s.nextGreaterElement(230241);
    
    return 0;
}
/**
 * 没有的想到的会有的数值的不在整数的范围的中间
 * 交换 之后， 数值应该是的排序的的 
 */