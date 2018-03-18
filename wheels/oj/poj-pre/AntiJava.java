import java.util.LinkedList;

/**
 * AntiJava
 */
public class AntiJava {
    int a;
    String b;
    public static void main(String[] args) {
        LinkedList<Integer> a = new LinkedList<>();
        a.add(0, 2);
        a.add(3);
        a.remove(0);
        for(int i: a){
            System.out.println(i);
        }
    }
}