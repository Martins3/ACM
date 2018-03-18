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

#define maxn 300
class Solution {
public:
    char res[maxn];
    string multiply(string num1, string num2) {
        memset(res, 0, sizeof(res)); 

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int len1 = num1.size();
        int len2 = num2.size();

        for(int i = 0; i < len1; i++){
            int a = num1[i] - '0';
            int carry  = 0;
            int j;
            for(j = 0; j < len2; j++){
                int b = num2[j] - '0';
                int c = res[i + j] == 0 ? 0 : res[i + j] - '0'; 
                int d = a * b + c + carry;
                carry =  d / 10;
                res[i + j] = d % 10 + '0';
            }

            if(carry) res[i + j] = carry + '0';
        }

        string a(res);
        reverse(a.begin(), a.end());
        unsigned i;
        for(i = 0; i < a.size(); i++){
            if(a[i] != '0') break;
        }
        if(i == a.size()){
            a = a.substr(a.size() - 1, 1);
        }else{
            a = a.substr(i, a.size() - i);
        }
        return a;
    }
};
int main(){
    REOPEN_READ
    //REOPEN_WRITE
    Solution s;
    cout << s.multiply("1231231231", "0") << endl;
    cout << 123 * 123 << endl;
    return 0;
}
/**
 * 删除的前导 0
 * 
 */