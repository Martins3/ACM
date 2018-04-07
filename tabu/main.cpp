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
    // 测试编译
    Tabu tabu(0);
    // tabu.tabu_search(49, 1000 * 10000);

    // tabu.hybrid_evolutionary(50, false, 30);
    tabu.hybrid_evolutionary(48, true, 4);
    // tabu.hybrid_evolutionary(48, false, 30);
    return 0;
}
