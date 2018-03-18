import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.List;

/**
 * StringAPI
 *  
 */
public class StringAPI {
    public static void main(String[] args) {
       StringAPI stringAPI = new StringAPI();
       boolean[] a = new boolean[10];
       System.out.println(a[0]);

    }

    private void stringBuffer(){
        // A thread-safe, mutable sequence of characters.
        // The principal operations on a StringBuffer are the append and insert methods

        // constuctor : capacity string char[]
        StringBuilder sb = new StringBuilder("123456");

        // method : insert append capacity insert lenght
        // charAt replace
        // delete deleteCharAt setCharAt 
        // indexOf lastIndexOf 
        // reverse
        System.out.println(sb.capacity());
    }

    private void stringBuilder(){
        // The StringBuilder class should generally be used in preference to this one,
        //  as it supports all of the same operations but it is faster, as it performs no synchronization.
    }

    private void string() {
        // constructor is from string stringbuilder stringbuffer or char[]
        // + op in string

        // methods: charAt subString compareTo contains equals isEmpty length indexOf
        // match spilt replace 

        // subSequence toCharArray
        

        // endWith beginWith trim
        // toUpperCase toLowerCase

        // valueOf 的唯一用途在于 toString 不可以检查 null


        String a = "abc";
        String b = "ABC";
        System.out.println(a.toUpperCase());
        a.equalsIgnoreCase(b);
        a = a.concat(b);
        a.compareToIgnoreCase(b);
        a.endsWith("ABC");
        a.indexOf(b, 1);
        a.lastIndexOf(b, 5);
        System.out.println(String.valueOf(true));
        String s = null;
        System.out.println(String.valueOf(s));

    }

    private void match(){
        String string = "Madam, I am Adam";

        // Starts with
        boolean  b = string.startsWith("Mad");  // true

        // Ends with
        b = string.endsWith("dam");             // true

        // Anywhere
        b = string.indexOf("I am") >= 0;        // true

        // To ignore case, regular expressions must be used

        // Starts with
        b = string.matches("(?i)mad.*");

        // Ends with
        b = string.matches("(?i).*adam");

        // Anywhere
        b = string.matches("(?i).*i am.*");


        // 找到所有的制定形状的所有的位置
        String s = "aaaaaa";
        Matcher m = Pattern.compile("(?=(aa))").matcher(s);
        List<Integer> pos = new ArrayList<Integer>();
        while (m.find())
        {
            pos.add(m.start());
        }
        System.out.println(pos);

        // 
        String text    =
        "This is the text to be searched " +
        "for occurrences of the http:// pattern.";

        String patternString = ".*http://.*";

        Pattern pattern = Pattern.compile(patternString);

        Matcher matcher = pattern.matcher(text);
        boolean matches = matcher.matches();
        System.out.println(matches);


        // Removes whitespace between a word character and . or ,
       String pn = "\\.\\*\\{\\}\\.\\*";
       Pattern patternOne = Pattern.compile(pn);
    }

}


