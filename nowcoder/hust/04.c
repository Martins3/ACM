#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..

struct Node {
    int val;
    struct Node * left;
    struct Node * right;
};

typedef struct Node * NodePtr;

int main(){
    int N;
    scanf("%d", &N);

    NodePtr root = NULL;
    while(N --){
        int val;
        scanf("%d", &val);

        if(root == NULL){
            root = (NodePtr)malloc(sizeof(struct Node));
            root->left = NULL;
            root->right = NULL;
            root->val = val;
            printf("%d\n", -1);
        }else{
            NodePtr cur = root;
            NodePtr res;

            while(cur != NULL){
                res = cur;
                if(val > cur->val){
                    cur = cur->right;
                }else{
                    cur = cur->left;
                }
            }
            

            cur = (NodePtr)malloc(sizeof(struct Node));
            cur->left = NULL;
            cur->right = NULL;
            cur->val = val;

            if(val > res->val){
                res->right = cur;
            }else{
                res->left = cur;
            }

            printf("%d\n", res->val);
        }
    }
    return 0;
}
