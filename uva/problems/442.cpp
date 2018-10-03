#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/uva/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("../output.txt", "w", stdout);

class Matrix{
public:
    int l;
    int r;
    Matrix( int l, int r): l(l), r(r){};
    Matrix(){};
    Matrix operator *(Matrix & b){
       return Matrix(l, b.r);
    } 

    static int cal(Matrix & a, Matrix & b){
        return a.l * a.r * b.r;
    }

};

char readChar(){
    char c = '\0';
    while(c == '\0' || c == ' ' || c == '\t' || c == '\n') c = getchar();
    return c;
}

Matrix M[30];


int main(){
    REOPEN_READ
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        char A;
        int l;
        int r;
        A = readChar();
        scanf("%d %d", &l, &r);
        M[A - 'A'] = Matrix(l, r);
    }

    getchar();

    string line;
    while(cin >> line){
        stack<Matrix> s;
        // 只要出现右括号， 使用所有的， 可以认为整个计算是从右边到达左边的开始的
        // 虽然的是之后计算， 但是可以提前计算出来
        bool error = false;
        int calculation = 0;
        for(int i = 0; i < line.size() ; i++){
            char c = line[i];
            if(isalpha(c)){
                s.push(M[c - 'A']);
            }else if(c == ')'){
                    Matrix b = s.top(); s.pop();
                    Matrix a = s.top(); s.pop();
                    if(a.r != b.l) {
                        error = true;
                        break;
                    }
                    calculation += Matrix::cal(a, b);
                    s.push(a * b);
            }
        }

        if(!error)
            printf("%d\n", calculation);
        else
            printf("error\n");
    }


    return 0;
}