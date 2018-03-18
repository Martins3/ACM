#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;
#define VSCODE_READ freopen("../../../input.txt", "r", stdin);
#define C_READ freopen("input.txt", "r", stdin);


/**
 * 构建 Tree
 */

class Node{
public:
    Node* left;
    Node* right;
    int val;
};

class Tree{
public:
    void find();
};