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
#include <unordered_set>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/OnlineJudge/output.txt", "w", stdout);


class TrieNode{
public:
    map<char, TrieNode *> children;
    bool isEnd;
    int val;
    TrieNode(): isEnd(false){}
};


class MapSum {
public:

    TrieNode * root;

    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        TrieNode * curNode = root;
        for(char s : key){
            auto f = curNode->children.find(s);
            if(f == curNode->children.end()){
                curNode->children[s] = new TrieNode();
            }
            curNode = curNode->children[s];
        }
        curNode->isEnd = true;
        curNode->val = val;

    }

    void query(TrieNode * curNode, int & res){
        if(curNode->isEnd) res += curNode->val;
        for(auto iter = curNode->children.begin(); iter != curNode->children.end(); iter ++){
            query(iter->second, res);
        }
    }


    int sum(string prefix) {
        int res = 0;
        TrieNode * curNode = root;
        for(char s : prefix){
            auto f = curNode->children.find(s);
            if(f == curNode->children.end()){
                return 0;
            }
            curNode = curNode->children[s];
        }
        query(curNode, res);
        return res;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    MapSum s;
    s.insert("apple", 3);
    s.insert("app", 4);
    cout << s.sum("app") << endl;
    cout << s.sum("appl") << endl;
    cout << s.sum("appleg") << endl;

    return 0;
}
