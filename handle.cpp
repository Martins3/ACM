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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/POJ.md", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/POJ.txt", "w", stdout);
char line[1000];
int main(){
    REOPEN_READ
    REOPEN_WRITE

    int nums = 0;
    vector<int> vec;
    while(fgets(line, 1000, stdin) != NULL){
        // 第一个空格，最后三个空格，替换为 |
        for(int i = 0; line[i] != '\0'; i++){
            if(line[i] == ' ') vec.push_back(i);
        }
        int len = vec.size();
        line[vec[0]] = '|';
        line[vec[len - 1]] = '|';
        line[vec[len - 2]] = '|';
        line[vec[len - 3]] = '|';
        line[vec[len - 4]] = '|';
        printf("%s", line);

        vec.clear();
    }
    cout <<  nums << endl;
    return 0;
}
