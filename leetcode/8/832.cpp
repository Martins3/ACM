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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/OnlineJudge/output.txt", "w", stdout);


void flip_line(vector<int> & line){
    for (int i = 0; i < line.size() / 2; ++i) {
        int t = line[i];
        line[i] = line[line.size() - i - 1];
        line[line.size() - i - 1] = t;
    }
}

void flip_image(vector<vector<int> >& A){
    for (int i = 0; i < A.size(); ++i) {
        flip_line(A[i]);
    }
}

void invert_image(vector<vector<int> >& A){
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            A[i][j] = A[i][j] ^ 1;
        }
    }
}


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        flip_image(A);
        invert_image(A);
        return A;
    }
};

int main(){
//    REOPEN_READ
//   REOPEN_WRITE

    return 0;
}
