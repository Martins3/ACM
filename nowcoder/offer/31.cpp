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

class Solution {
public:
    
    string PrintMinNumber(vector<int> numbers) {
        std::vector<string> A;
        for(auto s : numbers){
            A.push_back(to_string(s));
        }
        sort(A.begin(), A.end());


        string res;
        for(auto s :A){
            res+= s;
        }
        return res;
    }
};    

int main(){
    string a = "123";
    string b = "1234";
    cout << (a > b) << endl;
    
    return 0;
}
