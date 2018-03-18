//
// Created by martin on 17-12-11.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

/**
 * 注意地址的上面的不对应
 * 存储的数值为m , 那么地址为0 的位置需要空出来
 */
class BinaryIndexTree{

    int lowBit(int x){
        return (x) & (-x);
    }
public:

    vector<int> apple;
    vector<int> arr;
    vector<vector<int> > graph;
    vector<int> pos; // the pos of the apple
    vector<int> left; // the left apple of the apple

    // Binary Index part
    int sum(int x){
        int ans = 0;
        while(x != 0){
            ans += arr[x];
            x -= lowBit(x);
        }
        return ans;
    }

    void add(int x, int v){
        for(int i = x ; i < arr.size(); i += lowBit(i)){
            arr[i] += v;
        }
    }

    BinaryIndexTree(int size): arr(size + 1), graph(size + 1), left(size + 1), pos(size + 1), apple(size + 1){
        // init for every vector
        for (int i = 1; i < size + 1; ++i) {
            graph[i] = vector<int>();
        }

        // init the apple tree
        for (int j = 0; j <= size; ++j) {
            arr[j] = 0;
        }

        for (int k = 1; k <= size; ++k) {
            add(k, 1);
        }

        for (int l = 1; l <= size; ++l) {
           apple[l] = 1;
        }
    }

    // graph part
    void addEdge(int x, int y){
        graph[x].push_back(y);
    }


};

int main(){

    freopen("input.txt", "r", stdin);

    int N;
    scanf("%d", &N);

    BinaryIndexTree B(N);

    for (int i = 0; i < N - 1; ++i) {
        int u;
        int v;
        scanf("%d%d", &u, &v);getchar();
        B.addEdge(u, v);
    }

    // travel the graph
    vector<int> stackOne;
    vector<int> stackTwo;
    stackOne.push_back(1);

    /**
     * pop from stackOne: being visit the graph
     * pop from stackTwo: visit over
     *
     * every one's first child is the left apple
     * stackTwo means the pos
     */
    while (!stackOne.empty()){
        int a = stackOne.back();
        stackOne.pop_back();
        stackTwo.push_back(a);
        int w;
        for(int i = 0; i < B.graph[a].size(); i++){
            stackOne.push_back(B.graph[a][i]);
        }
    }

    // pos
    for (int l = 0; l < stackTwo.size(); ++l) {
        B.pos[stackTwo[l]] = N - l; //  + 1, why !
    }

    // left apple
    for (int i = N - 1; i >= 0; --i) {
        int k = stackTwo[i];
        if(B.graph[k].empty()){
            B.left[k] = k;
        }else{
            B.left[k] = B.left[B.graph[k].front()]; // ask the child node for the left
        }
    }



    int M;
    scanf("%d", &M);getchar();

    for (int j = 0; j < M; ++j) {
        char command;
        int fork;
        scanf("%c%d",&command, &fork); getchar();
        if(command == 'Q'){
            int a = B.sum(B.pos[fork]);
            int b = B.sum(B.pos[B.left[fork]] - 1);
            printf("%d\n",  a - b);
        }else{
            if(B.apple[fork] == 1){
                B.add(B.pos[fork], -1);
                B.apple[fork] = 0;
            }else{
                B.add(B.pos[fork], 1);
                B.apple[fork] = 1;
            }
        }
    }

    fclose(stdin);
}