#include<stdio.h>
#include<stdlib.h> // malloc 
#include<string.h> // strcmp ..
#include<stdbool.h> // bool false true
#include <stdlib.h> // sort


struct Student{
    int grade;
    char name[20];
    int age;
};

typedef struct Student * StuPtr;

// int const void *
int compare(const void * A, const void * B){
    StuPtr a = (StuPtr)A;
    StuPtr b = (StuPtr)B;

    int y = a->age - b->age;
    if(y) return y;

    int x = a->grade - b->grade;
    if(x) return x;

    return strcmp(a->name, b->name);
}


int main(){
    int N;
    
    while(scanf("%d", &N) == 1){
        StuPtr students = (StuPtr)malloc(sizeof(struct Student) * N);
        
        for (int i = 0; i < N; ++i) {
            scanf("%d%s%d", &(students + i)->grade, ((students + i)->name), &((students +i)->age));
        }

        qsort(students, N, sizeof(struct Student), compare);

        for (int i = 0; i < 3; ++i) {
            printf("%d %s %d\n", (students + i)->grade, ((students + i)->name), ((students +i)->age));
        }
    }

    return 0;
}
