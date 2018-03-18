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
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/output.txt", "w", stdout);

/**
 * 任务时间长的首先交代
 */
class Job{
public:
    int x;
    int y;
    bool operator < (const Job & j) const{
        return y > j.y;
    }

    Job(int x, int y): x(x), y(y){}
};
int N;
int main(){
    REOPEN_READ
    while(scanf("%d", &N) == 1 && N){
        vector<Job> v;
        for(int i = 0; i < N; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            v.push_back(Job(x, y));
        }

        sort(v.begin(), v.end());

        int max_time = 0;
        int accu = 0;
        for(auto i = v.cbegin(); i != v.cend(); i++){
            accu += (*i).x;
            max_time = max(max_time, accu + (*i).y);
        }

        printf("%d", max_time); 
    }
    return 0;
}