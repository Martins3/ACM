//
// Created by martin on 17-12-11.
//

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

    BinaryIndexTree(int size): arr(size + 1){}
};
