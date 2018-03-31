#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

class POINT{
public:
    int x;
    int y;
    POINT(int x, int y):x(x), y(y){};
    POINT(): x(0), y(0){};
    
    void print(){
        cout << "(" << x << " , " << y << ")" << endl;
    }
};

class Line{
public:
    int x1, y1;
    int x2, y2;    

    Line(const POINT & p1, const POINT & p2): x1(p1.x), y1(p1.y), x2(p2.x), y2(p2.y){};
    
    bool is_vertical(){
        return x1 == x2;
    }
    
};

bool seg_cut(int a1, int b1, int x1, int y1){
    int a = min(a1, b1);
    int b = max(a1, b1); 
    
    int x = min(x1, y1);
    int y = max(x1, y1);

    if(a >= x && a <= y) return true;
    if(b >= x && b <= y) return true;

    if(x >= a && x <= b) return true;
    if(y >= a && y <= b) return true;

    return false;
}

bool h_v_cut(const Line & l1, const Line & l2){
    // format it
    int a = min(l1.x1, l1.x2);
    int b = max(l1.x1, l1.x2);
    int c = l1.y1;

    int x = min(l2.y1, l2.y2);
    int y = max(l2.y1, l2.y2);
    int z = l2.x1;

    // do it
    return (z >= a && z <= b) && (c >= x && c <= y);
}


class Solution {
public:
    /**
     * x => document every line
     * y x y x
     * with 0 one ! when making more just check every line !
     */
    bool crossing_cut(Line & l1, Line & l2){
        int pos = 0;
        if(l1.is_vertical()) pos ++;
        if(l2.is_vertical()) pos ++;
        
        // 都是水平线
        if(pos == 0){
            if(l1.y1 != l2.y1) return false;
            return seg_cut(l1.x1, l1.x2, l2.x1, l2.x2);
        }

        // 都是垂直线
        if(pos == 2){
            if(l1.x1 != l2.x1) return false;
            return seg_cut(l1.y1, l1.y2, l2.y1, l2.y2);
        }

        // 保持的前者水平， 后者垂直
        if(l1.is_vertical()) swap(l1, l2);
        return h_v_cut(l1, l2);
    }

    // 是否的出现的相交的
    bool check_line(vector<int> & vec, int index){
        // find the cur line
        POINT lp(0, -1);
        POINT p;
        for(size_t i = 0; i <= index ; i++){
            lp = p;
            int mode = i % 4;
            int x;
            int y;
            switch(mode){
                case 0:
                    lp.y ++; 
                    x = lp.x;
                    y = lp.y + vec[i];
                    break; 

                case 1:
                    lp.x --;
                    x = lp.x - vec[i];
                    y = lp.y;
                    break; 

                case 2:
                    lp.y --;
                    x = lp.x;
                    y = lp.y - vec[i];
                    break; 

                case 3:
                    lp.x ++;
                    x = lp.x + vec[i];
                    y = lp.y;
                    break; 
            }

            p = POINT(x, y);
        }

        Line cur_line(lp, p); 
        cout << "<cur_line" << endl;
        cout << index << endl;
        lp.print();
        p.print();
        cout << "</cur_line>" << endl;


        // check all the line one by one
        lp = POINT(0, 0);
        p = POINT(0, 0);
        for(size_t i = 0; i < index; i++){
            lp = p;
            int mode = i % 4;
            int x;
            int y;
            switch(mode){
                case 0:
                    lp.y ++; 
                    x = lp.x;
                    y = lp.y + vec[i];
                    break; 

                case 1:
                    lp.x --;
                    x = lp.x - vec[i];
                    y = lp.y;
                    break; 

                case 2:
                    lp.y --;
                    x = lp.x;
                    y = lp.y - vec[i];
                    break; 

                case 3:
                    lp.x ++;
                    x = lp.x + vec[i];
                    y = lp.y;
                    break; 
            }

            p = POINT(x, y);
            Line line(lp, p);
            lp.print();
            p.print();
            if(crossing_cut(cur_line, line)) return true; 
        }
        return false;
    }

    bool isSelfCrossing(vector<int>& x) {
        size_t size = x.size(); 
        for(size_t i = 0; i < size; i++){
            if(check_line(x, i)) return true; 
        }
        return false;
    }
};
int main(){
    // REOPEN_READ
    //REOPEN_WRITE

    Solution s;
    vector<int> vec{1, 1, 1, 1};
    cout << s.isSelfCrossing(vec) << endl;

    return 0;
}