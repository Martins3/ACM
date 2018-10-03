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



int main(){
    REOPEN_READ
    // REOPEN_WRITE

    map<string, string> m;
    map<string, bool> ok;
    set<string> res;
    string line;
    while(getline(cin, line)){
        // cout << line << endl;
        if(line == "#") break;
        string word;
        stringstream ss(line);
        while(ss >> word){
            // cout << word << endl;
            string p_word = word;
            transform(word.begin(), word.end(), word.begin(), ::toupper);
            sort(word.begin(), word.end()); 
            if(ok.find(word) != ok.end()) {
                ok[word] = false;
                // cout << word << " find again" << endl;
            }else{
                ok[word] = true;
                // cout << word << " find" << endl;
                m[word] = p_word;
            }
        }
    }

    for(auto i = m.cbegin(); i != m.cend(); i++){
        // cout << (*i).first << endl;
       if(ok[(*i).first]){
           res.insert(m[(*i).first]);
        //    cout << m[(*i).first] << endl;
        //    cout << "fuck *************" << endl;
       }
    }
    // cout << res.size() << endl;

    for(auto i = res.cbegin(); i != res.cend(); i++){
       cout << *i << endl;
    }
    return 0;
}