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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, std::vector<int>> l; 
    priority_queue<int, std::vector<int>, std::greater<int> > r; 

    MedianFinder() {

    }
    
    void addNum(int num) {
        // add to which side
        

        if(!l.empty()){
            int a = l.top();
            if(num <= a)
                l.push(num);
            else
                r.push(num);
        }else{
            if(!r.empty()){
                if(r.top() < num)
                    r.push(num);
                else
                    l.push(num);
            }else{
                l.push(num);
            }
        }

        // if nums are not same, balance them !
        while(l.size() > r.size()){
            r.push(l.top()); l.pop();
        }

        while(r.size() - 1 > l.size()){
            l.push(r.top()); r.pop();
        }
    }
    
    double findMedian() {
        if(r.size() - 1 == l.size()) return r.top();    
        return (r.top() + l.top()) / 2.0;
    }
};


int main(){
    REOPEN_READ
    //REOPEN_WRITE
    MedianFinder* obj = new MedianFinder;
    obj ->addNum(123);
    obj ->addNum(2);
    obj ->addNum(6777);
    double param_2 = obj -> findMedian();
    
    return 0;
}