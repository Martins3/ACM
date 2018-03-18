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
 * 假设没有的大于 10的数值出现
 * 应该可以证明出来的
 */
class Solution {
public:
    string q2str(queue<int> & q){
        string s;
        while(!q.empty()){
            s += q.front() + '0'; q.pop();
        }
        return s;
    }

    string countAndSay(int n) {
        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(i == 1){
                q.push(1);
                continue;
            }

            int len = q.size();
            int mount = 0;
            int last_num = -1; 
            for(int j = 0; j < len; j++){
                // 弹出来的时候 需要 注意
                int num = q.front(); q.pop();
                if(mount){
                    if(num != last_num){
                        q.push(mount);
                        q.push(last_num);                       
                        last_num = num;
                        mount = 1;
                    }else{
                        mount ++;
                    }
                }else{
                    last_num = num;
                    mount ++;
                }
            }
            if(mount){
                q.push(mount);
                q.push(last_num);
            }
        }
        return q2str(q);
    }
};
int main(){
    REOPEN_READ
    //REOPEN_WRITE
    Solution s;
    for(int i = 1; i <= 10; i++){
        cout << s.countAndSay(i) << endl;
    }
    return 0;
}