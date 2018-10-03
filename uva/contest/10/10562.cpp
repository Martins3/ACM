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

#define LEN (300)
char chars[LEN][LEN];
int N;
int depth;
int width;

/**
 * 只是需要知道是否的含有对应控制范围就可以
 * 读出来的所有的字符的位置，读出区间的控制范围
 * 然后直接在字符集和上面处理的, 问题就是如果的首先遇到了， 那么会误以为是含有的
 */
void read_tree(){
    char c = '\0';
    width = 0;
    depth = 0;
    while(true){
        c = getchar();
        if(width == 0 && c == '#') break;
        if(c =='\n'){
            chars[depth][width] = '\0';
            depth ++;
            width = 0;
            continue;
        }
        chars[depth][width ++] = c;  
    }
    getchar();
}


// 只有对于叶子才会调用的该数据
void dfs(int x, int y){
    // 查询当前的节点是不是leaf
    if(x + 1 == depth || chars[x + 1][y] != '|'){
        printf("%c()",chars[x][y]);
        return;
    }
    
    // 如果含有子节点
    int start = y;
    while(start >= -1 && chars[x + 2][start] == '-' ) start --;
    start ++;

    // 查询的字符的位置的， 只要不是空格都是可以的
    printf("%c(", chars[x][y]);
    while(chars[x + 2][start] == '-'){
        char c = chars[x + 3][start];
        if(c != ' ' && c != '\0' && c!= '#' && c != '|' && c != '-') dfs(x + 3, start);
        start ++;
    }
    printf(")");
}

void solve(){
    printf("(");
    for(int i = 0;chars[0][i] != '\0' && chars[0][i] != '-' && chars[0][i] != '|' && chars[0][i] != '#' ; i++){
        if(chars[0][i] != ' ') dfs(0, i);
    }
    printf(")\n");
}


int main(){
    REOPEN_READ
    REOPEN_WRITE
    scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; i++){
        memset(chars, 0, sizeof(char) * 300 * 300);
        read_tree();
        // for(int i = 0; i < depth; i++){
        //     printf("%s\n", chars[i]);
        // }
        solve();
    }
    return 0;
}