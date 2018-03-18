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
 * 使用的two pointer 实现
 * 
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        assert(words.size());
        int len = words.size();
        unordered_map<string, int> table;
        unordered_map<string, int> datas;
        // 记录 表项 
        for(string s: words){
            auto f = datas.find(s);
            if(f != datas.end()){
                f->second ++;
            }else{
                datas.insert(make_pair(s, 1));
            }
        }

        for(auto i = datas.cbegin(); i != datas.cend(); i++){
            table.insert(make_pair(i->first, 0));
        }
        int word_len = words[0].size();
        vector<int> res;

        int finds = 0;
        
        for(int right = 0; right + word_len <= s.size(); right += word_len){
            string word = s.substr(right, word_len);
            if(datas.find(word) == datas.end()){
                for(auto i = table.begin(); i != table.end(); i++)i->second = 0;
                finds = 0;
                continue;
            }

            auto f = table.find(word);
            f->second ++;
            finds ++;

            int max_num = datas.find(word)->second;
            if(f->second > max_num){
                int start = right - finds * word_len + word_len;
                while(true){
                    word = s.substr(start, word_len);
                    auto fw = table.find(word);
                    fw->second --;
                    finds --;
                    if(fw->first == f->first) break;
                    start += word_len;
                }     
            }

            if(finds == len){
                int start = right - finds * word_len + word_len;
                word = s.substr(start, word_len);
                res.push_back(start);
                // 最前面的数值减一
                auto fw = table.find(word);
                fw->second --; 
                finds --;
            }
        }
        return res;
    }
};

int main(){
    REOPEN_READ
    // REOPEN_WRITE
    string str = 
    "barfoothebarfoo";
    vector<string> vec = {"foo","bar"};
    Solution s;
    vector<int> v = s.findSubstring(str, vec);
    for(int i = 0; i < v.size(); i++){
        printf("%d ", v[i]);
    } 
    return 0;
}
/**
 * 1. 题目意思的理解的错误， 是可以的对于的数据进行重复的添加到里面的
 * 2. 相同的错误 两次了， continue 只有 配合 for 或者 死循环书写 ！
 * 3. 清除的时候的， 正确的数值的开始的位置是固定， 但是错误的数值的开始的位置不一定
 *      当重新开始的时候， 开始的位置从 下一个字母开始， 
 */