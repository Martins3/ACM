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

class NestedInteger {
public:
  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};


class NestedIterator {
public:
    vector<int> A;
    int off;


    void flatten(const vector<NestedInteger> &nestedList){
        for(auto a : nestedList){
            if(a.isInteger()){
                A.push_back(a.getInteger());
            }else{
                flatten(a.getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        off = 0;
        flatten(nestedList);
    }

    int next() {
        return A[off ++];
    }

    bool hasNext() {
        return off < A.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main(){
    
    return 0;
}
