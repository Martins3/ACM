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
  void doGen(vector<int> &candidates, int target, int start,
             vector<vector<int>> &res, vector<int> &cons) {
    for (int i = start; i < candidates.size(); ++i) {
      // check invalid condition
      if (candidates[i] > target)
        break;

      if (candidates[i] == target) {
        cons.push_back(candidates[i]);
        res.push_back(cons);
        cons.pop_back();
        break;
      }

      // check res;
      cons.push_back(candidates[i]);
      doGen(candidates, target - candidates[i], i + 1, res, cons);
      cons.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> cons;
    doGen(candidates, target, 0, res, cons);

    auto sort_vec = [](const vector<int> &a, const vector<int> &b) -> bool {
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
    auto equal_vec = [](const vector<int> &a, const vector<int> &b) -> bool {
      if (a.size() != b.size())
        return false;
      for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i])
          return false;
      }
      return true;
    };

    sort(res.begin(), res.end(), sort_vec);
    auto last = unique(res.begin(), res.end(), equal_vec);
    res.erase(last, res.end());
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  auto target = 8;
  vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
  auto m = s.combinationSum2(candidates, target);
  for (auto g : m) {
    for (auto s : g) {
      cout << s << " ";
    }
    cout << endl;
  }

  return 0;
}
