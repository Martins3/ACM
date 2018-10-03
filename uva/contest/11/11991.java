import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.TreeMap;

class Main{

    public static void main(String[] args) throws Exception{
        solve();
    }

    private static void solve() throws Exception { 
        File file = new File("../input.txt");
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        String line;
        while((line = br.readLine())!= null){
            String[] NM = line.split("\\s+");
        int N = Integer.parseInt(NM[0]);
        int M = Integer.parseInt(NM[1]);

        TreeMap<Integer, ArrayList<Integer>> map = new TreeMap<>();

        ArrayList<Integer> list;
        line = br.readLine();
        String[] nums = line.split("\\s+");

        for(int i = 0; i < N; i++){
            int num = Integer.parseInt(nums[i]);
            if(map.containsKey(num)){
                list = map.get(num);
                list.add(i + 1);
            }else{
                ArrayList<Integer> a = new ArrayList<>();
                a.add(i + 1);
                map.put(num, a);
            }
        }

        for(int i = 0; i < M; i++){
            line = br.readLine();
            String[] kv = line.split("\\s+");
            int k = Integer.parseInt(kv[0]);
            int v = Integer.parseInt(kv[1]);
            
            if(!map.containsKey(v)){
                System.out.println(0);
                continue;
            }
            
            list = map.get(v);
            if(k > list.size()){
                System.out.println(0);
                continue;
            }
            
            System.out.println(list.get(k - 1));
        }
    }
    }
}