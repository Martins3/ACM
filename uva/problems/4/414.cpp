#include <iostream>
#include <fstream>
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
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);


#define LEN 30

char line[LEN];

int main(){
    REOPEN_READ
    REOPEN_WRITE

    int N;
    std::vector<int> dis;

    while(scanf("%d", &N) == 1 && N != 0){
        getchar();
        for (int i = 0; i < N; i++) {
            fgets(line, LEN, stdin);
            // printf("[%d]\n",N);
            // getchar();
            // printf("%s", line);
            int distance = 0;
            for (int i = 0; i < 25; i++) {
                if(line[i] != 'X')
                    distance ++;
            }
            dis.push_back(distance);
        }
        sort(dis.begin(), dis.end());
        // for(auto a : dis){
            // cout << a << endl;
        // }
        // cout << dis[0] << endl;
        int sum = 0;
        for (int i = 1; i < dis.size(); i++) {
            sum += dis[i] - dis[0];
        }
        printf("%d\n", sum);
        dis.clear();
    }
    return 0;
}
