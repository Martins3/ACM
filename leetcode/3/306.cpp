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
    string sum(string str1, string str2){

        if (str1.length() > str2.length())
            swap(str1, str2);

        string str;
        int n1 = str1.length(), n2 = str2.length();

        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());
     
        int carry = 0;
        for (int i=0; i<n1; i++) {
            int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }
     
        for (int i=n1; i<n2; i++) {
            int sum = ((str2[i]-'0')+carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }
     
        if (carry)
            str.push_back(carry+'0');
     
        reverse(str.begin(), str.end());
        return str;
    }


    // 前导0的处理
    // 一个数值一旦确定前面的数值，后面只是简单的测试
    bool isAdditiveNumber(string num) {
        int len = num.size();
        if(len < 3) return false;
        
        deque<string> q;

        for(size_t l = 0; l < len - 2; l ++){
            // 检查leading zero
            if(l >= 1 && num[0] == '0') return false;

            for (size_t  r = l + 1; r < len - 1; r++) {
                // [0, l] [l+1, r] 
                
                // 检查leading zero
                if(r - (l + 1) >= 1 && num[l + 1] == '0') break; 

                q.clear();
                q.push_back(num.substr(0, l + 1));
                q.push_back(num.substr(l + 1, r - l));

                // cout << q.front() << endl;
                // cout << q.back() << endl;
                // cout << "--------" << endl;


                // 确定了计算两个数值，之后就是简单的核对
                int start = r + 1;
                while(true){

                    string res = sum(q.front(), q.back());
                    // cout << "res : " << res << endl;
                    size_t res_size = res.size();
                    if(res_size + start > num.size()) break; // 长度超长，直接放弃
                    
                    string ans = num.substr(start, res_size);

                    if(ans == res){
                        // printf("%d %zu %d ", start, res_size, len);
                        if(start + res_size == len) return true;

                        q.pop_front();
                        q.push_back(ans);
                        start += res_size;
                    }else{
                        break; // 不相等，爆炸
                    }
                }
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    cout << s.isAdditiveNumber("112358");
    return 0;
}
