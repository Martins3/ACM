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

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

class Solution {
public:
  int numOfSubarrays(vector<int> &arr, int k, int threshold) {
    long long g = k * threshold;
    long long sum = 0;
    int res = 0;
    for (int i = 0; i < k; ++i) {
      sum += arr[i];
    }

    if (sum >= g)
      res++;

    for (int i = k; i < arr.size(); ++i) {
      sum -= arr[i - k];
      sum += arr[i];
      if (sum >= g)
        res++;
    }
    return res;
  }
};

int main() { return 0; }


// 
