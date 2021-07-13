#include "../dbg.hpp"
#include <bits/stdc++.h>
using namespace std;

#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

class Solution {
  int summary(vector<int> &v) {
    int res = 0;
    for (int i = 0; i < v.size(); ++i) {
      res += v[i];
    }
    return res;
  }

  int get_one_intersection(vector<int> &a, vector<int> &b) {
    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < b.size(); ++j) {
        if (a[i] == b[j])
          return a[i];
      }
    }
    return -1;
  }

  int get_coin_pos(vector<int> &coins, int coin) {
    for (int i = 0; i < coins.size(); ++i) {
      if (coins[i] == coin)
        return i;
    }
    assert(false);
  }

  void print_vec(vector<int> &vec) {
    for (auto v : vec) {
      cout << v << " ";
    }
    cout << endl;
  }

public:
  int coinChange(vector<int> &coins, int amount) {
    // 一遍是修改, 一遍是增减, 最多增加一个

    vector<vector<int>> solutions;
    sort(coins.begin(), coins.end());

    int max_diff = -1;
    if (coins.size() >= 2) {
      max_diff = coins[coins.size() - 1] - coins[0];
    }

    map<int, vector<int>> diff_map; // 给出 diff
    for (int i = 0; i < coins.size(); ++i) {
      for (int j = i + 1; j < coins.size(); ++j) {
        int diff = coins[j] - coins[i];

        auto ptr = diff_map.find(diff);
        if (ptr != diff_map.end()) {
          ptr->second.push_back(coins[i]);
        } else {
          diff_map[diff] = vector<int>{coins[i]};
        }
      }
    }

    solutions.push_back(vector<int>(coins.size()));

    for (int i = 1; i < amount; ++i) {
      printf("huxueshi:%s %d ---------\n", __FUNCTION__, i);
      print_vec(solutions[i - 1]);
      bool solution_found = false;
      if (max_diff != -1) {
        for (int d = 1; d <= max_diff; ++d) {
          int left = i - d;
          if (left < 0)
            continue;

          vector<int> left_solution = solutions[left];
          if (left_solution.empty())
            continue;

          auto diff = diff_map.find(d);
          if (diff == diff_map.end())
            continue;

          int intersection = get_one_intersection(diff->second, left_solution);
          if (intersection != -1) {
            vector<int> solution = left_solution;

            int a = get_coin_pos(coins, intersection);
            int b = get_coin_pos(coins, intersection + diff->first);
            if (solution[a] == 0)
              continue;

            solution[a]--;
            solution[b]++;
            solution_found = true;
            solutions.push_back(solution);
          }
        }
      }
      if (solution_found)
        continue;

      // 没办法，只能靠添加一个
      for (int c = 0; c < coins.size(); ++c) {
        int d = coins[c];
        int left = i - d;
        if (left < 0)
          continue;

        if (solutions[left].empty())
          continue;

        vector<int> solution = solutions[left];
        solution[c]++;
        solutions.push_back(solution);
        solution_found = true;
      }

      if (solution_found)
        continue;

      // 添加也没有办法，只能使用一个数值
      solutions.push_back(vector<int>());
    }

    vector<int> &res = solutions[amount];
    if (res.empty()) {
      return -1;
    }
    return summary(res);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  auto v = vector<int>{1, 2, 5};
  s.coinChange(v, 11);

  return 0;
}
