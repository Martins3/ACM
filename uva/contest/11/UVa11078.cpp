#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <forward_list>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

#define INF 0x3f3f3f3f
#define maxn (100000 + 100)
int T;
int n;
int nums[maxn];
int max_num[maxn]; // 

int main(){
    REOPEN_READ
    // REOPEN_WRITE
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        while(n--) scanf("%d", &nums[n]);
        copy(begin(nums), end(nums), begin(max_num));

        int max_value = -INF;
        for(int i = n - 2; i >= 0; i--){
            max_num[i] = max(max_num[i], max_num[i + 1]);
            max_value = max(max_value, max_num[i + 1] - nums[i]);
        }
        
        printf("%d\n", max_value);
    }

    return 0;
}