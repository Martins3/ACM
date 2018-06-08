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
#include <unordered_map>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/OnlineJudge/output.txt", "w", stdout);

class Solution {
public:
    void make_map(unordered_map<string, int>&  m, vector<string>& v){
        for (int i = 0; i < v.size(); i++) {
            m[v[i]] = i;
        }
    }

    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        std::unordered_map<string, int> map1;
        std::unordered_map<string, int> map2;
        make_map(map1, list1);
        make_map(map2, list2);

        vector<string> res;
        int dis = 0x3f3f3f3f;
        for(auto i = map1.begin(); i != map1.end(); i++){
            auto j = map2.find(i->first);
            if(j !=  map2.end()){
                int d = i->second + j->second;
                if(d == dis){
                    res.push_back(i->first);
                }else if(d < dis){
                    res.clear();
                    res.push_back(i->first);
                    dis = d;
                }
            }
        }
        return res;
    }
};
int main(){
//    REOPEN_READ
//   REOPEN_WRITE


    return 0;
}
