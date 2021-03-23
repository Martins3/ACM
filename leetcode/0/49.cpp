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
  vector<vector<string>> groupAnagrams(vector<string> &strs) {

    auto sort_vec = [](const vector<char> &a, const vector<char> &b) -> bool {
      if (a.size() < b.size())
        return true;
      if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); ++i) {
          if (a[i] < b[i])
            return true;
          if (a[i] > b[i])
            return false;
        }
      }
      return false;
    };
    vector<vector<string>> res;

    map<vector<char>, vector<string>, decltype(sort_vec)> map(sort_vec);
    for (auto &str : strs) {
      vector<char> chars;
      for (auto m : str) {
        chars.push_back(m);
      }
      sort(chars.begin(), chars.end());
      map[chars].push_back(str);
    }
    for (auto x : map) {
      res.push_back(x.second);
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
