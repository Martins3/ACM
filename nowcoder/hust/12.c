#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include <stdlib.h> // sort


struct Student{
    int grade;
    char name[120];
    int age;
};

typedef struct Student * StuPtr;

// int const void *
int compare(const void * A, const void * B){
    StuPtr a = (StuPtr)A;
    StuPtr b = (StuPtr)B;

    int x = a->grade - b->grade;
    if(x) return x;


    int y = strcmp(a->name, b->name);
    if(y) return y;

    return a->age - b->age;
}


int main(){
    int N;
    
    while(scanf("%d", &N) == 1){
        StuPtr students = (StuPtr)malloc(sizeof(struct Student) * N);
        for (int i = 0; i < N; ++i) {
            scanf("%s%d%d", (students + i)->name, &((students + i)->age), &((students +i)->grade));
        }

        qsort(students, N, sizeof(struct Student), compare);

        for (int i = 0; i < N; ++i) {
            printf("%s %d %d\n", (students + i)->name, ((students + i)->age), ((students +i)->grade));
        }
    }

    return 0;
}
