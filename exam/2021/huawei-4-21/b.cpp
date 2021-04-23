#include <bits/stdc++.h>
// #include "leetcode/dbg.hpp"
using namespace std;

#define REOPEN_READ freopen("/home/maritns3/core/ACM/a.txt", "r", stdin);

bool dfs(const vector<vector<int>> &edges, vector<bool> &visited,
         vector<bool> &instack, int v) {
  if (visited[v])
    return false;

  visited[v] = true;
  instack[v] = true;

  for (auto nei : edges[v]) {
    if (instack[nei])
      return true;

    if (dfs(edges, visited, instack, nei)) {
      return true;
    }
  }
  instack[v] = false;
  return false;
}

int main(int argc, char *argv[]) {
  // REOPEN_READ
  int M;
  int N;
  scanf("%d", &M);
  scanf("%d", &N);
  vector<vector<int>> edges(M);
  vector<bool> isolated(M, true);
  for (int i = 0; i < N; ++i) {
    int a;
    int b;
    scanf("%d %d", &a, &b);
    edges[a].push_back(b);
    isolated[a] = false;
    isolated[b] = false;
  }

  int credit = 10;
  for (int i = 0; i < M; ++i) {
    if (isolated[i])
      credit--;
  }

  vector<bool> visited(M, false);

  for (int i = 0; i < M; ++i) {
    vector<bool> instack(M, false);
    if (dfs(edges, visited, instack, i)) {
      credit -= 2;
      break;
    }
  }

  printf("%d\n", credit > 0 ? credit : 0);

  return 0;
}
