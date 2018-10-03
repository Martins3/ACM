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

#define maxn (10000 + 100)

class Ant{
public:
    int id;
    bool l;
    int pos;
    int after_pos;

    Ant(int id, bool l, int pos): id(id), l(l), pos(pos){}
    
    bool operator <(const Ant & ant) const{
        return pos < ant.pos;
    }

    bool operator > (const Ant & ant) const{
        return id < ant.id;
    }
};
int N;
int L, T, n;
int main(){
    REOPEN_READ
    REOPEN_WRITE
    scanf("%d", &N);

    for(int smn = 1; smn <= N; smn++){
        if(smn != 1) printf("\n");

        vector<Ant> v;
        scanf("%d %d %d", &L, &T, &n);
        for(int qq = 0; qq < n; qq++){
            int pos;
            bool l;
            scanf("%d", &pos); getchar(); l = getchar() == 'L';
            v.push_back(Ant(qq, l, pos));
        }
        sort(v.begin(), v.end());


        vector<int> positiones;
        for(auto i = v.begin(); i != v.end(); i ++){
            Ant & a = *i;
            int d = a.l ? -T : T;
            positiones.push_back(a.pos + d);
        }
        sort(positiones.begin(), positiones.end());

        for(int i = 0; i < v.size(); i++) v[i].after_pos = positiones[i];
        
        sort(v.begin(), v.end(), greater<Ant>());

        for(auto i = v.cbegin(); i != v.cend(); i ++){
            const Ant & a = *i;
            if(a.after_pos < 0 || a.after_pos > L){
                printf("Fell off\n");
            }else{
                printf("%d", a.after_pos);
            }
        } 
    }
    return 0;
}