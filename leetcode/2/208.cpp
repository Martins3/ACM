#include <bits/stdc++.h>
using namespace std;

class Trie {
  struct Node {
#define KEY_NUM 26
    Node *leaf[KEY_NUM];
    bool isEnd;
    Node() {
      for (int i = 0; i < KEY_NUM; ++i) {
        leaf[i] = NULL;
      }
      isEnd = false;
    }
  };

  Node root;

public:
  /** Initialize your data structure here. */
  Trie() { root.isEnd = true; }

  /** Inserts a word into the trie. */
  void insert(string word) {
    Node *node = &root;
    for (const auto c : word) {
      auto i = c - 'a';
      if (node->leaf[i] == NULL) {
        node->leaf[i] = new Node;
      }
      node = node->leaf[i];
    }
    node->isEnd = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Node *node = &root;
    for (const auto c : word) {
      auto i = c - 'a';
      if (node->leaf[i] == NULL) {
        return false;
      } else {
        node = node->leaf[i];
      }
    }
    return node->isEnd;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    Node *node = &root;
    for (const auto c : prefix) {
      auto i = c - 'a';
      if (node->leaf[i] == NULL) {
        return false;
      } else {
        node = node->leaf[i];
      }
    }
    return true;
  }
};

#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);
int main(int argc, char *argv[]) { return 0; }
