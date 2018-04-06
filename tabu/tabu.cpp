#include "./tabu.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <cstdio>
#include <set>
#include <cassert>

using namespace std;

void Tabu::initialization(bool is_he, vector<set<unsigned int> >& config){
    // init run time data structures
    solutions = vector<unsigned int>(N + 1, 0);
    best_solution = vector<unsigned int>(N + 1, 0);
    tabu_tenure = vector<vector<unsigned int> >(N + 1, vector<unsigned int>(K, 0));
    adjacent_color_table = vector<vector<unsigned int> >(N + 1, vector<unsigned int>(K, 0));
    conflict_num = 0;
    min_conflict_num = 0;

    // generate initial value
    if(is_he){
        for(size_t i = 0; i < config.size(); i ++){
            for(unsigned int v: config[i]){
                solutions[v] = i;
            }
        }
    }else{
        for(size_t i = 1; i <= N; i++) 
            solutions[i] = (unsigned int)rand() % K;
    }

    for(unsigned int x = 1; x <= N; x++){
        for(int i = nodeHead[x]; i != -1; i = graph[i].head){
            int y = graph[i].y;
            adjacent_color_table[x][solutions[y]] ++;
        }
    }

    for(size_t i = 1; i <= N; i++){
        conflict_num += adjacent_color_table[i][solutions[i]];        
    }
    min_conflict_num =  conflict_num;
    
    // print_runtime_ds();
}


void Tabu::tabu_search(int K){
    this->K = K;
    vector<set<unsigned int> > t;
    initialization(false, t);
    cout << "initialization over" << endl;

    unsigned int iter = 0;
    max_iter = 1000 * 10000;
    TabuMove tm;

    
    while(conflict_num != 0){
        assert(conflict_num >=0);
        find_move(tm, iter);
        make_move(tm, iter);
        iter ++;
        if(iter > max_iter) break;

        if(iter % 1000 == 0)
            printf("iter %u conflict %d\n", iter, conflict_num);
    }
    
    if(conflict_num == 0){
        freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/tabu/res.txt", "a", stdin);
        printf("K is %d\n", K);
        for(size_t i = 0; i < N; i++){
            printf("%d ", solutions[i]);
        }
    }
}


void Tabu::tabu_search(vector<set<unsigned int> > config){
    initialization(true, config);

    int iter = 0;
    max_iter = 1 * 10000;
    TabuMove tm;
    while(conflict_num){
        find_move(tm, iter);
        make_move(tm, iter);
        iter ++;
        if(iter > max_iter) break;
    }
}


void Tabu::find_move(TabuMove& tabu_move, unsigned int iter){
    TabuMove tabu_best_move;
    TabuMove non_tabu_best_move;


    for(int i = 1; i <= N; i++){
        if(adjacent_color_table[i][solutions[i]] != 0){
            for(int k = 0; k < K; k++){
                if(k == solutions[i]) continue;

                int delta = (int)adjacent_color_table[i][k] - (int)adjacent_color_table[i][solutions[i]];
               

                if(iter < tabu_tenure[i][k]){
                    if(delta < tabu_best_move.delta)
                        tabu_best_move = TabuMove(i, solutions[i], k, delta);
                }else{
                    if(delta < non_tabu_best_move.delta)
                        non_tabu_best_move = TabuMove(i, solutions[i], k, delta);
                }
            }
        }
    }


    // when tabu is worse and non-tabu is better, use non-tabu
    bool is_aspiration = (tabu_best_move.delta < 0 && non_tabu_best_move.delta > 0);
    if(is_aspiration)
        tabu_move = tabu_best_move;
    else
        tabu_move = non_tabu_best_move;

}

void Tabu::make_move(TabuMove& tabu_move, unsigned int iter){
    int u = tabu_move.u;
    int vi = tabu_move.vi;
    int vj = tabu_move.vj;
    int delta = tabu_move.delta;

    // change the color
    solutions[u] = vj;
    // update current conflict nums
    conflict_num = conflict_num + delta * 2;
    // update tabu tenure
    tabu_tenure[u][vi] = iter + conflict_num + (unsigned int)rand()%10;
    // update the Adjacent_Color_Table;
    for(int i = nodeHead[u]; i != -1; i = graph[i].head){
        int y = graph[i].y;
        assert(adjacent_color_table[y][vi]);
        adjacent_color_table[y][vi] --;
        adjacent_color_table[y][vj] ++;
    }
}



void Tabu::make_graph(){
    cout << "begin to make graph" << endl;
    size_t max_len = 100;
    char line[max_len];
    while(true){
        fgets(line, max_len, stdin);
        if(line[0] != 'c') break;
    }
    
    unsigned int vertex_num;
    unsigned int edge_num;
    sscanf(line + 7, "%u %u", &vertex_num, &edge_num);
    printf("vertex num %u\nedge num %u\n", vertex_num, edge_num);

    init_graph(vertex_num, edge_num);
    this->N = vertex_num;

    for(size_t i = 0; i < edge_num; i++){
        fgets(line, max_len, stdin);
        int x;
        int y;
        sscanf(line + 1, "%d %d", &x, &y);
        add_edge(x, y);
        add_edge(y, x);
    }
    // print_graph();
}

