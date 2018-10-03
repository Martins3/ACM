import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Stack;

class Main{

    Scanner in;
    public static void main(String[] args) throws FileNotFoundException {
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
        class Pair{
            int x;
            int y;
            Pair(int x, int y){
                this.x = x;
                this.y = y;
            }
        }
        int N;
        LinkedList<Pair> data = new LinkedList<>();
        while(in.hasNextInt()){
            N = in.nextInt();
            data.clear();
            for(int i = 0; i < N; i++){
                int x = in.nextInt();
                int y = in.nextInt();
                data.addLast(new Pair(x, y));
            }
        Stack<Integer> s = new Stack<>();
        PriorityQueue<Integer> p = new PriorityQueue<>((x, y) -> y - x);
        LinkedList<Integer> q = new LinkedList<>();
        boolean isStack = true;
        boolean isPriority = true;
        boolean isQueue = true;

        // test if is stack
        for(Pair d: data){
            int x = d.x;
            int y = d.y;
            if(x == 1){
                s.push(y);
            }else{
                if(s.isEmpty() || s.pop() != y){
                    isStack = false;
                    break;
                }
            }
        }

        for(Pair d: data){
            int x = d.x;
            int y = d.y;
            if(x == 1){
                p.add(y);
            }else{
                if(p.isEmpty() || p.poll() != y){
                    isPriority = false;
                    break;
                }
            }
        }


        for(Pair d: data){
            int x = d.x;
            int y = d.y;
            if(x == 1){
                q.addLast(y);
            }else{
                if(q.isEmpty() || q.pollFirst() != y){
                    isQueue = false;
                    break;
                }
            }
        }
        printRes(isStack, isQueue, isPriority);
        }
    }
    
    void printRes(boolean a, boolean b, boolean c){
        String[] ans = {"stack", 
            "queue",
            "priority queue", 
            "impossible",
            "not sure"
            };


        if(a && !b && !c) {
            System.out.println(ans[0]);
            return;
        }
        if(!a && b && !c) {
            System.out.println(ans[1]);
            return;
        }
        if(!a && !b && c) {
            System.out.println(ans[2]);
            return;
        }
        if(!a && !b && !c){
            System.out.println(ans[3]);
            return;
        }

        System.out.println(ans[4]);

    }
}