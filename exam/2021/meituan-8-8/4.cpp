#include <bits/stdc++.h>
#include "leetcode/dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/core/ACM/a.txt", "r", stdin);

#define GG (10000 + 10)

int bfs(int start, vector<bool> &visited, vector<set<int>> &edges) {
  vector<int> nums;
  nums.push_back(start);

  int res = 0;

  while (!nums.empty()) {
    int num = nums.back();
    nums.pop_back();
    if(visited[num]) continue;

    visited[num] = true;
    res ++;

    for (int i : edges[num]) {
      if(visited[i]) continue;
      nums.push_back(i);
    }
  }

  dbg(res);
  dbg(start);
  return res - 1;
}

int main(int argc, char *argv[]) {
  REOPEN_READ

  vector<set<int>> edges(GG, set<int>());
  int N;
  scanf("%d", &N);
  vector<int> nums;
  while (N--) {
    int tmp;
    scanf("%d", &tmp);
    nums.push_back(tmp);
  }
  int LEN = nums.size() / 2;
  for (int i = 0; i < LEN; ++i) {
    int j = i + LEN;
    if (nums[i] != nums[j]) {
      edges[nums[i]].insert(nums[j]);
      edges[nums[j]].insert(nums[i]);
    }
  }

  dbg(edges);

  vector<bool> visited(GG, false);
  int res = 0;

  for (int i = 0; i < GG; ++i) {
    if (visited[i])
      continue;
    if (edges[i].empty())
      continue;

    res += bfs(i, visited, edges);
  }
  printf("%d\n", res);
  return 0;
}
