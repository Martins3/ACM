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
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

/**
 * 1. 同一个位置不要部署　访问两次相同的数量
 */

class Solution {
public:
    vector<string> res;
    string vec;
    int counter;
    string str;
    std::vector<bool> visited;

    
    void trans(int loc){
        // 添加资源
        visited[loc] = true;
        counter ++;
        vec.push_back(str[loc]);

        // printf("%d %d %zd\n", counter, loc, visited.size());
        if(counter == visited.size()){
            res.push_back(vec);
            // printf("[%s]\n", res[0].c_str());
        }else{
            // 继续向下递归
            // 是屏蔽同级的
            bool ok = true;
            char last;
            for (int i = 0; i < visited.size(); i++) {
                if(!visited[i]){
                    if(ok){
                        trans(i);
                        last = str[i];
                        ok = false;
                    }else{
                        if(str[i] != last){
                            trans(i);
                            last = str[i];
                        }
                    }
                }
            }
        }

        // 回收资源
        vec.pop_back();
        counter --;
        visited[loc] = false;
        return;
    }

    vector<string> Permutation(string str) {
        sort(str.begin(), str.end());
        visited = vector<bool>(str.size(), false);
        counter = 0;
        this->str = str;


        for (int i = 0; i < str.size(); i++) {
            if(i > 0 && str[i] == str[i - 1])
                continue;
            trans(i);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> v = s.Permutation("adba");
    
    for(auto l : v){
        cout << l << endl;
    }
    
    
    return 0;
}
