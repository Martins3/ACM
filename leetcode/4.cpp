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
    int expectNumber(vector<int>& scores) {
      sort(scores.begin(), scores.end());
    int ret = 0;
    int prev = scores[0];
    scores.push_back(scores.back() + 1);
    for (int i = 0; i < scores.size(); ++i) {
      if(prev != scores[i]) {
        ret ++;
        prev = scores[i];
      }
   }
    return ret;
  }
};


int main() { 
  Solution s;
vector<int> x{2, 1};
  auto g = s.expectNumber(x);

  cout << g << endl;
  return 0; }
