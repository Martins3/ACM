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

class Solution {
public:
    // 利用 stack 分析一下，到底是谁在运行，
    vector<int> exclusiveTime(int n, vector<string>& logs) {
      vector<int> res(n, 0);
      if(logs.empty()) return res;

      stack<int> s;
      int last_time ;

      for(string l : logs){
        replace(l.begin(),l.end(), ':', ' ');
        stringstream iss(l);
        int id;
        string e; 
        int time;

        iss >> id;
        iss >> e;
        iss >> time;

        // 还是可以遇到时钟的方法
        
        if(!s.empty()){
          if(e == "end")
            res[s.top()] ++;
          res[s.top()] += time - last_time;
          /* cout << res[s.top()] << " " << last_time << " " << time  << endl; */
        }

          if(e == "end")
        last_time  = time + 1;
          else
            last_time = time;

        if(e =="start"){
          s.push(id);
        }else if(e == "end"){
          s.pop();
        }else{
          assert(false);
        }
      }
      
      return res;
    }
};

int main(){
  Solution s;
  vector<string> log=
  /* {"0:start:0","1:start:2","1:end:5","0:end:6"}; */
  {"0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"};
  auto g = s.exclusiveTime(2, log);
  cout << g[0] << endl;
  cout << g[1] << endl;

  return 0;
}

/**
 * 错误原因 : 没有考虑非递归的情况，深层次的错误，没有设计一个更好的算法
 * 措施: 首先在脑袋中间运行一次
 */
