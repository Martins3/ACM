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
#include <cassert>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

class Solution {
public:
    pair<int, int> bool_op(char op, pair<int, int> a, pair<int, int> b){
        int l = a.first + a.second;
        int r = b.first + b.second;
        int t, f;
        if(op == '|'){
            f = a.second * b.second;
            t = l * r - f;
        }else if(op == '&'){
            t = a.first * b.first;
            f = l * r - t;           
        }else{
            t = a.first * b.second + a.second * b.first;
            f = a.first * b.first + a.second * b.second;
        }

        return make_pair(t, f);                    
    }
    
    void sum(pair<int, int> & a, const pair<int,int> & b){
        a.first += b.first;
        a.second += b.second;
    }
        
    /**
     * 思路： 记录一个范围的数值运算的时候可以含有的可以出现情况
     * 如果两个范围中间的（a, b) (b, c) 数值都是可以含有m, n
     * 查看的两个数值的情况的是
     * 长度对应的情况
     * 相乘 
     * 多少组合为真， 多少组合为假 的
     * res 数组的表示范围， includsive
     * T F
     * 会不会前面的和后面的 含有 相互包含的情况， 计算的符号的优先级 ！
     * 1. 
     * @param symb: the array of symbols
     * @param oper: the array of operators
     * @return: the number of ways
     */
    int countParenth(string &symb, string &oper) {
        int len = symb.size();
        pair<int, int> * * res = new pair<int, int> * [len];
        for(int i = 0; i < len; i++) res[i] = new pair<int, int>[len];


        for(int len = 1;  len <= symb.size(); len++){
            for(int s = 0; s + len <= symb.size(); s++){
                int e = s + len - 1;
                if(len == 1){
                    bool r = symb[s] == 'T' ? true : false;
                    if(r)
                        res[s][e] = make_pair(1, 0);
                    else
                        res[s][e] = make_pair(0, 1);
                }else{
                    res[s][e].first = 0;
                    res[s][e].second = 0;
                    
                    for(int i = s; i < e; i++){
                        pair<int, int> left = res[s][i];
                        pair<int, int> right = res[i + 1][e];
                        pair<int, int> p = bool_op(oper[i], left, right);
                        sum(res[s][e], p); 
                    }
                }
            }
        }
        return res[0][len - 1].first;
    }
};

int main(){
    Solution s;
    string a = "FTTFFFTTTT";
    string b = "&|^&|&^^^";
    string sa = a.substr(1, 6);
    string sb = b.substr(1, 6);
    int res = s.countParenth(a, b);
    cout << res << endl;
    int sum = 1;
    for(int i = 1; i <= sb.size(); i++){
        sum *= i;
    }
    cout << sum << endl;
    return 0;
}