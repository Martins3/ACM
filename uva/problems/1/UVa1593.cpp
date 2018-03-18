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

#define max_line_len (300 + 5)
#define max_lines_nums (2000 + 5)
#define max_documents 200

int N, M, DOC_NUM;
char row[max_lines_nums][max_line_len];
map<int, set<int> > res;
int line_index;
map<int, set<int> > doc_lines;


map<string, map<int, set<int> > > google;

void insert(string str, int doc,  int line){
    auto f = google.find(str);

    // 是否含有 string
    if(f == google.end()){
        map<int, set<int> > m;
        set<int> s;
        s.insert(line);
        m.insert(make_pair(doc, s));
        google.insert(make_pair(str, m));
    }else{
        map<int, set<int> > & m = google[str];
        // 如果 f_doc 不存在
        auto f_doc = m.find(doc);
        if(f_doc == m.end()){
            set<int> s;
            s.insert(line);
            m.insert(make_pair(doc, s));
        }else{
            f_doc->second.insert(line);
        }
    }
}

bool is_ten_asterisk(char * line){
    return strcmp(line, "**********\n") == 0;
}

void print_line(int line){
    printf("%s", row[line]);
}

map<int, set<int> > & get_map(string & a, map<int, set<int> >& empty){
    map<int, set<int> > & A = empty;
    auto Ap = google.find(a);
    if(Ap != google.end()) A = Ap->second; 
    return A;
}

void merge_set(set<int>& a, const set<int>& b){
    for(auto i = b.begin(); i != b.end(); i++){
        if(a.find(*i) == a.end()) a.insert(*i);
    } 
}

void AND(string & a, string & b){
    map<int, set<int> > empty;
    map<int, set<int> > A = get_map(a, empty);
    map<int, set<int> > B = get_map(b, empty);

    for(auto i = A.cbegin(); i != A.cend(); i ++){
        auto j = B.find(i->first);
        if(j != B.cend()){
            set<int> s;
            merge_set(s, i->second);
            merge_set(s, j->second);
            res.insert(make_pair(i->first, s));
        }
    }

}

void OR(string & a, string & b){
    map<int, set<int> > empty;
    map<int, set<int> > A = get_map(a, empty);
    map<int, set<int> > B = get_map(b, empty);

    for(auto i = A.cbegin(); i != A.cend(); i ++){
        if(B.find(i->first) == B.cend()){
            res.insert(make_pair(i->first, i->second));
        }
    }

    for(auto i = B.cbegin(); i != B.cend(); i ++){
        auto f = res.find(i->first);
        if(f == res.end())
            res.insert(make_pair(i->first, i->second));
        else
            merge_set(f->second, i->second);
            
    }
}

void NOT(string & a){
    map<int, set<int> > empty;
    map<int, set<int> > A = get_map(a, empty);
    
    for(int i = 1; i <= DOC_NUM; i++){
        if(A.find(i) == A.end()){
            res.insert(make_pair(i, doc_lines[i]));            
        }
    }
}

void SINGLE(string & a){
    map<int, set<int> > empty;
    map<int, set<int> > A = get_map(a, empty);

    // 可以优化
    for(auto i = A.cbegin(); i != A.cend(); i ++){
        res.insert(make_pair(i->first, i->second));
    }
}


vector<string> get_words(char * line){
    // first 
    int left = 0;
    int right = 0;
    vector<string> vec;
    while(line[left] != '\0'){
        while(line[left] != '\0'){
           if(islower(line[left]) || isupper(line[left])) break;
           left ++; 
        }
        right = left;
        while(islower(line[right]) || isupper(line[right])) right ++;
        // not included right
        string word(line + left, line + right);
        if(word.size()) vec.push_back(word);
        left = right;
    }
    return vec; 
}

void insert_row(char* line, int doc, int line_num){
    vector<string> words = get_words(line);
    for(string word: words){
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        insert(word, doc,  line_num);
    }
}

void init_doc_line(){
    for(int i = 1; i <= DOC_NUM; i++){
        set<int> s;
        doc_lines.insert(make_pair(i, s));
    }
}

void read_documents(){
    int doc = 1;
    while(M --){
        while(true){
            fgets(row[line_index], max_line_len, stdin);
            // print_line(line_index);
            if(is_ten_asterisk(row[line_index])) break;
            doc_lines[doc].insert(line_index);
            insert_row(row[line_index], doc,  line_index);
            line_index ++;
        }
        doc ++;
    }
}

void read_query(){
    char line[max_line_len * 2];
    fgets(line, max_line_len * 2, stdin);
    vector<string> words = get_words(line);
    res.clear();
    if(words.size() == 3){
        if(words[1] == "AND") AND(words[0], words[2]);
        if(words[1] == "OR") OR(words[0], words[2]);
    } 
    
    if(words.size() == 1) SINGLE(words[0]);

    if(words.size() == 2) NOT(words[1]);

    int fis = 0;
    for(auto i = res.begin(); i != res.end(); i ++){
        if(fis ++) printf("%s\n", "----------"); 
        for(auto j = i->second.begin(); j != i->second.end(); j++){
            print_line(*j);
        }
    }
    if(fis == 0) printf("%s\n", "Sorry, I found nothing.");
    printf("%s\n", "==========");
    
}




int main(){
    REOPEN_READ
    REOPEN_WRITE
    scanf("%d", &M); getchar(); DOC_NUM = M;
    read_documents();
    

    scanf("%d", &N); getchar();
    while(N --) read_query();
    return 0;
}
/**
 * error log
 * 1. 忘记了 fgets 含有换行符号
 * 2. 选中doc， 确定文档
 * 3. map 的数值融合的时候，set 需要merge 一下才可以的 
 *  
 */