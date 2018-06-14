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

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        vector<vector<int> > adj(wordList.size(), vector<int>());
        vector<bool> visited(wordList.size(), false);

        int size = wordList.size();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if(i == j) continue;
                if(check(wordList[i], wordList[j])){
                    adj[i].push_back(j);
                    // cout << i  << "  " <<  j << endl;
                }
            }
        }

        int begin = -1;
        int end = -1;
        for (int i = 0; i < size; ++i) {
            if(wordList[i] ==  beginWord) begin = i;
            if(wordList[i] ==  endWord) end = i;
        }

        if(begin == -1 || end == -1) return 0;


        queue<int> q;
        visited[begin] = true;
        q.push(begin);

        int res = 1;
        while(!q.empty()){
            int size = q.size();
            res ++;
            for (int i = 0; i < size; ++i) {
                // 感染周围节点
                int cur =  q.front();
                q.pop();
                for(int nei : adj[cur]){
                    if(nei == end) return res;
                    if(!visited[nei]){
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }
        }

        return 0;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    vector<string> v{"hot","dot","dog","lot","log","cog"};
    cout << s.ladderLength("hit", "cog", v);
    return 0;
}
