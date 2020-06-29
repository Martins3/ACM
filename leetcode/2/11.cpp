#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

// 1. 不需要添加任何数值，不是 NULL 即可
// 2. 除非长度都是相同的，否则需要添加标志位
class WordDictionary {
public:
  struct Node {
    Node *next[26];
    bool end[26];

    Node() {
      memset(next, 0, sizeof(next));
      memset(end, 0, sizeof(end));
    }
  };
  Node root;

  /** Initialize your data structure here. */
  WordDictionary() {}

  /** Adds a word into the data structure. */
  void addWord(string word) {
    Node *n = &root;
    for (int i = 0; i < word.size(); ++i) {
      char c = word[i];

      if (n->next[c - 'a'] == NULL) {
        n->next[c - 'a'] = new Node();
        if (i == word.size() - 1)
          n->end[c - 'a'] = true;
      }
      n = n->next[c - 'a'];
    }
  }

  // 1. 即将搜索的位置
  // 2. 如何保证恰好是: 如果存在ab，同时存在 abc
  // TODO 是否处理 空的字符串 ?
  bool s(string &word, int index, Node *n) {
    if(n == NULL) return false;
    if (index == word.size() - 1) {
      if (word[index] == '.') {
        for (int i = 0; i < 26; ++i) {
          if (n->next[i] != NULL && n->end[i]) {
            return true;
          }
        }
      } else {
        if (n->next[word[index] - 'a'] != NULL && n->end[word[index] - 'a'])
          return true;
      }
    } else {
      if (word[index] == '.') {
        for (int i = 0; i < 26; ++i) {
          if (n->next[i] != NULL) {
            if (s(word, index + 1, n->next[i]))
              return true;
          }
        }
      } else {

        if (n->next[word[index] - 'a'] != NULL) {
        if (s(word, index + 1, n->next[word[index] - 'a']))
          return true;
          }
      }
    }

    return false;
  }

  /** Returns if the word is in the data structure. A word could contain the dot
   * character '.' to represent any one letter. */
  bool search(string word) { return s(word, 0, &root); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
  WordDictionary s;

  return 0;
}

/**
 * 错误原因 : 只是比较了字母相等的，但是没有处理 node 是否存在的问题
 * 措施:
 */
