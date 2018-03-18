/**
 * http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
 */
#include <iostream>
#include <fstream>
using namespace std;

class KMP{

    char * pat; // the word
    int * lps;
public:
    void computeLPSArray(char *pat, int M, int *lps);
    KMP(int length, char * pat):pat(pat), lps(new int[length]){
        computeLPSArray(pat, length, lps);
        int last = length -  lps[length - 1];
        if(length % last == 0)
            printf("%d\n", length / last);
        else
            printf("%d\n", 1);
    }
};

void KMP::computeLPSArray(char *pat, int M, int *lps) {
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    // 循环的所有的位置回撤位置

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }else {
            if (len != 0) {
                len = lps[len-1];
            } else{
                lps[i] = 0;
                i++;
            }
        }
    }
}


#define MAX_SIZE 1000100
int main(){
    freopen("input.txt", "r", stdin);
    char a[MAX_SIZE];
    while (scanf("%s", a) && a[0] != '.'){
        int i;
        for (i = 0; i < MAX_SIZE; ++i) {
            if(a[i] == 0) break;
        }
        KMP kmp(i, a);
    }
    return 0;
}

