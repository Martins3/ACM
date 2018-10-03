import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


class Main{
    Scanner in;

    public static void main(String[] args) throws FileNotFoundException, IOException {
        Main j = new Main();
        j.initScanner();
        j.solve();
        
    }

    private void initScanner() throws FileNotFoundException{
        File file = new File("../input.txt");
        in = new Scanner(file); // submit , just change to System.in
        // in = new Scanner(System.in); // submit , just change to System.in
    }

    private void solve(){
        int []stackOne = new int[100];
        LinkedList<Integer> stackTwo = new LinkedList<>();
        int p1 = 0;

        LinkedList<Integer> res = new LinkedList<>();
        LinkedList<Integer> source = new LinkedList<>();
        
        while(in.hasNext()){
            res.clear();
            source.clear();
            p1 = 0;
            String line = in.nextLine();

            String[] nums = line.split("\\s+");
            for(int i = nums.length - 1; i >= 0; i--){
                String c = nums[i];
                stackOne[p1++] = Integer.valueOf(c);
                source.addFirst(Integer.valueOf(c));
            }

            // 找到最大值， 翻转, 然后全部翻转
            // 如何处理本来就位的数值
            int count = p1;
            for(int kk = 1; kk <= count; kk++){
                int maxValue = -1;
                int index = 0;
                for(int i = kk - 1; i < count; i++){
                    if(stackOne[i] > maxValue){
                        index = i;
                        maxValue = stackOne[i];
                    }
                }   
                if(index + 1 == kk) continue;


                if(p1 != index + 1){
                    // first epoch
                    while(p1 != index){
                        stackTwo.addLast(stackOne[--p1]);
                    }
                    while(!stackTwo.isEmpty()){
                        stackOne[p1 ++] = stackTwo.removeFirst();
                    }
                    res.addLast(index + 1);
                }

                // second epoch
                while(p1 != kk - 1){
                    stackTwo.addLast(stackOne[--p1]);
                }
                while(!stackTwo.isEmpty()){
                    stackOne[p1 ++] = stackTwo.removeFirst();
                }
                res.addLast(kk);
            }

            System.out.printf("%d", source.get(0));
            for(int i = 1; i < source.size(); i++){
                System.out.printf(" %d", source.get(i));
            }
            System.out.println();

            for(int i = 0; i < res.size(); i++){
                System.out.printf("%d ", res.get(i));
            }
            System.out.println(0);
        }
    }


    void sovle_others()throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String s;
        while ((s = in.readLine()) != null) {
            Scanner stream = new Scanner(s);
            int[] a = new int[s.split(" ").length];
 
            for (int i=0; i<a.length; i++){
                a[i]= stream.nextInt();     System.out.print(a[i]+ " ");
            }
            System.out.println();
            List<Integer> flips = flips(a);
 
            for (int e : flips)     System.out.print((e+1) +" ");
 
            System.out.println(0);
        }
    }
 
    private static List<Integer> flips(int[] a) {
        List<Integer> flips = new ArrayList<Integer>();
            for(int i=a.length-1; i>0; i--){
                int maxI = maxIndex(a, i);
                if(maxI==i) continue;
                reverse(a, maxI);
                if(maxI!=0) flips.add(a.length-1-maxI);
                reverse(a, i);
                flips.add(a.length -i-1);
            }
        return flips;
    }
 
    public static int maxIndex(int[] a , int end){
        int j=0,index = 0;
        for(; j<=end;index = a[j] > a[index] ? j : index, j++);
        return index;
    }
 
    public static void reverse(int[] a, int end){
        for(int i=0, j=end ; i<j; a[i]=a[i]^a[j], a[j]=a[i]^a[j], a[i]=a[i++]^a[j--]);
    }
}