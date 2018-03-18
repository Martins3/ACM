#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int, int> a;
    a[1] = 2;
    a[4] = 5;
    a[3] = 4;
    cout << a[4] << endl;
}