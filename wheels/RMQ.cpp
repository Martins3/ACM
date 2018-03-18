#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;
#define VSCODE_READ freopen("../../../input.txt", "r", stdin);
#define C_READ freopen("../input.txt", "r", stdin);
class RMQ{
public:
    int N;
    int ** arr;
    int K;
    RMQ(int N):N(N){
        arr = new int *[N];
        // 计算出来 2 ** k >= N 的最小值
        int k = 1;
        while(true) if(1 << k++ >= N) break; 
        
        K = k;
        for(int i = 0; i < N; i++){
            arr[i] = new int[k];
        }
    }
    int RMQ::rangeMin(int x, int y);
    void RMQ::readData(vector<int> & data);


};

    void RMQ::readData(vector<int> & data){
        for(int i = 0; i < N; i++){
            arr[i][0] = data[i];
        }
        
        for(int j = 1; (1 << j) <= N; j++){
            for(int i = 0; i < N; i++){
                arr[i][j] = min(arr[i][j - 1], arr[i + (1 << j - 1)][j - 1]);
            } 
        }
    }

    int RMQ::rangeMin(int x, int y){
        // 找到最大的k的数值，2 **(k + 1) <= len
        // 只是的需要覆盖的半区间就可以了
        // 边界条件， 如果正好的覆盖， 那么如何的处理的

        int k = 0;
        while(1 << (k + 1) <= (y - x + 1)) k++;
        return min(arr[x][k], arr[x - (1 << k) + 1][k]);
    }
int main(){
    
    return 0;
}