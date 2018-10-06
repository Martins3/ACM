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
 * Longest Common Sequence
 * dp[i][j] is simple brute force !
 * https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
 *
 */

#define LEN 22
int dp[LEN][LEN];

int LCS(vector<int>& a, vector<int>& b, int x, int y){
    // printf("%d %d\n", x, y );
    if(x < 0 || y < 0) return 0;

    if(dp[x][y] != -1) return dp[x][y]; 

    if(a[x] == b[y]){
        dp[x][y] = LCS(a, b, x- 1, y - 1) + 1;
    }else{
        dp[x][y] = max(LCS(a, b, x - 1, y), LCS(a, b, x, y - 1));
    }
    return dp[x][y];
}


vector<int> read_line(){
    string line;
    vector<int> res;
    if(getline(cin, line)){
        int a;
        std::istringstream iss(line);
        while(iss >> a){
            res.push_back(a);
        }
    }
    return res;
}

int main(){
    REOPEN_READ
    REOPEN_WRITE

    vector<int> line;

    vector<int> ans;
    while(!(line = read_line()).empty()){
        if(line.size() == 1){
            ans.clear();
            continue;
        } 

        if(ans.empty()){
            ans = vector<int>(line.size());
            for (int i = 0; i < line.size(); i++) {
                ans[line[i] - 1] = i + 1;
            }
            
            // for (int i = 0; i < line.size(); i++) {
                // cout << line[i] << " | ";
            // }
            // cout << endl;

        }else{
            // for (int i = 0; i < line.size(); i++) {
                // cout << line[i] << " ";
            // }
            // cout << endl;
            
            memset(dp, -1, sizeof(dp));

            vector<int> sans(line.size());
            for (int i = 0; i < line.size(); i++) {
                sans[line[i] - 1] = i + 1;
            }
            
            printf("%d\n", LCS(ans, sans,  line.size() - 1, line.size() - 1));

            // for (int i = 0; i < LEN; i++) {
                // for (int j = 0; j < LEN; j++) {
                    // printf("%d ", dp[i][j]);
                // }
                // printf("\n");
            // }
            
        }
    }
    return 0;
}
