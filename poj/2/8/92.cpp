//
// Created by martin on 17-12-11.
//
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


class BinaryIndexTree{
    int num;
    int lowBit(int x){
        return (x) & (-x);
    }
public:
    vector<int> arr;
    vector<int> destroyed;


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

    BinaryIndexTree(int size): arr(size + 1), destroyed(size + 1), num(size){

    }

    int left(int x);

    int right(int x);

    int query(int x);
};

/**
 * all discussion: end point is included !
 */
int BinaryIndexTree::left(int x) {
    int left = 1;
    int right = x; // left is included
    if(sum(right) - sum(left - 1) == 0)
        return 1;

    while (left + 1 <  right){ // more careful check
        int middle = (left + right) / 2; // at most middle = left
        int rightInterval = sum(right) - sum(middle); // middle + 1 to right
        if(rightInterval){
            left = middle + 1;
        }else{
            right = middle;
        }
    }

    if(destroyed[right]){
        return right + 1;
    }
    return right;
}

int BinaryIndexTree::right(int x) {
    int left = x;
    int right = num;
    if(sum(right) - sum(left - 1) == 0)
        return num;

    while (left + 1 < right){
        int middle = (left + right) / 2;
        int leftInterval = sum(middle) - sum(left - 1); // left -- middle
        if(leftInterval){
            right = middle;
        }else{
            left = middle + 1;
        }
    }

    if(destroyed[left])
        return left - 1;

    return left;
}

int BinaryIndexTree::query(int x) {
    if(destroyed[x]) return 0;
    return right(x) - left(x) + 1;
}

/**
 * 寻找一个区间的求和为 0
 * destroyed then 1
 */
int main(){
    freopen("input.txt", "r", stdin);
    int N;
    int M;
    scanf("%d%d", &N, &M); getchar();
    BinaryIndexTree B(N);
    vector<int> stack;
    for (int i = 0; i < M; ++i) {
        int c = getchar();
        if(c == 'R'){
            int last = stack.back();
            stack.pop_back();
            B.destroyed[last] = 0;
            B.add(last, -1);
        }else {
            int node;
            scanf("%d", &node);
            if(c == 'D'){
                B.destroyed[node] = 1;
                B.add(node, 1);
                stack.push_back(node);
            }else{
                printf("%d\n", B.query(node));
            }
        }
        getchar(); // read the \n
    }
    /**
    for (int i = 0; i < M; ++i) {
        char a[10];
        fgets(a, 5, stdin);
        scanf("%s", a);
        char op = a[0];
        if(op == 'D'){
            int node = a[2] - '0';
            B.destroyed[node] = 1;
            B.add(node, 1);
            stack.push_back(node);
        }else if(op == 'Q'){
            printf("%d\n", B.query(a[2] - '0'));
        }else{
            int last = stack.back();
            stack.pop_back();
            B.destroyed[last] = 0;
            B.add(last, -1);
        }
    }
    */

    fclose(stdin);
    return 0;
}

