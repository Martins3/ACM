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
    int num;
};

int in_order[10000];
int post_order[10000];

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

    int num = post_order[r];
    int i;
    for(i = left; i <= right; i++){
        if(in_order[i] == num) break;
    }
    n -> num = in_order[i];
    
    if(left <= i - 1) {
        n -> l = new Node;
        make_tree(n -> l, left, i - 1, l, l + ((i - 1) - left));
    }

    if(i + 1 <= right){
        n -> r = new Node;
        make_tree(n -> r, i + 1, right, (r - 1) - (right - (i + 1)), r - 1);
    }
}

int min_leaf;
int val;
int sum;

/**
 * dfs
 */
void find_max(Node* n){
    // cout << n ->num << endl;
   sum += n -> num; 
   if(n -> l == nullptr && n -> r == nullptr){
       if(sum < min_leaf){
            val = n -> num;
            min_leaf = sum;
       }else if(sum == min_leaf){
           val = min(val, n -> num);
       }
       sum -= n -> num;
       return;
    }

    if(n -> l != nullptr) find_max(n -> l);
    if(n -> r != nullptr) find_max(n -> r);
    sum -= n -> num;
}

int main(){
    REOPEN_READ
    REOPEN_WRITE
    while(true){
        string line;
        if(!getline(cin, line)) break; 
        stringstream ss(line);
         
        int i;
        for(i = 0; ss >> in_order[i]; i++);
       
        getline(cin, line);
        stringstream ss2(line);
        for(i = 0; ss2 >> post_order[i]; i++);

        Node * root = new Node;
        make_tree(root, 0, i - 1, 0, i - 1);
        min_leaf = INT_MAX;
        find_max(root);

        printf("%d\n", val);
    }
    return 0;
}