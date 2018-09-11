#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
#include <cassert>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

class Solution {
public:
    int * arr;
    int size = 0;
    int index = 0;

    int m;

    void push(int value) {
        if(index == size){
            // 初始化
            if(size == 0){
                arr = (int *)malloc(sizeof(int) * 100);
                m = INT_MAX;
                size = 100;
            }else{
                int * t = (int *)malloc(sizeof(int) * size * 2);
                for (int i = 0; i < size; i++) {
                    t[i] = arr[i];
                }
                size = size * 2;
                arr = t;
            }
        }

        // 注入
        arr[index ++] = value; 
        
        // 计算最小值
        if(value < m) m = value;
    }

    void pop() {
        index --;
        // 计算最小值
        m = INT_MAX;
        for (int i = 0; i < index; i++) {
            if(arr[i] < m) m = arr[i];
        }
    }

    int top() {
        return arr[index - 1];
    }

    int min() {
        return m;
    }
};

int main(){
    
    return 0;
}
