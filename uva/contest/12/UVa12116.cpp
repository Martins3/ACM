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
class Node{
public:
    int num;
    Node * l = nullptr;
    Node * r = nullptr;
    Node() = default;
    Node(int num): num(num){};
};
const char * str;
Node * make_tree(int left, int right){
    if(str[left] != '['){
        int num;
        sscanf(str, "%d", &num);
        return new Node(num);
    }

    // 划分势力， 实现区分的const and expr
    // 如果是的表达式， 那么必定是 【】在lefe and right 的位置
    int in = 0;
    int i;
    for(i = left + 1; i < right; i++){
        if(str[i] == '[') in++;
        if(str[i] == ']') in--;
        if(str[i] == ',' && in == 0) break;
    }
    Node * t = new Node();
    t -> l =  make_tree(left + 1, i - 1);
    t -> r = make_tree(i + 1, right);
    return t;
}

// 
int post_order(Node * n){

}

int main(){
   REOPEN_READ
   REOPEN_WRITE

    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        string line; 
        getline(cin, line);
        str = line.c_str(); 
        Node * root = make_tree(0, line.size() - 1);

        // 使用后序遍历
    }

    return 0;
}