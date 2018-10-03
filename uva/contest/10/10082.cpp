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
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("../output.txt", "w", stdout);

char keyboard[30][30] = {
{'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=' },
{'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\' },
{'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', '*', '*' },
{'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/', '*', '*', '*' }
};

class Loc{
public:
    int x;
    int y;
    Loc(int x, int y): x(x), y(y){};
    Loc() = default;
};

Loc locations[1000];


int main(){
    REOPEN_READ

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            locations[keyboard[i][j]] = Loc(i, j);
        }
    }
    string line;
    while(getline(cin, line)){
        for(int i = 0; i < line.size(); i++){
            if(line[i] == ' ') continue;
            line[i] = keyboard[locations[line[i]].x][locations[line[i]].y - 1];
        }
        cout << line << endl;
    }
    
    return 0;
}