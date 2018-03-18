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
    
    vector<vector<int> > res;
    vector<int> container;
    int target;
    int sum;
    int len;
    
    // 表示将要的到达 该节点的， 退出的时候， 需要删除该数值
    // 表示的查询的时候， 之后的查询里面全部含有的该数值
    void dfs(int index,  vector<int> & candidates){
        int num = candidates[index];
        sum += num;
        container.push_back(num);

        if(sum >= target){
            if(sum == target){
                res.push_back(container);
            }
            // 退出搜索
            sum -= num;
            container.pop_back();
            return;
        }

        for(int i = index; i < len; i++){
            dfs(i, candidates);            
        }

        sum -= num;
        container.pop_back();
    }
     
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        this->sum = 0;
        this->len = candidates.size();
        container.clear();
        res.clear(); 
        sort(candidates.begin(), candidates.end());

        // 开始 查询 数据
        for(int i = 0; i < len; i++){
            dfs(i, candidates);
        }
        return res; 
    }
};

int main(){
    REOPEN_READ
    //REOPEN_WRITE

    Solution s;
    vector<int> candidates{2, 3, 6, 7};
    int target = 7;
    s.combinationSum(candidates, target);

    return 0;
}