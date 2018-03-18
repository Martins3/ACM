#include <iostream>
#include <fstream>
#include <cstring>


// 可怕， 好像必须使用数组的表示 ！

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("../output.txt", "w", stdout);

#define LEN (100000 + 10)

char line[LEN];

class Node{
public:
    Node * next = nullptr;
    char c;
    Node() = default;
    Node(char c): c(c), next(nullptr){}; 
    Node(char c, Node * next): c(c), next(next){}; 
};

Node Nodes[LEN];


int main(){
    REOPEN_READ
    // REOPEN_WRITE
    while(scanf("%s", line) != EOF){
        Node * head = Nodes; // 头指针
        Node * tail = head;
        Node * cur = head;
        Node * t = nullptr; // 在首端插入的时候，记录结束位置
        memset(Nodes, 0, sizeof(Nodes));

        for(int i = 0; i < strlen(line); i++){
            if(line[i] == '['){
                cur = head;
                t = head -> next;
            }else if(line[i] == ']'){
                cur = tail;
                t = nullptr;
            }else{
                Nodes[i + 1].c = line[i];
                Nodes[i + 1].next = t;

                cur -> next = &(Nodes[i + 1]);
                // cur -> next = new Node(line[i], t);

                if(cur == tail) tail = cur -> next; // 判断是否在尾端地方
                cur = cur -> next;
            }
        }

        // 输出结果
    
        cur = head->next;
        while(cur != nullptr){
            putchar(cur -> c);
            cur = cur -> next;
        }
        putchar('\n');  
    }
    return 0;
}