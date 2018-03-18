#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("../output.txt", "w", stdout);

int trains[1000];
int p;


int main(){
    int Range;
    REOPEN_READ
    REOPEN_WRITE
    while(true){
        scanf("%d", &Range);
        if(Range == 0) break;
        
        while(true){
            p = 0;
            bool is_end = false;
            for(int i = 0; i < Range; i++){
                scanf("%d", &(trains[p++]));
                if(trains[p - 1] == 0){
                    is_end = true;
                    break;
                }
            }
            if(is_end) break;
            
            stack<int> s;


            // 一个一个添加， stack 上面的元素满足
            // 当没有元素可以添加， 而stack 的大小不为空
            int T = Range;
            for(int i = Range - 1; i >= 0; i--){
                s.push(trains[i]);
                
                while(!s.empty() && s.top() == T) {
                    T --;
                    s.pop();
                }
            }

            if(s.empty())
                printf("%s\n", "Yes");
            else
                printf("%s\n", "No");
        }
        
        printf("\n");
    }
    return 0;
}