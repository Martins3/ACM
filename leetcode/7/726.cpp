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

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

class Solution {
public:
    string str;

    void mergeMap(map<string, int> & a, map<string, int> & b){
        for(auto i = a.begin(); i != a.end(); i++){
           string s = i->first;
           int n = i->second;
           
           auto d = b.find(s);
           if(d != b.end()) i->second += d->second;
        }

        for(auto i = b.begin(); i != b.end(); i++){
            auto d = a.find(i ->first);
            if(d == a.end()) a.insert(*i);
        }
    }

    pair<int, int> getP(int l){
        int ok = 0;
        int r = l;
        do{
            if(str[r] == '(') ok ++;
            if(str[r] == ')') ok --;
            r ++; 
        }while(ok);
        return make_pair(l, r - 1);
    }

    // name 顺序
    pair<int, int> getName(int l){
        int r = l + 1;
        while(islower(str[r])) r++;
        return make_pair(l, r - 1);
    }

    // 可用 开始
    pair<int, int> getNum(int l){
        int r = l;
        while(isdigit(str[r])) r ++;;

        int res = 0 ;
        if(l != r) {
            res = stoi(str.substr(l, r - l));     
        }else{
            res = 1;
        }
        return make_pair(res, r);
    }

    // set 数值相乘
    void multiMap(map<string, int> & m, int num){
        for(auto i = m.begin(); i != m.end(); i++) i->second *= num;
    }

    map<string, int> pCount(int l, int r){
        map<string, int> m;
        for(int i = l; i <= r;){
            if(str[i] == '('){
                auto p = getP(i);
                i = p.second + 1;
                auto num = getNum(i);
                i = num.second;
                
                map<string, int> lp = pCount(p.first + 1, p.second - 1);
                multiMap(lp, num.first);
                mergeMap(m, lp);
            } else{
                auto s = getName(i);
                i = s.second + 1;
                auto num = getNum(i);
                i = num.second;

                string name = str.substr(s.first, s.second - s.first + 1);
                auto p = m.find(name);
                if(p == m.end()) 
                    m[name] = num.first;
                else
                    m[name] += num.first;
            }
        }
        return m;
    }

    string countOfAtoms(string formula) {
        this->str = formula;
        map<string, int> m =  pCount(0, str.size() - 1);
        string res;
        for(auto i = m.cbegin(); i != m.cend() ; i++){
            res += i->first + (i->second == 1 ? "" : to_string(i->second));
        }      
        return res;
    }
};


int main(){
    REOPEN_READ
    // REOPEN_WRITE
    Solution s;
    cout << s.countOfAtoms("K4(ON(SO3)2)2") << endl;

    return 0;
}
/**
 * error log:
 *  1. pCount 函数忘记的写返回值
 *  2. 对于 ++ 理解错误， 在while 中间的 ++， 导致偏离错误， ++ 禁用 
 *  3. 不应该自己手写的string int 的转化函数， 出现错误
 *  4. 对于输入的没有分析清楚的 
 */