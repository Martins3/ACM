#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    queue<int> queueOne;
    queueOne.push(1);    
    queueOne.push(2);
    queueOne.pop();
    cout << queueOne.front();    
    return 0;
}