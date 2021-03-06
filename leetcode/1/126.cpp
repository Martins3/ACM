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
#include "../info.hpp"

using namespace std;
class Solution {
public:
    bool check(const string & str1, const string & str2){
        // cout << str1 << " " << str2 << endl;
        int c = 0;
        for (int i = 0; i < str1.size(); ++i) {
            if(str1[i] != str2[i]) c++;
            if(c == 2){
                return false;
            }
        }
        return c == 1;
    }

    void findPath(vector<vector<string> > & res, vector<vector<int> > adj, vector<string> & wordList,
            vector<int> distance, int node, vector<string> & path){
        path.push_back(wordList[node]);

        if(distance[node] == 0) res.push_back(path);

        for(int nei : adj[node]){
            if(distance[nei] + 1 == distance[node]){
                findPath(res, adj, wordList, distance, nei, path);
            }
        }
        path.pop_back();

    }

    vector<vector<string> > ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        vector<vector<int> > adj(wordList.size(), vector<int>());
        vector<bool> visited(wordList.size(), false);
        vector<int> distance(wordList.size(), -1);

        int size = wordList.size();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if(i == j) continue;
                if(check(wordList[i], wordList[j])){
                    adj[i].push_back(j);
                }
            }
        }

        vector<vector<string> > res;
        int begin = -1;
        int end = -1;
        for (int i = 0; i < size; ++i) {
            if(wordList[i] ==  beginWord) begin = i;
            if(wordList[i] ==  endWord) end = i;
        }

        if(begin == -1 || end == -1) return res;


        queue<int> q;
        visited[begin] = true;
        int dis = 0;
        distance[begin] = dis;
        q.push(begin);

        // 确定距离
        while(!q.empty()){
            dis ++;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int cur =  q.front();
                q.pop();
                for(int nei : adj[cur]){
                    if(!visited[nei]){
                        visited[nei] = true;
                        q.push(nei);
                        distance[nei] = dis;
                    }
                }
            }
        }

        // 使用深度优先搜索实现多有路查询， 利用stack的技术

        vector<string> path;
        findPath(res, adj, wordList, distance, end, path);
        for(vector<string> & v : res){
            reverse(v.begin(), v.end());
            print_v(v);
        }
        return res;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    vector<string> v{"hot","dot","dog","lot","log","cog"};
    s.ladderLength("hit", "cog", v);
    return 0;
}
