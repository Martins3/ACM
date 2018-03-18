import java.util.Arrays;


/**
 * BinaryIndexTree
 * tutorial for the BinaryIndexTree
 * 
 * application: 
 *  1. calculate cumulative frequency
 *  2. http://www.cppblog.com/menjitianya/archive/2015/11/02/212171.html
 * 
 * efficiency: 对于任何的连续区间的求和为 O(log(n)) 的时间, 修改节点的数值复杂度为的O(log(n)),
 * 此处n 为数组的长度
 * 
 * philosophy:
 * ，对于两个数组下标x，y(x < y)，如果x + 2^k = y (k 等于 x的二进制表示中末尾0的个数)，那么定义(y, x)为一组树上的父子关系，其中y为父结点，x为子结点 
 * 标记 lowBit为 2^k的时候, 那么 x + lowBit = y
 * 
 * 数组A 和 树状数组 C 的关系是什么 :
 *  1.  Ci  =  sum{ A[j] |  i - 2^k + 1 <= j <= i }  
 *  2.  
 * 
 * todo: 算法复杂度的证明
 * @author Bachelar Hu
 * 
 */
public class BinaryIndexTree {
    private int[] C;

    /**
     * 创建初始值为0的数组
     */
    private BinaryIndexTree(int num){
        C = new int[num];
    }

    /**
     * 通过A 创建 C
     */
    private BinaryIndexTree(int[] arr){
        C = new int[arr.length + 1];
        // System.arraycopy(arr, 0, C, 0, arr.length);
        for(int i = 0; i < arr.length; i++){
            add(i + 1, arr[i]);
        }
    }

    /**
     * @param x 数组下标
     * 将整数x 转化为二进制之后, 返回从低位计 最开始遇到的1
     * 比如 6为 00000110 的结果为2
     */
    private int lowBit(int x){
        return x &(-x);
    }


    /**
     * 返回从1 到 x 的求和
    */
    private int sum(int x){
         int ans = 0;
         while(x != 0){
             ans += C[x];
             x -= lowBit(x);
         }
         return ans;
    }

    /**
     * edit
     * @param x 为下标
     * @param v 增加的数值
    */
    private void add(int x, int v){
        for(int i = x ; i < C.length ; i += lowBit(i)){
            C[i] += v;
        }
    }

    public static void main(String[] args) {
        BinaryIndexTree bit = new BinaryIndexTree(10);

        // 说明lowBit的使用
        // System.out.println(bit.lowBit(5));

        
        // 测试各种基本的操作
        int[] A = new int[]{1, 2, 3};
        bit = new BinaryIndexTree(A);
        for(int i: bit.C){
            System.out.print(i + " ");
        }
        
        System.out.println();
        System.out.println(bit.sum(2) - bit.sum(1));
    
        


    }

}