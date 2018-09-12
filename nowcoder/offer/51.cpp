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
#include <unordered_map>

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

/**
 * 有什么高深的东西吗?
 *
 *
 */

int F[256];

class Solution {
public:
    queue<char> q;
    //Insert one char from stringstream
    void Insert(char ch){
        unsigned off = (unsigned)ch;
        if(F[off] == 0){
            F[off] = 1;
            q.push(ch);
        }else if(F[off] == 1){
            F[off] = -1;
        }
    }

    //return the first appearence once char in current stringstream
    char FirstAppearingOnce(){
        while(!q.empty()){
            char c = q.front();
            unsigned off = q.front();
            if(F[off] == -1){
                q.pop();
                continue;
            }
            return c;
        }

        return '#';
    }
};

int main(){
    
    return 0;
}
