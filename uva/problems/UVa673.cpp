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
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

int N;
int main(){
    REOPEN_READ
    REOPEN_WRITE
    scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; i++){
       string line;
       getline(cin, line); 
       stack<int> s;
        
        bool ok = true;
       for(int j = 0; j < line.size(); j++){
           switch(line[j]){
               case '(':
                    s.push(0);
                    break;
               case ')':
                    if(!s.empty() && s.top() == 0)
                        s.pop();
                    else
                        ok = false;
                    break;
               case '[':
                    s.push(1);
                    break;
               case ']':
                    if(!s.empty() && s.top() == 1)
                        s.pop();
                    else
                        ok = false;
                    break;
           }
           if(ok == false) break;
       }
       if(ok && s.empty())
        printf("Yes\n");
        else
        printf("No\n");
    } 
    return 0;
}