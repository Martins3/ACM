import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.TreeMap;

public class Main{
    int NumProgram;
    int[] length;
    int Quote;
    BufferedReader br;
    PrintWriter pw;

    ArrayList<ArrayList<String>> programs;
    public static void main(String[] args) throws Exception {
        Main j = new Main();
        j.initScanner();
        String line = j.br.readLine();
        int N = Integer.parseInt(line);
        j.br.readLine();
        while(N-- != 0){
            j.solve();
            j.br.readLine();
            if(N !=0)
                j.pw.printf("\n");
        }
        j.pw.flush();
    }

    private void initScanner() throws FileNotFoundException{
        File file = new File("/home/martin/X-Brain/Notes/java/WorkStation/lintcode/src/input.txt");
        br = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
//        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
    }

    private int op(String str){
        if(str.contains("=")) return 0;
        if(str.contains("print")) return 1;
        if(str.contains("unlock")) return 3;
        if(str.contains("lock")) return 2;
        if(str.contains("end")) return 4;
        return -1;
    }

    private char getVar(String str){
        if(str.contains("=")) return str.charAt(0);
        return str.charAt(6);
    }





    private void solve()throws  Exception{
        // init the computer
        String line_a = br.readLine();
        String[] data = line_a.split("\\s+");

        NumProgram = Integer.parseInt(data[0]);
        length = new int[5];
        for(int i = 0; i < 5; i++){
            length[i] = Integer.parseInt(data[i + 1]);
        }
        Quote = Integer.parseInt(data[6]);

        programs = new ArrayList<>();
        for(int i = 0; i < NumProgram; i++){
            String line;
            ArrayList<String> oneThread = new ArrayList<>();
            while(true){
                line = br.readLine();
                if(line.equals("begin")) continue;
                oneThread.add(line);
                if(line.equals("end")) {
                    programs.add(oneThread);
                    break;
                }
            }
        }

        //begin it !
        LinkedList<Integer> blockingQueue = new LinkedList<>();
        LinkedList<Integer> waitingQueue = new LinkedList<>();
        for(int i = 0; i < NumProgram; i++){
            waitingQueue.addLast(i);
        }

        TreeMap<Character, Integer> variable = new TreeMap<>();
        boolean locked = false;
        int[] programPointers = new int[NumProgram];


        // 是不是只要waitingQueue 结束就是可以了
        while(!waitingQueue.isEmpty()){
            int threadNum = waitingQueue.pollFirst();

            int time = 0;
            breakLock:
            while(true){
                String command = programs.get(threadNum).get(programPointers[threadNum] ++);
                int op = op(command);
                time += length[op];

//                pw.printf("%d -> %s\n", threadNum + 1, command);
                int num;
                char var;
                switch(op){
                    case 0:
                        String [] t = command.split("\\s+");
                        num = Integer.parseInt(t[t.length - 1]);
                        var = getVar(command);
                        variable.put(var, num);
                        break;
                    case 1:
                        var = getVar(command);
                        int t_num;
                        if(variable.get(var) == null){
                            t_num = 0 ;
                        }else{
                            t_num = variable.get(var);
                        }
                        pw.printf("%d: %d\n",threadNum + 1, t_num);
                        break;
                    case 2:
                        // 如果当前为p 操作, 被阻塞
                        if(locked){
                            blockingQueue.addLast(threadNum);
                            programPointers[threadNum] --;
                            break breakLock;
                        }
                        locked = true;
                        break;
                    case 3:
                        // v 操作
                        locked = false;
                        if(!blockingQueue.isEmpty())
                            waitingQueue.addFirst(blockingQueue.pollFirst());
                        break;
                    case 4:
                        break breakLock;
                }

                if(time >= Quote) {
                    waitingQueue.addLast(threadNum);
                    break;
                }
            }

        }
    }
}
