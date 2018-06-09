#ifndef INFO_H
#define INFO_H

#include<cstddef>
#include<vector>
#include<iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print_v(std::vector<int> v){
    for(int i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}

#endif // FO_H
