#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;
#define VSCODE_READ freopen("../../../input.txt", "r", stdin);
#define C_READ freopen("input.txt", "r", stdin);
/**
 * How to prove !
 * 1. use the lightest people to handle 
 * 2. 
 */
int main(){
    VSCODE_READ
    int testNum;
    scanf("%d", &testNum);
    while(testNum){
        testNum --;
        
        int peopleNum;
        scanf("%d", &peopleNum);
        vector<int> people;
        for(int i = 0; i < peopleNum; i++){
            int weight;
            scanf("%d", &weight);
            people.push_back(weight);
        }
        sort(people.begin(), people.end());
        int res = 0;
        

        while(peopleNum >= 4){
            int a = people[0];
            int b = people[1];
            int c = people[peopleNum - 2];
            int d = people[peopleNum - 1];

            int methodOne = b + a + d + b;
            int methodTwo = c + a + d + a;
            res += min(methodOne, methodTwo);
            peopleNum -= 2;
        }

        if(peopleNum !=2){
            for(int i = 0; i < peopleNum; i++){
                res += people[i];
            }
        }else{
            res += people[1];
        }


        printf("%d\n", res);
    }
    return 0;
};