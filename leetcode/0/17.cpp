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
  vector<char> characters(char i) {
    switch (i) {
    case '2':
      return vector<char>{'a', 'b', 'c'};
    case '3':
      return vector<char>{'d', 'e', 'f'};
    case '4':
      return vector<char>{'g', 'h', 'i'};
    case '5':
      return vector<char>{'j', 'k', 'l'};
    case '6':
      return vector<char>{'m', 'n', 'o'};
    case '7':
      return vector<char>{'p', 'q', 'r', 's'};
    case '8':
      return vector<char>{'t', 'u', 'v'};
    case '9':
      return vector<char>{'w', 'x', 'y', 'z'};
    default:
      exit(12);
    }
  }

  void cons(const string digits, int len, vector<string> &res, vector<char> & str) {
    if (len == digits.size()){
      res.push_back(string(str.begin(), str.end()));
      return;
    }
    auto chars = characters(digits[len]);
    for (int i = 0; i < chars.size(); ++i) {
      str.push_back(chars[i]);
      cons(digits, len + 1, res, str);
      str.pop_back();
    }
  }

  vector<string> letterCombinations(string digits) {
    vector<string> res;
    vector<char> str;
    if(digits.empty()) return res;
    cons(digits, 0, res, str);
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  auto x = s.letterCombinations("");
  for(auto xi: x){
    cout << xi << endl;
  }
  return 0;
}
