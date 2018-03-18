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

#define INF 0x3f3f3f3f
class Node{
public:
    int val;
    int id;
    Node(int val, int id): val(val), id(id){}
    bool operator < (const Node & n) const{
        return val > n.val;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> index(nums.size(), 0);
        // vector<bool> isValid(nums.size(), 0);
        vector<int> lens;
        int LEN = nums.size();
        for(auto v: nums){
            lens.push_back(v.size());
        }

        priority_queue<Node> q;
        priority_queue<int, vector<int>, greater<int> > gohst;
        pair<int, int> range;
        int left;
        int right = -INF;
        int distance = 2 * INF;

        for(int i = 0; i < LEN; i++){
            q.push(Node(nums[i][0], i));
            right = max(right, nums[i][0]);
        }
        left = q.top().val;
        distance = right - left;
        range = make_pair(left, right);

        // 添加元素的时候， 才会有更新
        int valid_q = LEN;
        while(true){
            Node n = q.top(); q.pop();
            ++index[n.id];
            if(index[n.id] == nums[n.id].size()){
                if(!(--valid_q)) break;
                gohst.push(n.val); 
            }else{
                q.push(Node(nums[n.id][index[n.id]], n.id));
                right = max(right, nums[n.id][index[n.id]]);
                left = q.top().val;
                if(gohst.size()) left = min(left, gohst.top());


                if(right - left < range.second - range.first){
                    range.first = left;
                    range.second = right;
                }
            }
        }
        return vector<int>{range.first, range.second};        
    }
};


/**
 * 所有的元素最多包含一个， 保证所有元素总是在一起的
 * 分析：
 * 1. 当一个 其中一个元素只有最后的时候的，如何处理的 ？ 不在出来
 * 2. 
 */
int main(){
    REOPEN_READ
    // REOPEN_WRITE
    Solution s;
    vector<vector<int> > v;
    v.push_back(vector<int>{4,10,15,24,26});
    v.push_back(vector<int>{0,9,12,20});
    v.push_back(vector<int>{5,18,22,30});
    // v.push_back(vector<int>{1});

    vector<int> vec = s.smallestRange(v);
    cout << vec[0] << " " << vec[1] << endl;

    return 0;
}

/**
 * error log
 * 1. 对于right 数值初始化错误
 * 2. 对于只有的一个元素的情况， 没有处理
 */