#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
  void pushLeft(vector<string> &res, vector<int> &stack, int left,
                vector<char> &cons) {
    stack.push_back(1);
    cons.push_back('(');
    doGen(res, stack, left - 1, cons);
    stack.pop_back();
    cons.pop_back();
  }

  void pushRight(vector<string> &res, vector<int> &stack, int left,
                 vector<char> &cons) {
    stack.pop_back();
    cons.push_back(')');
    doGen(res, stack, left, cons);
    stack.push_back(1);
    cons.pop_back();
  }

  void doGen(vector<string> &res, vector<int> &stack, int left,
             vector<char> &cons) {
    if (stack.empty()) {
      if (left == 0) {
        res.push_back(string(cons.begin(), cons.end()));
      } else {
        pushLeft(res, stack, left, cons);
      }
    } else {
      // 放入 (
      if (left > 0) {
        pushLeft(res, stack, left, cons);
      }

      pushRight(res, stack, left, cons);
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> vec;
    vector<char> cons;
    vector<int> stack;
    doGen(vec, stack, n, cons);
    return vec;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  
 auto x=  s.generateParenthesis(8);
 for(auto xi: x){
   cout << xi << endl;
 }
  return 0; }
