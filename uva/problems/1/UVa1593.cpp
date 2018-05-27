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
#include <cstdio>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

/**
 * 每一行的单词个数不一致
 *
 */

void get_words(vector<string> & vec, char * line){
    int left = 0;
    int right = 0;

    while(line[left] != '\n'){
        while(line[left] != '\n'){
           if(!isspace(line[left])) break;
           left ++;
        }
        right = left;
        while(!isspace(line[right])) right ++;
        // not included right
        string word(line + left, line + right);
        // line may maybe end with space
        if(word.size()) vec.push_back(word);
        // find the next word
        left = right;
    }
}

char line[300];
char word[100];


int main(){
    REOPEN_READ
    REOPEN_WRITE

    vector<vector<string> > doc;
    while(fgets(line, 300, stdin) != NULL){
        vector<string> vec;
        get_words(vec, line);
        doc.push_back(vec);
    }


    unsigned col = 0;
    for (unsigned i = 0; i < doc.size(); ++i) {
        col = max(col, (unsigned)doc[i].size());
    }
    unsigned row = doc.size();

    vector<int> start(col, 0);

    for (unsigned i = 0; i < col; ++i) {
        unsigned max_len = 0;
        for (unsigned j = 0;  j < row; j++) {
            if(i < doc[j].size())
                max_len = max(max_len, (unsigned)doc[j][i].size());
        }
        start.push_back(max_len);
    }

    for (unsigned i = 1; i < start.size(); ++i) {
        start[i] += start[i - 1];
    }

    char output[10000];
    for (unsigned i = 0; i < doc.size(); ++i) {

        memset(output, 0, sizeof(output));
        for (unsigned j = 0; j < doc[i].size(); ++j) {
            int s = i == 0 ? 0 : start[i - 1];
            strcpy(output + s, doc[i][j].c_str());
        }
        printf("%s", output);
    }


    return 0;
}
