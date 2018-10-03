#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <forward_list>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("../output.txt", "w", stdout);

// 讲特殊的元素全部替换为的空格即可
int main(){
    set<string> s;
    string line;
    while(getline(cin, line)){
        for(int i = 0; i < line.size(); i++){
            if(isalpha(line[i])){
                line[i] = tolower(line[i]);
            }else{
                line[i] = ' ';   
            }
        } 
        string word;
        stringstream ss(line);
        while(ss >> word) s.insert(word);
    }
    for(auto i = s.cbegin(); i != s.cend() ; i++){
        cout << *i << endl;
    }
    return 0;
}