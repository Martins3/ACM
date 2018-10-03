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
 * 使用set 保存到string， 不要添加 空格
 */
int N;

string union_str(string &a, string &b){
    set<string> s;
    int in = 0;
    int left = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != '{' && a[i] != '}') continue;
        if(in == 0) left = i;
        
        if(a[i] == '{') 
            in ++ ;
        else
            in --;

        if(in == 0) s.insert(a.substr(left, i - left + 1));
    }
    
    a = b;
    in = 0;
    left = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != '{' && a[i] != '}') continue;
        if(in == 0) left = i;
        
        if(a[i] == '{') 
           in ++ ;
        else
            in --;

        if(in == 0) s.insert(a.substr(left, i - left + 1));
    }
    string c;
    for(auto i = s.cbegin(); i != s.cend() ; i++){
        c += (*i);
    }
    return c;
}

string intersect_str(string &a, string &b){
    stringstream ss_a(a);
    stringstream ss_b(b);
    set<string> s;
    set<string> res;

    int in = 0;
    int left = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != '{' && a[i] != '}') continue;
        if(in == 0) left = i;
        
        if(a[i] == '{') 
           in ++ ;
        else
            in --;

        if(in == 0) s.insert(a.substr(left, i - left + 1));
    }

    a = b;
    in = 0;
    left = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != '{' && a[i] != '}') continue;
        if(in == 0) left = i;
        
        if(a[i] == '{') 
           in ++ ;
        else
            in --;

        if(in == 0){
            string word = a.substr(left, i - left + 1);
            if(s.find(word) != s.end())
                res.insert(word);
        }
    }
    
    string c;
    for(auto i = res.cbegin(); i != res.cend() ; i++){
        c += (*i);
    }
    return c;
}

/**
 * added the b into the first one,
 * maybe added, but maybe not !
 */
string add_str(string &a, string &b){
    string com = "{";
    com = com + b + "}";
    a = a  + com;
    return a;
}

string op[] = {"PUSH", "DUP", "UNION", "INTERSECT", "ADD"};

int get_degree(const string & a){
    int in = 0;
    int ans  = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != '{' && a[i] != '}') {
            if(a[i] != ' ')
                cout << "fuck" << endl;
            continue;
        }
        if(in == 0)  ans ++;
        
        if(a[i] == '{') 
           in ++;
        else
           in --;
    }
    return ans;
}

int solve(string & line, stack<string> & s){
    int i;
    for(i = 0; i < 5; i++){
        if(line == op[i]) break;
    }
    switch(i){
        case 0:
            s.push(""); 
            break; 
        case 1:
            s.push(s.top());
            break; 
        case 2:{
            string &a = s.top(); s.pop();
            string &b = s.top(); s.pop();
            s.push(union_str(a, b));
            break; 
        }
        case 3:{
            string &c = s.top(); s.pop();
            string &d = s.top(); s.pop();
            s.push(intersect_str(c, d));
            break; 
        }
        case 4:
            string &e = s.top(); s.pop();
            string &f = s.top(); s.pop();
            s.push(add_str(e, f));
            break; 
    }
    return get_degree(s.top());
}

int op_num;
int main(){
    REOPEN_READ
    scanf("%d", &N);
    for(int j = 0; j < N; j++){
        stack<string> s;
        scanf("%d", &op_num);
        getchar();
        for(int i = 0; i < op_num; i++){
            string line;
            getline(cin, line);

            int a = solve(line, s);
            printf("%d\n", a);
            cout << s.top() << endl;
        }
        printf("***\n");
    } 
    return 0;
}