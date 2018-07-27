//
// Created by martin on 17-12-12.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
using namespace std;

class Cow{
public:
    int start;
    int end;
    int index;
    int res;
    bool operator > (const Cow& cow) const
    {
        if(start < cow.start) return true;
        if(start > cow.start) return false;
        return (end > cow.end);
    }
    bool operator < (const Cow& cow) const
    {
        return (index < cow.index);
    }

    Cow(int start, int end, int index):start(start), end(end), index(index){

    }
};
/**
 * what should care about:
 * 1.
 */
class BinaryIndexTree{
private:
    vector<int> arr;
    int lowBit(int x){
        return (x) & (-x);
    }
public:
    int sum(int x){
        int ans = 0;
        while(x != 0){
            ans += arr[x];
            x -= lowBit(x);
        }
        return ans;
    }

    void add(int x, int v){
        for(int i = x ; i < arr.size(); i += lowBit(i)){
            arr[i] += v;
        }
    }

    BinaryIndexTree(int size): arr(size + 1){

    }
};

/**
 * 恢复顺序有没有better way !
 *
 */
int main(){
    freopen("input.txt", "r", stdin);
    int N;
    while(~scanf("%d", &N) && N) {

        vector<Cow> cows;

        for (int i = 0; i < N; ++i) {
            int start;
            int end;
            scanf("%d%d", &start, &end);
            Cow cow(start + 2, end + 2, i);
            cows.push_back(cow);
        }

        sort(cows.begin(), cows.end(), greater<Cow>());
        const int posRange = 100000 + 5;
        BinaryIndexTree endings(posRange);


        int lastLeft = -1;
        int lastRight = -1;
        int startAtSame = 0;
        for (int j = 0; j < N; ++j) {
            if (lastLeft != cows[j].start || lastRight != cows[j].end) {
                lastLeft = cows[j].start;
                lastRight = cows[j].end;
                startAtSame = 0;
            } else {
                startAtSame++;
            }


            int end = cows[j].end;
            int res = endings.sum(posRange) - endings.sum(end - 1) - startAtSame;
            cows[j].res = res;
            endings.add(end, 1);
        }

        // sort and get back

        sort(cows.begin(), cows.end(), less<Cow>());
        for (int k = 0; k < N - 1; ++k) {
            printf("%d ", cows[k].res);
        }
        printf("%d\n", cows[N - 1].res);
    }
    return 0;
}
