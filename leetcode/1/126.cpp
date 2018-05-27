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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

class Comparator{
public:
    int omit_index;
    Comparator(int _omit_index) : omit_index(_omit_index){}
    inline bool operator() (const string & str1, const string & str2){
        int len = str1.size();
        for (int i = 0; i < len; ++i) {
            if(i == omit_index) continue;
            if(str1[i] == str2[i]) continue;
            if(str1[i] < str2[i]){
                return false;
            }else{
                return true;
            }
        }
        return true;
    }
};


class Solution {
public:
    vector<string> GetStrings;
    vector<vector<int> > graph;
    vector<bool> visited;
    vector<int> dis;
    vector<vector<int> > dfsTree;

    int getNum(const string & str){
        return lower_bound(GetStrings.begin(), GetStrings.end(), str) - GetStrings.begin();
    }

    bool isTransform(const string & str1, const string & str2, int omit){
        int len = str1.size();
        for (int i = 0; i < len; i++) {
            if(i == omit) continue;
            if(str1[i] != str2[i]) return false;
        }
        return true;
    }

    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // hash
        this->GetStrings  = wordList;
        sort(GetStrings.begin(), GetStrings.end());

        // make the graph
        graph = vector<vector<int> >(wordList.size(), vector<int>());
        int strLen = beginWord.length();
        int listLen = wordList.length():
        for (int i = 0; i < strLen; ++i) {
            sort(wordList.begin(), wordList.end(), Comparator(i));
            for (int w = 0; w < listLen - 1; ++w) {
                if(isTransform(wordList[w], wordList[w + 1], i)){
                    int a = getNum(wordList[w]);
                    int b = getNum(wordList[w + 1]);
                    graph[a].push_back(b);
                    graph[b].push_back(a);
                }
            }
        }

        // find the path

        vector<vector<string> > res;
        return res;
    }
};

int main(int argc, char *argv[]){
    REOPEN_READ
    REOPEN_WRITE
    return 0;
}
