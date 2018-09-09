#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include <stdlib.h> // sort


char pre[30];
char mid[30];

struct Node{
    char val;
    struct Node * left;
    struct Node * right;
};

typedef struct Node * NodePtr;

NodePtr init_node(char val){
    NodePtr n = (NodePtr)malloc(sizeof(struct Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}


// 长度为０　是否计算
NodePtr build(int a, int b, int x, int y){
    if(a == b)
        return init_node(pre[a]);
    if(a > b)
        return NULL;

    NodePtr m = init_node(pre[a]);
    int i;
    for (i = x; i <= y; ++i) {
        if(pre[a] == mid[i])
            break;
    }

    m->left = build(a + 1, a + 1 + (i - 1) - x, x, i - 1);
    m ->right = build(a + 1 + (i - 1) - x + 1, b,  i + 1, y);
    return m;
}

void print(NodePtr n){
    if(n == NULL) return;
    print(n->left);
    print(n->right);
    printf("%c", n->val);
}

int main(){
    while(scanf("%s %s",pre, mid) == 2){

        printf("%s\n",pre);
        printf("%s\n",mid);
        print(build(0, strlen(pre) - 1, 0, strlen(mid) - 1));
        printf("\n");

        memset(pre, 0, 30 * sizeof(char));
        memset(mid, 0, 30 * sizeof(char));
    }
    return 0;
}
