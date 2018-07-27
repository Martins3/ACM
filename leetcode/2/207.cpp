#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
#include <cassert>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/ACM/leetcode/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/ACM/leetcode/output.txt", "w", stdout);

/**
 * 完全理解错误 :
 * runtimeVisited 用于表示在stack中间的。
 * visited: 表示访问该点不可能找到环。
 *
 */
class Solution {
public:

    bool findCycle(int node, vector<vector<int> > & graph, vector<bool> & visited, vector<bool> & runtimeVisited){
        if(runtimeVisited[node]) return true;
        if(visited[node]) return false;

        runtimeVisited[node] = true;
        visited[node] = true;

        for(int n : graph[node]){
            if(findCycle(n, graph, visited, runtimeVisited)) return true;
        }

        runtimeVisited[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<vector<int> > graph(numCourses, vector<int>());
        for(auto & v : prerequisites){
            graph[v.first].push_back(v.second);
        }

        vector<bool> runtimeVisited(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if(visited[i]) continue;
            fill(runtimeVisited.begin(), runtimeVisited.end(), false);
            if(findCycle(i, graph, visited, runtimeVisited)) return false;
        }
        return true;
    }
};

int main(){
    // REOPEN_READ
    // REOPEN_WRITE

    Solution s;
    vector<pair<int, int> > p;
    p.push_back(make_pair<int, int>(0, 1));
    p.push_back(make_pair<int, int>(0, 2));
    p.push_back(make_pair<int, int>(1, 2));
    cout << s.canFinish(3, p);

    return 0;
}
