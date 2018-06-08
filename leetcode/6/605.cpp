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

class Solution {
public:
    int max_flowers(int c){
        c -= 2;
        if(c <= 0) return 0;
        return (c + 1) / 2;
    }

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int c = 1;
        flowerbed.push_back(0);
        flowerbed.push_back(1);
        int res = 0;
        for (int i = 0; i < flowerbed.size(); ++i) {
            int s = flowerbed[i];
            if(s == 0){
                c ++;
            }else{
                res += max_flowers(c);
                c = 0;
            }
        }
        return res >= n;
    }
};

int main(){
    REOPEN_READ
    REOPEN_WRITE
    return 0;
}
