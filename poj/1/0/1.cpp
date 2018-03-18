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
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);

#define maxn 100

// l 2 l
// leading 0
// integer 
class Decimal{
public:
    char digits[maxn];


    Decimal(char * num){
        memset(digits, 0, sizeof(digits));
        for(int i = 0; i < strlen(num); i++){
            digits[i] = num[strlen(num) - 1 - i];
        }
    }

    Decimal(){
        memset(digits, 0, sizeof(digits));
    }

    Decimal operator * (const Decimal & d){
        char res[maxn];
        const char * num  = d.digits;

        memset(res, 0, sizeof(res));

        for(int i = 0; i < strlen(num); i++){
            int a = num[i] - '0';
            int carry  = 0;
            int j;
            for(j = 0; j < strlen(digits); j++){
                int b = digits[j] - '0';
                int c = res[i + j] == 0 ? 0 : res[i + j] - '0'; 
                int d = a * b + c + carry;
                carry =  d / 10;
                res[i + j] = d % 10 + '0';
            }

            if(carry) res[i + j] = carry + '0';
        }
        return Decimal(res);
    }
};

char digits[maxn];
int N;
int main(){
    REOPEN_READ
    while(scanf("%s%d", digits, &N) != EOF){
        int w = 0;
        bool de = false;
        int len = strlen(digits);
        for(int i = 0; i < len; i++){
            if(de) w ++;
            if(digits[i] == '.'){
                de = true;
            }
            if(de) digits[i] = digits[i + 1];
        }

        Decimal d(digits);
        char one[] = "1";
        Decimal res(one);
        for(int i = 0; i < N; i++){
            res = res * d; 
        }

        string s;  
        char * r = res.digits;
        for(int i = 0; i < strlen(r); i++){
            if(strlen(r) - i == w * N){
                s += '.';
            }
            s += r[i];
        }

        reverse(s.begin(), s.end());
        printf("%s\n", s.c_str());
    }
    printf("%d", 95123 * 95123);
    return 0;
}