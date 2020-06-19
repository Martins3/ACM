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
class TopVotedCandidate {

  class Fuck {
  public:
    int vote;
    int time;
    int who;
    Fuck(int a, int b, int c) : vote(a), time(b), who(c) {}

    friend ostream &operator<<(ostream &o, const Fuck &f) {
      o << f.vote << " : " << f.time << " : " << f.who << endl;
      return o;
    }
  };

  class Compare {
  public:
   int operator()(const Fuck &a, const Fuck &b) const {
      if (a.vote != b.vote)
        return a.vote > b.vote;
      if (a.time != b.time)
        return a.time > b.time;
      return a.who > b.who;
    }
  };

public:
  // 不应该使用优先队列，除非操作模式，可以修改的内容总是开头的
  vector<int> data;
  vector<int> times;

  TopVotedCandidate(vector<int> &persons, vector<int> &times) {
    this->times = times;
    vector<int> record(persons.size() + 1,
                       0); // 0 <= persons[i] <= persons.length
    set<Fuck, Compare> cao;
    for (int i = 0; i < times.size(); ++i) {
      // 需要快速找到 person 才可以
      // 过时的数据永远都不会产生真正的作用
      record[persons[i]]++;
      Fuck f(record[persons[i]], times[i], persons[i]);
      cao.insert(f);
      data.push_back(cao.begin()->who);
    }
  }

  int q(int t) {
    auto f = lower_bound(times.begin(), times.end(), t);

    if (f == times.end()) {
      return data.back();
    }

    if (*f == t) {
      return data[f - times.begin()];
    }

    if (f == times.begin()) {
      return 12343545;
    }

    f--;
    return data[f - times.begin()];
  }
};

int main() {

  vector<int> a{0, 1, 1, 0, 0, 1, 0};
  vector<int> b{0, 5, 10, 15, 20, 25, 30};
  TopVotedCandidate x(a, b);

  cout << x.q(3);
  cout << x.q(12);
  cout << x.q(25);
  cout << x.q(15);
  cout << x.q(24);
  cout << x.q(8);

  return 0;
}

/**
 * 错误原因 : 不应该使用队列，因为因为每次增加的时候，只有被增加的数值才有用
 * 措施: 新的经验，计算一堆数值的最大值，不一定非要使用 priority queue 的操作，当最大值是逐渐增减的，那么直接扫描最大值即可。
 */
