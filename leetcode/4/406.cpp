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
#define REOPEN_READ freopen("../input.txt", "r", stdin);

class BinaryIndexTree{
private:
    std::vector<int> arr;
    int lowBit(int x){
        return (x) & (-x);
    }

public:
    int sum(int x){
        int ans = 0;
        while(x != 0){
            ans += arr[x];
            x -= lowBit(x);
        }
        return ans;
    }

    void add(int x, int v){
        for(int i = x ; i < arr.size(); i += lowBit(i)){
            arr[i] += v;
        }
    }

    int lower_bound(int target){
        int left = 1;
        int right = arr.size() - 1;
        int mid = left + (right - left) / 2;
        while(left < right){
            if(sum(mid) < target){
                left = mid + 1;
            }else{
                right = mid;
            }
            mid = left + (right - left) / 2;
        }
        return left;
    }

    BinaryIndexTree(int size): arr(size + 1){}
};

struct Comparator{
    inline bool operator()(const pair<int, int> & a, const pair<int, int> & b){
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int> >& people) {
        BinaryIndexTree B(people.size());
        for (size_t i = 1; i <= people.size(); ++i) B.add(i, 1);

        std::priority_queue<pair<int, int>, std::vector<pair<int, int> >, Comparator> P;
        vector<pair<int, int> > res(people.size(), make_pair<int, int>(0, 0));
        for(pair<int, int> & p : people) P.push(p);

        // 当数值发生变化的时候再去处理

        vector<int> nums;
        int former_num = -1;

        while(!P.empty()){
            pair<int, int> p = P.top(); P.pop();
            if(p.first != former_num){
                former_num = p.first;
                for(int index : nums)
                    B.add(index, -1);
                nums.clear();
            }


            // 计算出来位置
            int index = p.second + 1;
            index = B.lower_bound(index);
            res[index - 1] = p;

            nums.push_back(index);


            for(auto x : res)
                cout << x.first << " " << x.second << " | ";
            cout << endl;
        }

        return res;
    }
};


int main(){
   REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    vector<pair<int, int> > vec;
    int a;
    int b;
    while(scanf("%d %d", &a, &b) == 2){
        vec.push_back(pair<int, int>(a, b));
        cout << a << " " << b << " ";
    }
    cout << endl;
    s.reconstructQueue(vec);
    return 0;
}
