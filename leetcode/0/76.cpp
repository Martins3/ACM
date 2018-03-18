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
    string minWindow(string s, string t) {
        map<char, int> m;
        set<char> chars;
        for(char c: t){
            chars.insert(c);
            if(m.find(c) != m.end()){
                m[c] ++;
            }else{
                m[c] = 1;
            }
        }
        pair<int, int> range;

        int left = 0;
        int right = 0;

        // get the first one 
        int size = chars.size();
        bool ok = false;
        while(right < s.size()){
            char c = s[right];
            auto f = m.find(c);
            if(f != m.end()){
                if(f -> second == 1) {
                    size --;
                    if(size == 0) {
                        ok = true;
                        f -> second --;
                        break;
                    }
                }
                
                f -> second --;
            }
            right ++;
        }        
        
        
        
        if(!ok) return "";
        range = make_pair(left, right);
        // rebuild the m
        // 负数表示剩下的数目

        char need = 0;
        bool complete = true;
        while(right < s.size()){
            if(complete){
                if(chars.find(s[left]) != chars.end() ){
                    if(m[s[left]]){
                        m[s[left]] ++;
                    }else{
                        complete = false;
                        need = s[left];
                    }
                }

                if(range.second - range.first > right - left) range = make_pair(left, right);                

                left ++;
            }else{
                right ++;
                if(right >= s.size()) break;

                if(s[right] == need){
                    complete = true;
                }else if(chars.find(s[right]) != chars.end()){
                    m[s[right]] --;
                }
            }
        }
        return s.substr(range.first, range.second - range.first + 1);
    }
};
int main(){
    REOPEN_READ
    // REOPEN_WRITE
    string S = "aba";
    string T = "ba";
    Solution s;
    cout << s.minWindow(S, T) << endl;

    return 0;
}

/**
 * 1. 变量书写错误 应该是 s
 * 2. 当出现元素向右边移动的时候， 会有元素没有办法处理过但是没有添加的， 所以需要使用的 map 处理
 *      当缺乏元素的时候， 最多只是需要一个， 但是查询的过程中间的数据都是需要添加
 * 3. 开始的时候添加元素就是会出现问题， 所以，判断结束的方法含有问题， 本来设计的含有问题的
 * 4. right 进一步访问的时候， 缺少的必须
 * 
 */