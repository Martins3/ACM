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


    // backtrace
    bool isAdditiveNumber(string num) {
        if(num.size() < 3) return false;

    }
};

int main(){
    
    return 0;
}
