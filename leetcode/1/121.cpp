#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() < 2)
      return 0;

    int max_val = prices.back();
    int res = 0;
    for (int i = prices.size() - 2; i >= 0; i--) {
      max_val = max(prices[i], max_val);

      res = max(res,  max_val - prices[i]);
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
