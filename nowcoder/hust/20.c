#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include<stdlib.h> // sort
#include<limits.h> // INT_MAX

struct Node{
    int val;
    struct Node * left;
    struct Node * right;
};

typedef struct Node * NodePtr;
NodePtr root;

NodePtr init_node(int val){
    NodePtr root = (NodePtr)malloc(sizeof(struct Node));
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void insert(int val){
    if(root == NULL){
        root = init_node(val);
        return;
    }
    NodePtr cur = root;
    NodePtr last;
    while(cur != NULL){
        last = cur;

        if(val > cur->val){
            cur = cur->right;
        }else if(val < cur->val){
            cur = cur->left;
        }else{
            return;
        }
    }

    cur = init_node(val);

    if(val > last->val){
        last->right = cur;
    }else{
        last->left = cur;
    }
}


void pre(NodePtr n){
    if(n == NULL) return;
    printf("%d ",  n->val);
    pre(n->left);
    pre(n->right);
}

void mid(NodePtr n){
    if(n == NULL) return;
    mid(n->left);
    printf("%d ",  n->val);
    mid(n->right);
    
}

void last(NodePtr n){
    if(n == NULL) return;
    last(n->left);
    last(n->right);
    printf("%d ",  n->val);
}

int main(){
    int N;
    while(scanf("%d", &N) == 1){
        int t;
        root = NULL;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &t); 
            insert(t);
        }

        pre(root); printf("\n");
        mid(root); printf("\n");
        last(root); printf("\n");
    }
    return 0;
}
