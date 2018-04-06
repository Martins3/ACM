#ifndef TABU_H
#define TABU_H
#include <string>
#include <vector>
#include <set>


class Edge{ public:
    int x;
    int y;
    int head;
    Edge(){}
    Edge(int _x, int _y, int _head):x(_x), y(_y), head(_head){}
};

class Person{
public:
    std::vector<std::set<unsigned int> > config;
    int conflict_num;
    Person(const unsigned int N, const unsigned int K, const std::vector<unsigned int> solutions, const int _conflict_num):conflict_num(_conflict_num){
        config = std::vector<std::set<unsigned int> >(K, std::set<unsigned int>());
        for(unsigned int i = 1; i <= N; i++){
            config[solutions[i]].insert(i);
        }
         
    }
};

class TabuMove{
public:
    int u;
    int vi;
    int vj;
    int delta;

    const static int INF = 0x3f3f3f3f;
    TabuMove(int _u, int _vi, int _vj, int _delta):
    u(_u), vi(_vi), vj(_vj), delta(_delta){}

    TabuMove():
    u(0), vi(0), vj(0), delta(INF){}
};

class Tabu{
private:

    // runtime data
    std::vector<unsigned int> solutions; 
    std::vector<unsigned int> best_solution;
    std::vector<std::vector<unsigned int> > tabu_tenure;
    std::vector<std::vector<unsigned int> > adjacent_color_table;
    int conflict_num;
    int min_conflict_num;

    // config data
    unsigned int N;
    unsigned int K;
    unsigned int max_iter;

    // parameters
    /**
     * 为调参的提供接口
     */
    void initialization(bool is_he, std::vector<std::set<int> >& config);
    void find_move(TabuMove& tabu_move, int iter);
    void make_move(TabuMove& tabu_move, int iter);
    void update_adjacent_table(int u, int vi, int vj);

    // graph
    int * nodeHead;
    int nodePointer;
    Edge * graph;


    void add_edge(int x, int y);
    void init_graph(unsigned int vertex_num, unsigned int edge_num);
    void make_graph();

    // Hybrid Evolutionary
    void cross_over(std::vector<std::set<unsigned int> > config_one, std::vector<std::set<unsigned int> > config_two, std::vector<std::set<unsigned int> > offspring);
    void tabu_search(std::vector<std::set<unsigned int> > config);
    unsigned int population_size;
    std::vector<Person> populations; 
    void solution_to_config(const std::vector<unsigned int> & solution, std::vector<std::set<unsigned int> >& config);

public:
    ~Tabu();
    Tabu(int data_version);

    void tabu_search(int K);
    void hybrid_evolutionary(int K);

};
#endif // !ABU_H
