//
// Created by martin on 17-12-12.
//
class DisjointSet{
public:
    const int size;
    int * arr; // for union
    int * rank;
    DisjointSet(int num):size(num + 1){
        arr = new int[size];
        for (int i = 0; i < size ; ++i) {
           arr[i] = 0;
        }
        rank = new int[size];
        for (int i = 0; i < size ; ++i) {
            rank[i] = 0;
        }
    }

    ~DisjointSet(){
        delete [] arr;
        delete [] rank;
    }


    int find(int x);

    void unite(int x, int y);

};



int DisjointSet::find(int x) {
    if(arr[x] == 0) return x;
    arr[x] = find(arr[x]);
    return arr[x];
}

void DisjointSet::unite(int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);
    if(x_parent == y_parent) return;

    int x_rank = rank[x];
    int y_rank = rank[y];

    if(x_rank > y_rank){
        arr[y_parent] = x_parent;
    }else{
        if(x_rank == y_rank) rank[x] ++;
        arr[x_parent] = y_parent;
    }
}
