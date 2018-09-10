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

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

class Solution {
public:
	void replaceSpace(char *str,int length) {
        char * F = (char *)malloc(length * sizeof(char));
        for (int i = 0; i < length; i++) {
            F[i] = str[i];
        }

        for (int i = 0, j = 0; i < length; i++) {
            switch (F[i]) {
                case ' ':
                    str[j++] = '%';
                    str[j++] = '2';
                    str[j++] = '0';
                    break;
                default:
                    str[j++] = F[i];
            }
        }
	}
};
int main(){
    
    return 0;
}
