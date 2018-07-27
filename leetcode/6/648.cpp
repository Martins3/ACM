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

class DisjointSet{
public:
    int * arr;

    DisjointSet(int size){
        arr = new int[size + 1];
        memset(arr, 0, sizeof(int) * (size + 1));
    }

    int find(int x){
        if(arr[x]) return arr[x] = find(arr[x]);
        return x;
    }

    void union_pair(int x, int y){
        x = find(x);
        y = find(y);
        arr[y] = x;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet D(edges.size());
        vector<int> a;
        for(auto & e : edges){
            int x = D.find(e[0]);
            int y = D.find(e[1]);
            if(x == y){
                a = e;
                break;
            }else{
                D.union_pair(e[0], e[1]);
            }
        }
        return a;
    }
};
int main(){
    // REOPEN_READ
    // REOPEN_WRITE

    return 0;
}
