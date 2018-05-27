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
class Node{
public:
    int num;
    char c;
    Node * left;
    Node * right;
    Node(int _num, char _c):num(_num), c(_c), left(nullptr), right(nullptr){}
};

class Comparator{
    public:
    inline bool operator() (const Node& a, const Node& b) {
       return a.num < b.num;
    }
};

std::priority_queue<Node, std::vector<Node>, Comparator() > node_heap; 



char counter[26];
int main(int argc, char *argv[]){
    REOPEN_READ
    REOPEN_WRITE
    char c;
    while(scanf("%c", &c)) counter[c - 'a'] ++;
    
    for(int i = 0; i < 26; i++){
        if(counter[i] > 0){
            node_heap.push(Node(counter[i], 'a' + i));
        }
    }

    Node root(0, '1'); // root ???
    while(node_heap.size() > 1){
        Node a = node_heap.top(); node_heap.pop();
        Node b = node_heap.top(); node_heap.pop();
    }
    return 0;
}
