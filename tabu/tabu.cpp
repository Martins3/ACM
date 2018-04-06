#include "./tabu.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <cstdio>
#include <set>

using namespace std;

void Tabu::initialization(bool is_he, vector<set<int> >& config){
    // init run time data structures
    solutions = vector<unsigned int>(N + 1, 0);
    best_solution = vector<unsigned int>(N + 1, 0);
    tabu_tenure = vector<vector<unsigned int> >(N + 1, vector<unsigned int>(K, 0));
    adjacent_color_table = vector<vector<unsigned int> >(N + 1, vector<unsigned int>(K, 0));
    conflict_num = 0;
    min_conflict_num = 0;

    // generate initial value
    if(is_he){
        for(size_t i = 1; i <= N; i++) solutions[i] = rand() % K;
    }else{
        for(size_t i = 0; i < config.size(); i ++){
            for(int v: config[i]){
                solutions[v] = i;
            }
        }
    }

    for(int x = 1; x <= N; x++){
        for(int i = nodeHead[i]; i != -1; i = graph[i].head){
            int y = graph[i].y;
            adjacent_color_table[x][solutions[y]] ++;
        }
    }

    for(size_t i = 1; i <= N; i++){
        conflict_num += adjacent_color_table[i][solutions[i]];        
    }
    min_conflict_num =  conflict_num;
}


void Tabu::tabu_search(int K){
    this->K = K;
    vector<set<int> > t;
    initialization(false, t);

    unsigned int iter = 0;
    max_iter = 100 * 10000;
    TabuMove tm;
    while(conflict_num){
        find_move(tm, iter);
        make_move(tm, iter);
        iter ++;
        if(iter > max_iter) break;
    }
}


void Tabu::tabu_search(vector<set<int> > config){
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


void Tabu::find_move(TabuMove& tabu_move, int iter){
    TabuMove tabu_best_move;
    TabuMove non_tabu_best_move;


    for(size_t i = 0; i < N; i++){
        if(adjacent_color_table[i][solutions[i]] > 0){
            for(size_t k = 0; k < K; k++){
                if(k == solutions[i]) continue;

                int delta = adjacent_color_table[i][k] - adjacent_color_table[i][solutions[i]];

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
    bool is_aspiration = (tabu_best_move.delta >= 0 && non_tabu_best_move.delta <= 0);
    if(is_aspiration)
        tabu_move = tabu_best_move;
    else
        tabu_move = non_tabu_best_move;

}

void Tabu::make_move(TabuMove& tabu_move, int iter){
    int u = tabu_move.u;
    int vi = tabu_move.vi;
    int vj = tabu_move.vj;
    int delta = tabu_move.delta;

    // change the color
    solutions[u] = vj;
    // update current conflict nums
    conflict_num = conflict_num + delta;
    // update tabu tenure
    tabu_tenure[u][vi] = iter + conflict_num + rand()%10;
    // update the Adjacent_Color_Table;
    for(int i = nodeHead[u]; i != -1; i = graph[i].head){
        int y = graph[i].y;
        adjacent_color_table[y][vi] --;
        adjacent_color_table[y][vj] ++;
    }
}




void Tabu::make_graph(){
    size_t max_len = 100;
    char line[max_len];
    while(true){
        fgets(line, max_len, stdin);
        if(line[0] == 'c') continue;
    }
    
    fgets(line, max_len, stdin);
    unsigned int vertex_num;
    unsigned int edge_num;
    sscanf(line, "%u %u", &vertex_num, &edge_num);

    init_graph(vertex_num, edge_num); 

    for(size_t i = 0; i < edge_num; i++){
        fgets(line, max_len, stdin);
        int x;
        int y;
        sscanf(line, "%d %d", &x, &y);
        add_edge(x, y);
        add_edge(y, x);
    }
}


void Tabu::add_edge(int x, int y){
   graph[nodePointer] = Edge(x, y, nodeHead[x]);
   nodeHead[x] = nodePointer;
   nodePointer ++;
}

void Tabu::init_graph(unsigned int vertex_num, unsigned int edge_num) {
    vertex_num += 10; edge_num += 10;
    nodeHead = new int[vertex_num];
    graph = new Edge[edge_num];
    for(size_t i = 0; i < vertex_num; i++) nodeHead[i] = -1;
    nodePointer = 0;
}

Tabu::~Tabu(){
    delete [] nodeHead;
    delete [] graph;
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
                for(int v:config_one[max_i]){
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
                for(int v:config_one[max_i]){
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
        int s1 = rand() % K;
        int s2 = rand() % K;

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