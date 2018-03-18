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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
public:

    /** Initialize your data structure here. */
    map<int, int> se;
    map<int, int> es;
    SummaryRanges() {

    }
    
    void addNum(int val) {
        auto fse = se.find(val + 1);
        
        auto fes = es.find(val - 1);

        auto p = es.lower_bound(val);
        if(p->first >= val && p->second <= val) return;
        
        

        if(fse != se.end() &&  fes != es.end()){
            int a = fes->second;
            int b = fes->first;
            int c = fse->first;
            int d = fse->second;
            
            es.erase(b);
            es.erase(d);

            se.erase(a);
            se.erase(c);

            es[d] = a;
            se[a] = d;
        }else if(fse != se.end()){
            int c = fse->first;
            int d = fse->second;
            

            es.erase(d);
            se.erase(c);

            es[d] = val;
            se[val] = d;
        }else if(fes != es.end()){
            int a = fes->second;
            int b = fes->first;

            se.erase(a);
            es.erase(b);

            es[val] = a;
            se[a] = val;
        }else{
            se[val] = val;
            es[val] = val;
        }   
        
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> v;
        for(auto i = se.begin(); i != se.end(); i++){
            v.push_back(Interval(i->first, i->second));
        }
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 * 
 * 除非 节点本身的就是的一个 Interval, 那么
 */
int main(){
    REOPEN_READ

    SummaryRanges obj;
    obj.addNum(1);
    obj.addNum(2);
    obj.addNum(3);

    obj.addNum(5);
    vector<Interval> param_2 = obj.getIntervals();
    
    for(Interval i: param_2){
        cout << i.start << "  " << i.end << endl;
    }

    map<int, int> a;
    a[1] = 1;
    a[10] = 10;
    a[100] = 100;

    // 第一个的不会的小于的元素的在上面　
    auto p = a.lower_bound(7);
    cout << p->first << endl;
    return 0;
}

/**
 * 1. 如果正好的是命中的中间的区域， 没有分析对应的情况的
 * 2.　
 * 3. 
 */