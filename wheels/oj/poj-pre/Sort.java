import com.sun.org.apache.xpath.internal.SourceTree;

/**
 * Sort
 * 
 * Reading some advanced material is much painful
 * these code is ladder for them
 * 
 * @author Hu Bachelar
 */
public class Sort {
    /**
     * 排序的原理: 如果数值的取值比较小的范围的, 可以的实现对于的数值的排序在O(n)的时间, 
     * 其中 n 表示为数值的取值的范围
     * 本次实现假定所有的数值在0 和 k 之间的(包括k)
     */
    private static int[] countingSort(int[] arr){
        int[] A = new int[arr.length];
        System.arraycopy(arr, 0, A, 0, arr.length);
        
        int[] B = new int[arr.length]; // the output buffer

        int max = 0;
        for(int i: A){
            max = Math.max(max, i);
        }

        int[] C = new int[max + 1]; 
        // index means how many elements in A is not bigger than i

        for(int i: A){
            C[i]++;
        }

        for(int i = 0; i < max; i ++){
            C[i + 1] += C[i];
        }

        for(int i: A){
            B[C[i] - 1] = i;
            C[i] --;
        }
        return B;
    }


    /**
     * 按照数位进行排序, 而且从低位到高位进行排序
     */
    private static int[] radixSort(int[] arr){
        return null;
    }
    
    private static int[] bucketSort(int[] arr){
        return null;
    }

    private static void print(int[] arr){
        for(int i: arr){
            System.out.print(i + " ");
        }
        System.out.println();
    }
   
    public static void main(String[] args) {
        int[] a = new int[]{3, 3 , 4, 4, 5, 6, 1, 0, 0, 0 };
        print(countingSort(a));


    }
}