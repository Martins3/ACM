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
 * weights must be strictly increasing, and IQs must be strictly decreasing
 * exclude same elephent
 * We can not understand it !
 */

struct Ele{
    int i;
    int size;
    int IQ;
};

struct Comp{
    inline bool operator ()(const Ele & a, const Ele & b){
        if(a.size > b.size) return true;
        if(a.size < b.size) return false;

        return a.IQ > b.IQ;
    }
};

int main(){
    int size;
    int IQ;

    while(scanf("%d %d", &size, &IQ) == 2){

    }
    return 0;
}
