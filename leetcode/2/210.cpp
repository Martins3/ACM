#include <bits/stdc++.h>
using namespace std;
#include "../dbg.hpp"
#include "../info.hpp"

#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

// 检查环路的存在不是靠 visited ，而是靠 stack 的
class Solution {

public:
  bool dfs(const vector<vector<int>> &edges, vector<int> &ans, int v,
           vector<bool> &visited, vector<bool> &localvisited) {

    if (localvisited[v])
      return true;
    if (visited[v])
      return false;

    visited[v] = true;
    localvisited[v] = true;
    for (auto child : edges[v]) {
      if (dfs(edges, ans, child, visited, localvisited))
        return true;
    }
    ans.push_back(v);
    localvisited[v] = false;
    return false;
  }

  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {

    vector<bool> visited(numCourses, false);

    vector<vector<int>> edges(numCourses);

    for (auto e : prerequisites) {
      int x = e[0];
      int y = e[1];
      edges[x].push_back(y);
    }

    vector<int> ans;

    for (int i = 0; i < numCourses; ++i) {
      if (visited[i])
        continue;

      vector<bool> localvisited(numCourses, false);

      if (dfs(edges, ans, i, visited, localvisited)) {
        return vector<int>();
      }
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int>> a{{0, 1}, {0, 2}, {1, 2}};
  dbg(s.findOrder(3, a));
  return 0;
}
