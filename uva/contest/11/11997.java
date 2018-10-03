import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;
/**
 * 算法思想是什么：
 *  1. 
 */

class UVa11997{

    public static void main(String[] args) throws Exception {
        solve();
    }

    private static void solve() throws Exception{
        File file = new File("../input.txt");
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
       // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        String line;
        String[] datas;
        ArrayList<PriorityQueue<Integer>> queues;
        int[] nums;
        int[] res;
        while((line = br.readLine()) != null){
            int N = Integer.parseInt(line);
            nums = new int[N];
            queues = new ArrayList<>();
            res = new int[N];
            

            for(int i = 0; i < N; i++){
                line = br.readLine();
                datas = line.split("\\s+");
                PriorityQueue<Integer> q = new PriorityQueue<>();
                for(int j = 0; j < datas.length; j++){
                    int a = Integer.parseInt(datas[j]);
                    q.add(a);    
                }
                queues.add(q);
            }

            int sum = 0;
            for(int i = 0; i < N; i++){
               nums[i] = queues.get(i).poll(); 
               sum += nums[i];
            }
            res[0] = sum;


            for(int i = 1; i < N; i++){
                int index = 0;
                int min = Integer.MAX_VALUE;
                for(int j = 0; j < N; j++){
                    int d = queues.get(j).peek() - nums[j];
                    if(d < min){
                        index  = j;
                        min = d;
                    }
                }
                
                res[i] = sum + min;
                queues.get(index).poll();
            }

            for(int i = 0; i < N - 1; i++){
                pw.printf("%d ", res[i]);
            }
            pw.printf("%d\n", res[N- 1]);
            pw.flush();
        }

    }
}