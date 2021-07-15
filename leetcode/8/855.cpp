#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/maritns3/test/cpp/input.txt", "r", stdin);

static int N;

class Segment {
public:
  // begin 和 end 指的是都有人吧!
  Segment(int l, int r) : begin(l), end(r) {
    assert(begin >= -1);
    assert(end <= N);

    size = end - begin - 1; // end 和 begin 的位置都有人的
    if (!size) {
      size = -1;
      return;
    }

    size--; // 当前节点本身需要占据位置
    if (!isSideSegment()) {
      size = size / 2;
    }
  }

  int begin;
  int end;
  int size;

  bool isSideSegment() { return isLeftSide() || isRightSide(); }

  bool isLeftSide() { return begin == -1; }

  bool isRightSide() { return end == N; }
};

struct CMP {
  bool operator()(const Segment *l, const Segment *r) const {
    if (l->size == r->size) {
      return l->begin < r->begin;
    } else {
      return l->size > r->size;
    }
  }
};

class ExamRoom {
public:
  set<Segment *, CMP> segments;
  map<int, Segment *> start;
  map<int, Segment *> end;
  // start 和 end 的安全性问题 : 永远不会出现公用 start 和 end 的情况

  ExamRoom(int n) { N = n; }

  int seat() {
    if (segments.empty()) {
      Segment *a = new Segment(-1, 0);
      Segment *b = new Segment(0, N);
      insert_segment(a);
      insert_segment(b);
      debug();
      return 0;
    }

    Segment *seg = *segments.begin();
    int BEGIN = seg->begin;
    int END = seg->end;

    int m;
    if (seg->isLeftSide()) {
      m = 0;
    } else if (seg->isRightSide()) {
      m = N - 1;
    } else {
      m = BEGIN + (END - BEGIN) / 2;
    }

    Segment *left = new Segment(BEGIN, m);
    Segment *right = new Segment(m, END);
    erase_segment(seg);
    insert_segment(left);
    insert_segment(right);
    debug();
    return m;
  }

  void debug() {
    bool isEmpty = true;
    for (auto f : segments) {
      isEmpty = false;
      printf("[%d %d]", f->begin, f->end);
    }
    if (isEmpty)
      printf("Empty");
    printf("\n");
  }

  // 在使用这个函数之前不要重新赋值哦
  void erase_segment(Segment *seg) {
    assert(segments.find(seg) != segments.end());
    segments.erase(segments.find(seg));
    start.erase(start.find(seg->begin));
    end.erase(end.find(seg->end));
    delete seg;
  }

  void insert_segment(Segment *seg) {
    start[seg->begin] = seg;
    end[seg->end] = seg;
    segments.insert(seg);
  }

  void leave(int p) {
    if (segments.size() == 2) {
      Segment *seg = *segments.begin();
      erase_segment(seg);

      seg = *segments.begin();
      erase_segment(seg);

      assert(segments.empty() && start.empty() && end.empty());
      debug();
      return;
    }

    Segment *left_seg = end[p];
    Segment *right_seg = start[p];
    Segment *new_seg = new Segment(left_seg->begin, right_seg->end);
    erase_segment(left_seg);
    erase_segment(right_seg);
    insert_segment(new_seg);

    debug();
  }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

int main(int argc, char *argv[]) {

  ExamRoom *obj = new ExamRoom(10);
  obj->seat();
  obj->seat();
  obj->leave(9);
  obj->seat();
  obj->seat();

  return 0;
}