void Tabu::print_graph(){
    
    for(size_t x = 1; x <= N; x++){
        printf("%lu : ", x);
        for(int i = nodeHead[x]; i != -1; i = graph[i].head){
            printf("%d ", graph[i].y);
        }
        printf("\n");
    }
}

void Tabu::add_edge(int x, int y){
   graph[nodePointer] = Edge(x, y, nodeHead[x]);
   nodeHead[x] = nodePointer;
   nodePointer ++;
}

void Tabu::init_graph(int vertex_num, int edge_num) {
    vertex_num += 10; edge_num += 10; edge_num *= 2;
    this->nodeHead = vector<int>(vertex_num, -1);
    this->graph =  vector<Edge>(edge_num);
    nodePointer = 0;
    cout << "init graph data structure finished !" << endl;
}


Tabu::Tabu(int data_version){
    // choose a right version to make the graph
    switch(data_version){
        case 0:
            freopen("/home/martin/Downloads/DSJC500.5.txt", "r", stdin);
            break;
        case 1:
            break;
        default:
            break;
    }
    make_graph();
}


void Tabu::cross_over(vector<set<unsigned int> > config_one, vector<set<unsigned int> > config_two, 
    vector<set<unsigned int> > offspring){
        
        // make sure offspring is empty
        for(size_t i = 0; i < K; i++){
            if(i % 2){
                unsigned int max_v = 0;
                int max_i = -1;
                for(size_t j = 0; j < K; i++){
                    const set<unsigned int> & s = config_one[i];
                    if(s.size() > max_v){
                        max_v = s.size();
                        max_i = j;
                    } 
                }

                offspring.push_back(config_one[max_i]);
                for(unsigned int v:config_one[max_i]){
                    for(set<unsigned int>& s : config_two){
                        s.erase(v);
                    }
                }
                config_one[max_i].clear();
            }else{
                unsigned int max_v = 0;
                int max_i = -1;
                for(size_t j = 0; j < K; i++){
                    const set<unsigned int> & s = config_two[i];
                    if(s.size() > max_v){
                        max_v = s.size();
                        max_i = j;
                    } 
                }
                offspring.push_back(config_two[max_i]);
                for(unsigned int v:config_one[max_i]){
                    for(set<unsigned int>& s : config_one){
                        s.erase(v);
                    }
                }
                config_two[max_i].clear();
            }
        }
}


void Tabu::hybrid_evolutionary(int K){
    // 设置数值 K
    this->K = K;
   
    population_size = 10;
    vector<set<unsigned int> > t_config;
    int best_person = TabuMove::INF; // 记录population 中间的 最佳的数值
    for(size_t i = 0; i < population_size; i++){
        tabu_search(K);
        // 刚刚计算的结束， tabu search 数据的都是合法的， 此时的将数据的放到的正确的位置上面
        populations.push_back(Person(N, K, solutions, conflict_num));
        best_person = min(best_person, conflict_num);
    }
    
    // 使用什么东西作为结束条件
    while(best_person){
        int s1 = (unsigned int)rand() % K;
        int s2 = (unsigned int)rand() % K;

        vector<set<unsigned int> > offspring;
        cross_over(populations[s1].config, populations[s2].config, offspring);
        tabu_search(offspring);

        Person s0 = Person(N, K, solutions, conflict_num);
        best_person = min(best_person, s0.conflict_num);

        int worst_person = 0;
        int worst_index = -1;
        for(size_t i = 0; i < population_size; i++){
            if(populations[i].conflict_num > worst_person){
                worst_index = i;
                worst_person = populations[i].conflict_num;
            }
        }
        if(worst_index != -1) populations[worst_index] = s0;
    }
}

void Tabu::solution_to_config(const vector<unsigned int> & solution, vector<set<unsigned int> >& config){
    for(size_t i = 1; i <= N; i++){
        config[solutions[i]].insert(i);
    }
}

void Tabu::print_runtime_ds() const{
    printf("conflict num %d\n", conflict_num);
    printf("solutions\n");
    for(size_t i = 0; i < solutions.size(); i++){
        printf("%u ", solutions[i]);
    }
    printf("\n");

    printf("adjacent color table\n");
    for(size_t i = 0; i < adjacent_color_table.size(); i++){
        for(size_t j = 0; j < adjacent_color_table[i].size(); j++){
            printf("%u ", adjacent_color_table[i][j]);
        }
        printf("\n");
    }

    printf("tabu_tenure\n");
    int I = tabu_tenure.size();
    int J = tabu_tenure[0].size();
    for(int i = 1; i < I; i++){
        int j;
        for(j = 0; j < J; j++){
            printf("%u ", tabu_tenure[i][j]);
        }
        printf("\n");
    }
    printf("log finished !\n");
}