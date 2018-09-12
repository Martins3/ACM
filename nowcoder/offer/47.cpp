#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>
#include <climits>
#include <deque>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>
#include <cassert>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define REOPEN_READ freopen("/home/shen/Core/ACM/input.txt", "r", stdin);
#define REOPEN_WRITE freopen("/home/shen/Core/ACM/output.txt", "w", stdout);

/**
 * 
 * 链接：https://www.nowcoder.com/questionTerminal/623a5ac0ea5b4e5f95552655361ae0a8
 * 源：牛客网
 * 不需要额外的数组或者hash table来保存，题目里写了数组里数字的范围保证在0 ~ n-1 之间
 * 所以可以利用现有数组设置标志，当一个数字被访问过后，可以设置对应位上的数 + n，
 * 之后再遇到相同的数时，会发现对应位上的数已经大于等于n了，那么直接返回这个数即
 *
 * 顺序访问　和　查找访问
 */
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length <= 1) return false;

        sort(numbers, numbers + length);
        int last = numbers[0];
        for (int i = 1; i < length; i++) {
            if(numbers[i] == last){
                *duplication = last;
                return true;
            }
            last = numbers[i];
        }

        return false;
    }
};

int main(){
    
    return 0;
}
