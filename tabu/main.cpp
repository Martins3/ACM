#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
#include <cassert>
#include <cstdlib>
#include "./tabu.h"

using namespace std;
int main(){
    freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/tabu/log.txt", "a", stdout);
    // 测试编译
    Tabu tabu(0);
    // tabu.tabu_search(50, 1000 * 10000);
    tabu.hybrid_evolutionary(48);
    return 0;
}
