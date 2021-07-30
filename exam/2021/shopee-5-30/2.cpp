#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

string nums[] = {"ZERO",    "One",     "Two",       "Three",    "Four",
                 "Five",    "Six",     "Seven",     "Eight",    "Nine",
                 "Ten",     "Eleven",  "Twelve",    "Thirteen", "Forteen",
                 "Fifteen", "Sixteen", "Selveteen", "Eighteen", "Ninteen"};

string tys[] = {"ERROR, "
                "Error",
                "Twenty",
                "Thirty",
                "Forty",
                "Fifty",
                "Sixty",
                "Seventy",
                "Eighty",
                "Ninty"};

string less_than_twenty(int i) { return nums[i]; }

bool is_less_than_twenty(int i) { return i < 20; }

bool is_ty(int i) {
  assert(i < 100 && i > 0);
  return i % 10 == 0;
}

string ty(int i) {
  assert(is_ty(i));
  return tys[i / 10];
}

string less_than_thousand(int i) {
  string res;
  if (i >= 100) {
    int h = i / 100;
    i = i % 100;
    res += less_than_twenty(h);
    res += " Hundred";
  }

  if (is_less_than_twenty(i)) {
    cout << "de " << i << endl;
    res += " " + less_than_twenty(i);
    return res;
  }

  int x = i / 10 * 10;
  int y = i % 10;
  res += " " + ty(x);

  if (y > 0) {
    res += " " + less_than_twenty(y);
  }
  return res;
}

#define BILLION (1000 * 1000 * 1000)
#define MILLION (1000 * 1000)
#define THOUSAND (1000)

string f(int i) {
  string res;
  if (i > BILLION) {
    int x = i / BILLION;
    i = i % BILLION;

    res += " " + less_than_thousand(x);
    res += " Billion";
  }

  if (i > MILLION) {
    int x = i / MILLION;
    i = i % MILLION;

    res += " " + less_than_thousand(x);
    res += " Million";
  }

  if (i > THOUSAND) {
    int x = i / THOUSAND;
    i = i % THOUSAND;

    cout << "gg " << i << endl;

    res += " " + less_than_thousand(x);
    res += " Thousand";
  }

  res += " " + less_than_thousand(i);
  return res;
}

int main() {
  cout << f(123) << endl;
  cout << f(12312123) << endl;
}
