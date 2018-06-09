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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/OnlineJudge/output.txt", "w", stdout);


class TrieNode{
public:
    map<char, TrieNode *> children;
    bool isEnd;
    TrieNode(): isEnd(false){}
};

class Solution {
public:
    void insert(TrieNode* curNode, const string & str){
        for (char s : str) {
            auto f = curNode->children.find(s);
            if(f == curNode->children.end()){
                curNode->children[s] = new TrieNode();
            }
            curNode = curNode->children[s];
        }
        curNode->isEnd = true;
    }

    string res;
    void query(string & q, TrieNode * curNode){
        for(auto iter = curNode->children.begin(); iter != curNode->children.end(); iter ++){
            if(iter->second->isEnd){
                q.push_back(iter->first);

                query(q, iter->second);
                if(q.size() > res.size()){
                    res = q;
                }
                q.pop_back();
            }
        }
    }

    string longestWord(vector<string>& words) {
        TrieNode * root = new TrieNode();
        for(string s : words){
            insert(root, s);
        }
        string q;
        query(q, root);
        return res;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    Solution s;
    vector<string> v{"w","wo","wor","worl", "world", "worlk"};
    cout << s.longestWord(v) << endl;
    return 0;
}
