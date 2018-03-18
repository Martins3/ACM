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

#define INF 0x3f3f3f3f
class Solution {
public:
    // 简单的dfs 
    vector<int> chars_pos[26];
    int key_len;
    int ring_len;
    string ring;
    string key;
    int min_dis; 

    // dp 表示 index　和
    
    int min_distance(int s, int t){
        if(s > t) swap(s, t); // s <= t
        int d = t - s;
        if(d > ring_len / 2){
            d = ring_len - d;
        }
        return d;
    }

    void get_pos(){
        for(int i = 0; i < ring.size(); i++){
            chars_pos[ring[i] - 'a'].push_back(i);
        }
    }

    void dfs(int index, int pos, int distance){
        if(index == key_len - 1) {
            min_dis = min(min_dis, distance);
            return;
        }
        
        for(int i: chars_pos[key[index + 1] - 'a']){
            dfs(index + 1, i, distance + min_distance(pos, i));
        }
    } 
    
    int findRotateSteps(string ring, string key) {
        this->ring = ring;
        this->key = key;
        key_len = key.size();
        ring_len = ring.size(); 
        min_dis = INF;


        get_pos();  
        dfs(-1, 0, 0);
        return min_dis + key_len;
    }
};

int main(){
    REOPEN_READ
    // REOPEN_WRITE
    Solution s;
    string a = "caotmcaataijjxi";
    string b = "oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx";
    cout << s.findRotateSteps(a, b) << endl;
    return 0;
}

/**
 * １．　出现了搜索重复的情况，　但是没有处理过
 * ２．　
 */