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

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);





/**
 * 注意空格的问题
 */

int main(){
    REOPEN_READ

    char c;
    int len = 0;
    int inWord = 0;
    int first_world = 1;
    while((c = getchar()) != EOF){
        switch(c){
            case ' ':
                if(inWord){
                    printf("%d", len);
                    inWord = 0;
                }
                break;

            case '.':
                getchar(); // 马上处理掉后面的数值
                if(inWord){
                    printf("%d", len);
                    inWord = 0;
                }
                printf("\n");
                first_world = 1;
                break;

            default:
                if(inWord){
                    len ++;
                }else{
                    if(!first_world){
                        printf(" ");
                    }else{
                        first_world = 0;
                    }
                    inWord = 1;
                    len = 1;
                }
                break;
        }
    }
    
    return 0;
}
