#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <forward_list>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;
#define REOPEN_READ freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/martin/X-Brain/Notes/Clang/OnlineJudge/output.txt", "w", stdout);


class Solution {
public:
    /**
     * 如何实现原地的处理 :
     * 1. 计算出来当前的形状是什么 ？
     * 2. 根据当前的形状和 折叠确定
     *      1. len depth 向上 的 数据为 那几个 depth 个 width / 2 个数据
     * 
     * 3. 长宽为 1
     * 
     * 数据总是的确保是从左边到右边的数据的，确定数据位置， 实现数据位置确定
     * 
     * @param nums: the original array
     * @param req: the direction each time
     * @return: the final folded array 
     */
    vector<int> folding(vector<int> &nums, vector<int> &req) {
        // write your code here
        // vector<int> new_nums =  nums;
        vector<int> new_nums(nums.size(), 0);
        int width = nums.size();
        int depth = 1;

        for(int i = 0; i < req.size(); i++){

            // 从左边到右边
            if(req[i] == 0){
                // 左边的数据 翻转
                // 数据分离
                int start = 0;
                int right_ind = nums.size() / 2;
                int p = 0;
                for(int j = 0; j < depth; j++){
                    for(int in = 0; in < width / 2; in++){
                        new_nums[p] = nums[j * width + in];
                        new_nums[p + right_ind] = nums[j * width + in + width / 2];
                        p++; 
                    }
                } 

            }

            // 从右边到左边
            else{
                int start = 0;
                int right_ind = nums.size() / 2;
                int p = 0;
                for(int j = 0; j < depth; j++){
                    for(int in = 0; in < width / 2; in++){
                        new_nums[p + right_ind] = nums[j * width + in];
                        new_nums[p] = nums[j * width + in + width / 2];
                        p++; 
                    }
                } 
                
            }
            reverse(new_nums.begin(), new_nums.begin() + new_nums.size() / 2);
            swap(nums, new_nums);
            // 更新的depth 和 width
            depth *= 2;
            width /= 2;
        }
        return nums;
    }
};
int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> seq = {0, 0, 1}; 
    Solution s;
    vector<int> res = s.folding(v, seq);
    for(int i = 0; i < v.size(); i++){
        printf("%d ", res[i]);
    }
    return 0;
}
/**
 * error log 
 * 没有更细的depth 也没有正常的初始化的dpeth 文件的！
 */
