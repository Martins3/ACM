#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <forward_list>
#include <queue>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("../output.txt", "w", stdout);

int N;
vector<int> arr[30]; // the box world
int pos[30];

int op(string &line){
    if(line.find("move") != string::npos &&line.find("onto") != string::npos) return 1;
    if(line.find("move") != string::npos &&line.find("over") != string::npos) return 2;
    if(line.find("pile") != string::npos &&line.find("onto") != string::npos) return 3;
    return 4;
}

// 记录所在的槽
void put_back(int a){
    int slot = pos[a];

    int c = arr[slot].back();
    while(c != a){
        arr[c].push_back(c);
        pos[c] = c;
        arr[slot].pop_back();
        c = arr[slot].back();
    }
}


void move_a_to_b(int a, int b){
    int a_slot = pos[a];
    int b_slot = pos[b];
    int find = 0;
    for(int i = 0; i < arr[a_slot].size(); i++){
        if(find){
            arr[b_slot].push_back(arr[a_slot][i]);
            pos[arr[a_slot][i]] = b_slot;
            find ++;
            continue;
        }
        if(arr[a_slot][i] == a){
            find ++;
            arr[b_slot].push_back(arr[a_slot][i]);
            pos[arr[a_slot][i]]= b_slot;
        }
    }

    // clear the message
    for (int j = 0; j < find; ++j) {
        arr[a_slot].pop_back();
    }

}

void do_it(string &line){
    int operation = op(line);
    int a = 0;
    int b = 0;
    stringstream ss(line);
    string string1;
    ss >> string1;
    ss >> a;
    ss >> string1;
    ss >> b;

    if(pos[a] == pos[b]) return;

    switch(operation){
        case 1:
            // a 和 b 上面的复原
            put_back(a);
            put_back(b);
            move_a_to_b(a, b);
            break;
        case 2:
            // a 的复原
            put_back(a);
            move_a_to_b(a, b);
            break;
        case 3:
            // b 的复原
            put_back(b);
            move_a_to_b(a, b);
            break;
        case 4:
            move_a_to_b(a, b);
            break;
    }
} 

int main(){
    REOPEN_READ
//    REOPEN_WRITE
    scanf("%d", &N);
    getchar();
    
    // 初始化 盒子
    for(int i = 0; i < N; i++){
       arr[i].push_back(i);
    }
    // 记录所有的位置
    for(int i = 0; i < N; i++){
        pos[i] = i;
    }

    string line;
    int index = 0;
    while(getline(cin, line)){
        if(line == "quit") break;
        do_it(line);
    }
    for(int i = 0; i < N; i++){
        printf("%d:", i);
        for(int j = 0; j < arr[i].size(); j++){
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}