#ifndef INFO_H
#define INFO_H

#include<cstddef>
#include<vector>
#include<iostream>
#include<string>

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

void print_v(std::vector<std::string> v){
    for(std::string i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}


std::vector<TreeNode *> make_tree(std::vector<int> a){
    TreeNode * root = NULL;
    std::vector<TreeNode *> trees(a.size() + 1, NULL);
    for (size_t i = 0; i < a.size(); ++i) {
        TreeNode * this_node;
        if(a[i] == -1){
            this_node = NULL;
        }else{
            this_node = new TreeNode(a[i]);
        }
        int index = i + 1;
        if(index == 1){
            root = this_node;
        }else{
            int x = index / 2;
            int y = index % 2;

            if(y)
                trees[x]->right = this_node;
            else
                trees[x]->left = this_node;
        }
        trees[index] = this_node;
    }
    return trees;
}

void print_tree(TreeNode * node, int tab = 0){
    if(node == NULL) return;
    for (int i = 0; i < tab; ++i) {
        putchar('\t');
    }
    printf("%d\n", node->val);
    tab ++;
    print_tree(node->left, tab);
    print_tree(node->right, tab);
}

#endif // FO_H
