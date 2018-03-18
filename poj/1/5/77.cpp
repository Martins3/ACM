#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;
#define VSCODE_READ freopen("../../../input.txt", "r", stdin);
#define C_READ freopen("input.txt", "r", stdin);


class Node{
public:
    Node* left;
    Node* right;
    char val;
    Node(char c):left(0), right(0), val(c){}
    ~Node(){
        if(left != 0) delete left;
        if(right != 0) delete right;
    }
};

Node * root;

void preorderTravel(const Node * node){
    if(node != 0) {
        printf("%c", node->val);
        preorderTravel(node->left);
        preorderTravel(node->right);
    }
}
void insertNode(Node * & node, char c){
    if(node == 0) {
        node = new Node(c);
        return;
    }


    if(node->val > c){
        insertNode(node->left, c);
    }else{
        insertNode(node->right, c);
    }
}


void solve(vector<char> & vec){
    while(vec.size()){
        char c = vec.back();
        vec.pop_back();
        insertNode(root, c);
    }

    // 前序遍历
    preorderTravel(root);
    printf("\n");


    delete root;
    root = 0;
}
 
int main(){
    VSCODE_READ

    vector<char> chars;
    char c;
    while(true){
        scanf("%c", &c);
        if(c == '$'){
            solve(chars);
            break;
        }

        if(c == '*') {
            solve(chars);
            continue;
        }

        if(c == '\n') continue;

        chars.push_back(c);
    }
    return 0;
};