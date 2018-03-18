#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Node{
public:
    int lazy; // 0 表示没有lazy
    int colors;
    int start;
    int end;
    Node():lazy(0){
        cout << "J";
    }
    ~Node(){
        cout << "fuck";
    }
};

class ManyNodes{
public:
    Node * head;
    ManyNodes(int a){
        head = new Node[a];
    }

    ~ManyNodes(){
        delete [] head;
    }
};

int main(){
    // vector<Node> S(100);
    vector<int> a;
    a.push_back(12);
    a.push_back(14);
    auto s = lower_bound(a.begin(), a.end(), 14);
    cout << (s - a.begin()) < endl;
    return 1;
}
    
    
    
int a(){
    vector<int> a;
    a.push_back(1);

    vector<int> b = a;
    b.push_back(2);
    cout << a.size() << endl;
    cout << b.size();
    
    ManyNodes manyNodes(100);
    // vector and vector
    vector<vector<int> > graph(100);
    graph[1] = vector<int>();
    graph[2] = vector<int>();
    graph[3] = vector<int>();

    graph[1].push_back(1);
    graph[2].push_back(2);
    
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
        int j = stackTwo.size();
        int k = stackOne.size();
        int w;
        for(int i: graph[a]){
            stackOne.push_back(i);
            w = stackOne.size();
        }
    }

    for(int i: stackTwo){
        cout << i;
    }
    return 0;
}