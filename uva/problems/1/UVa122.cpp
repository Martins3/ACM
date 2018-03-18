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

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("../output.txt", "w", stdout);

class Node{
public:
    int num;
    int valid = -1;
    Node * left = nullptr;
    Node * right = nullptr;
};

Node * root;

int readNode(){
    int c = ' ';
    while(c == ' ' || c == '\n') {
        c = getchar();
        if(c == EOF) return -1;     
    }
    return 0;
}


char line[1000];
Node * nodes[300];
void addNode(Node* n, int num, char * c){
    if(*c == ')'){
        n -> num = num;
        n -> valid ++;
        return;
    }else if(*c == 'L'){
        if(n -> left == nullptr) n -> left = new Node;
        addNode(n -> left, num, c + 1);
    }else{
        if(n -> right == nullptr) n -> right = new Node;
        addNode(n -> right, num, c + 1);
    }
}
int main(){
    REOPEN_READ
    REOPEN_WRITE
    while(true){
        bool over = false;
        root = new Node;
        memset(nodes, 0, sizeof(nodes));
        memset(line, 0, sizeof(line));

        while(true){
            if(scanf("%s", line) == EOF) {
                over = true; 
                break;
            }
            int num;
            sscanf(line + 1, "%d", &num);
            
            if(strcmp(line, "()") == 0) break;
            char * c = strchr(line, ',');
            addNode(root, num, c + 1);
        }
        if(over) break;
        
        queue<Node *> Q;
        queue<Node *> res;
        Q.push(root);
        res.push(root);
        bool vaild = true;

        while(!Q.empty()){
            Node * node = Q.front();
            Q.pop();
            if(node -> valid) {
                vaild = false;
                break;
            }

            if(node -> left != nullptr) {
                Q.push(node -> left);
                res.push(node -> left);
            }

            if(node -> right != nullptr) {
                Q.push(node -> right);
                res.push(node -> right);
            }
        }

        if(!vaild) {
            printf("%s\n", "not complete");
        }else{
            Node * n = res.front();
            res.pop();
            printf("%d", n -> num);

            while (!res.empty()){
                Node * n = res.front();
                res.pop();
                printf(" %d", n -> num);
            }
            printf("\n");
        }
    }
    return 0;
}