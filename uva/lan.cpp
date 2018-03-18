#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <forward_list>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

class Bucket{
public:
    int doc;
    set<int> lines;
    bool operator < (const Bucket & b) const {
        return doc < b.doc; 
    }
    Bucket(){}
    Bucket(int doc): doc(doc){};
};

int main(){
    REOPEN_READ
    
    map<string, set<Bucket> > google;
    set<Bucket> s;
    Bucket b(10);
    b.lines.insert(123); 
    s.insert(b);
    google.insert(make_pair("a",s));
    auto sf = google["a"];
    auto bf = sf.find(Bucket(10));

    set<int> s;
    
    return 0;
}