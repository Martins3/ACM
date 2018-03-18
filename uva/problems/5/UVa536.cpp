#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <forward_list>
#include <deque>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>
#include <climits>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("../output.txt", "w", stdout);

class Node{
public:
    Node * l = nullptr;
    Node * r = nullptr;
    char num;
};

char in_order[10000];
char post_order[10000]; // 这就是前面的顺序

/**
 * left and r included
 * n is alread alloc
 */
void make_tree(Node* n, int left, int right, int l, int r){
//    cout << left << " " << right << endl;
    if(left == right) {
        n -> num = in_order[left];
        return;
    }

    char num = post_order[l];
    int i;
    for(i = left; i <= right; i++){
        if(in_order[i] == num) break;
    }
    n -> num = in_order[i];
    
    if(left <= i - 1) {
        n -> l = new Node;
        // make_tree(n -> l, left, i - 1, l, l + ((i - 1) - left));
        make_tree(n -> l, left, i - 1, l + 1, l + 1 + ((i - 1) - left));
    }

    if(i + 1 <= right){
        n -> r = new Node;
        // make_tree(n -> r, i + 1, right, (r - 1) - (right - (i + 1)), r - 1);
        make_tree(n -> r, i + 1, right, r - (right - (i + 1)), r);
    }
}



void post_order_print(Node* & n){
    if(n -> l != nullptr) post_order_print(n -> l);
    if(n -> r != nullptr) post_order_print(n -> r);
    printf("%c", n -> num);
}

int main(){
    REOPEN_READ
    // REOPEN_WRITE
    while(true){
        if(scanf("%s %s", post_order, in_order) != 2) break;
        Node * root = new Node;
        int i = strlen(in_order);
        make_tree(root, 0, i - 1, 0, i - 1);
        post_order_print(root);
        printf("\n");
    }
    return 0;
}
