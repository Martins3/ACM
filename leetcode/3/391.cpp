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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/OnlineJudge/output.txt", "w", stdout);

class Rectangle{
public:
    pair<int, int> left;
    pair<int, int> right;
    Rectangle(int a, int b, int c, int d){
        left = make_pair(a, b);
        right = make_pair(c, d);
    }

    void print() const{
        cout << left.first << " ";
        cout << left.second << " ";
        cout << right.first << " ";
        cout << right.second << endl;
    }
};

struct LessThanByAge{
    bool operator()(const Rectangle& lhs, const Rectangle& rhs) const
    {
            if(lhs.left.second != rhs.left.second) return lhs.left.second > rhs.left.second;
            return lhs.left.first > rhs.left.first;
    }
};

class Solution {
public:

    map<int, int> skyline;
    std::priority_queue<Rectangle, std::vector<Rectangle>, LessThanByAge> heap;


    // 维持高度必定不相同
    // 右侧是否检查过
    bool add(const Rectangle & rec){
        // 检查越界
        map<int, int>::iterator right = skyline.lower_bound(rec.right.first);
        if(right == skyline.end()) return false;
        if(right == skyline.begin()) return false;
        auto t = right;
        --right;
        auto left = right;
        right = t;

        if(left->first > rec.left.first) return false;

        // 确保落在上方
        if(left->second != rec.left.second) return false;

        if(left->first  != rec.left.first){
            skyline[rec.left.first] = rec.right.second;
        } else{
            left->second = rec.right.second;
            // 高度相同，合并
            if(left != skyline.begin()){
                auto t = left;
                --left;
                auto ll = left;
                left = t;
                if(ll->second == left->second){
                    skyline.erase(left);
                }
            }
        }

        if(right->first != rec.right.first){
            skyline[rec.right.first] = rec.left.second;
        }else{
            if(rec.right.second == right->second){
                skyline.erase(right);
            }
        }

        cout << "add : ";
        for(auto r : skyline){
            cout << r.first  << " " << r.second << " | ";
        }
        cout << endl;
        return true;
    }



    bool make_bottom(){
        if(heap.empty()) return false;
        skyline[heap.top().left.first] = heap.top().right.second;
        skyline[heap.top().right.first] = heap.top().left.first;
        int h = heap.top().left.second;
        int s = heap.top().right.first;
        heap.pop();

        while(!heap.empty()){
            const Rectangle & r = heap.top();
            if(h != r.left.second) break;
            if(s != r.left.first) return false;


            map<int,int>::iterator last = skyline.end();
            last --;
            last --;
            if(last->second == r.right.second){
                skyline.erase(++last);
            }else{
                skyline[r.left.first] = r.right.second;
            }

            skyline[r.right.first] = h;
            s = r.right.first;
            heap.pop();
        }

        cout << " make_bottom : ";
        for(auto r : skyline){
            cout << r.first  << " " << r.second << " | ";
        }
        cout << endl;

        return true;
    }

    bool isRectangleCover(vector<vector<int> >& rectangles) {
        for(vector<int> & v : rectangles){
            heap.push(Rectangle(v[0], v[1], v[2], v[3]));
        }

        if(!make_bottom()) return false;
        while(!heap.empty()){
            if(!add(heap.top())) return false;
            heap.pop();
        }

        return skyline.size() == 2;
    }

};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;

    vector<vector<int> > v;
    v.push_back(vector<int>{1,1,3,3});
    v.push_back(vector<int>{ 3,2,4,4});
    v.push_back(vector<int>{ 1,3,2,4});
    v.push_back(vector<int>{ 2,3,3,4});
    v.push_back(vector<int>{ 3,1,4,2});
    cout << s.isRectangleCover(v);
    return 0;
}
