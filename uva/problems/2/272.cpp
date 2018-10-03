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

int main(){
    REOPEN_READ
    REOPEN_WRITE
    char c;
    bool is = true;
    while((c = getchar()) != EOF){
        if(c == '\"'){
            if(is){
                putchar('`');
                putchar('`');
            }else{
                putchar('\'');
                putchar('\'');
            }
            is = !is;
        }else{
            putchar(c);
        }
    } 
    return 0;
}