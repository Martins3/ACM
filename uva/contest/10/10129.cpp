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

/**
 * 使用Euler： 
 * 使用简单的后序 遍历 然后实现， 加入到数值中间
 * 之所以不会出现， 只有处理结束之后才会处理对应的数值
 *  对于euler 路径的理解含有的问题， 输入输出的数目不可以相差的2 
 * 
 * 认为所有的单词的进入和出去的
 */
char not_ok []= "The door cannot be opened.";
char ok[] = "Ordering is possible.";
int test_case;
int words_num;
int front_end[100000][2];
int counter[26][2]; // 统计字母的个数，分别计算出来的度数

int uf[26];

int find(int x){
    if(uf[x] == -1) return x;
    uf[x] = find(uf[x]);
    return uf[x];
}
int union_node(int x, int y){
    int px = find(x);
    int py = find(y);
    if(px == py) return 0;

    uf[px] = py;
    return 1;
}


string line;
int main(){
    REOPEN_READ
    REOPEN_WRITE
    scanf("%d", &test_case);
    while(test_case --){
        memset(counter, 0, sizeof(counter[0][0]) * 26 * 2);
        memset(uf, -1, sizeof(uf));

        scanf("%d", &words_num);
        getchar();

        for(int i = 0; i < words_num; i++){
            getline(cin, line);
            int f = line[0] - 'a';
            int e =  line[line.size() - 1] - 'a';
            front_end[i][0] = f;
            front_end[i][1] = e;
            
            counter[f][0]++;
            counter[e][1]++;
        }

        // 计算所有的点出来度数，
        int odd = 0;
        int num1 = 0;
        int num2 = 0;
        bool fine = true;
        for(int i = 0; i < 26; i++){
            if(counter[i][1] != counter[i][0]){
                odd ++;
                if(counter[i][1] + 1 == counter[i][0]){
                   num1 ++;
                }else if(counter[i][1] - 1 == counter[i][0]){
                    num2 ++;
                } else{
                    fine = false;
                    break;
                }
            }
        }

        // 只要极点的个数小于的

        if(((num1 == 2 || num2 == 2) && odd == 2) || (odd > 2) || (!fine)){
            printf("%s\n", not_ok);
            continue;
        }


        int count = -1;
        for(int i = 0; i < 26; i++){
           if(counter[i][0] > 0 || counter[i][1] > 0) count ++;
        }

        fine = false;
        for(int i = 0; i < words_num; i++){
            if(union_node(front_end[i][0], front_end[i][1])) {
               count --;
            }
            if(!count) {
                fine = true;
                break;
            }
        }

        if(!fine){
            printf("%s\n", not_ok);
        }else{
            printf("%s\n", ok);
        }

    }  
    return 0;
}