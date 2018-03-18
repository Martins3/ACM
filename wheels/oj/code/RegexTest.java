import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * 脑残: 所有的斜杠全部都是反过来的
 */
public class RegexTest {  

      public static void main(String[] args) {  
            Pattern p = Pattern.compile("a");
            Matcher m = p.matcher("aa s");
            System.out.println(m.find());
      }

      private void fuckingDemo(){
          /*  
           * 普通字符  
           */  
          String str1 = "abc45abc345";  
          String[]arr1 = str1.split("abc");  
          for (String string : arr1) {  
              System.out.print(string+"-->");  
          }  
          System.out.println();  
            
            
          /*  
           * 简单的转义字符  
           * 在java中转义字符时一定要用双反斜线,两个斜线转义成一个斜线,  
           * 在用这个斜线字符转义那些特殊字符.  
           */  
          String str2 = "^$()[]{}.?+*|";  
          boolean flag = str2.matches("\\^\\$\\(\\)\\[\\]\\{\\}\\.\\?\\+\\*\\|");
          System.out.println(flag);  
        

            
          /*  
           * 转义字符 /Q.../E.  
           */  
          String str3 = "^$()[]{}.?+*|99999";  
          boolean flag2 = str3.matches("\\Q^$()[]{}.?+*|\\E\\d{5}");
          boolean tempFlag = str3.matches(".*");
          System.out.println(tempFlag);
          System.out.println(flag2);
          String too = "1212313421442341234";
          String[] tooMany = too.split("2", -1);
          for (String i : tooMany) {
              System.out.println(i);
          }
          /*  
           * 字符集合  
           */  
          String str4 = "dfddri334";  
          boolean flag4 = str4.matches(".+");  
          System.out.println(flag4);  
            
          String str5 = "#$%^*())%";  
          boolean flag5 = str5.matches("\\W{9}");  
          System.out.println(flag5);  
            
          String str6 = "4gffmdkekrhhr";  
          boolean flag6 = str6.matches("//w+");  
          System.out.println(flag6);  
            
          String str7 = "fjfdke    eett ";  
          boolean flag7 = str7.matches("\\w+//s+//w{4}//s?");  
          System.out.println(flag7);  
            
          String str8 = "   erefff    ";  
          boolean flag8 = str8.matches("\\s+\\S+\\s+");  
          System.out.println(flag8);  
            
          String str9 = "456776888";  
          boolean flag9 = str9.matches("//d+");  
          System.out.println(flag9);  
            
            
          String str10 = "rtydfgrgwvr  ";  
          boolean flag10 = str10.matches("//D+");  
          System.out.println(flag10);  
            
            
          /*  
           * 自定义字符集合 [ ]  
           */  
          String str11 = "fdfeetg  34566";  
          boolean flag11 = str11.matches("[fdetg]+//s+[3-6]+");  
          System.out.println(flag11);  
            
            
          String str12 = "rtyuie   5768";  
          boolean flag12 = str12.matches("[^abcdf]+//s+[^1234]+");  
          System.out.println(flag12);  
            
            
          /*  
           * 匹配次数限定符  
           */  
            
          //贪婪模式  
          String str13 = "ytreggcv454444444333";  
          boolean flag13 = str13.matches("//w{20}");  
          System.out.println(flag13);  
            
          boolean flag14 = str13.matches("//w{10,21}");  
          System.out.println(flag14);  
            
          boolean flag15 = str13.matches("//w{18,}");  
          System.out.println(flag15);  
            
          String str14 = "4";  
          boolean flag16 = str14.matches("//d?");  
          System.out.println(flag16);  
            
          String str15 = "ddcvgt";  
          boolean flag17 = str15.matches("//D+//d?");  
          System.out.println(flag17);  
            
          String str16 = "e33tf44t44t";  
          boolean flag18 = str16.matches("//w+//W*");  
          System.out.println(flag18);  
            
          //勉强模式(只举一例)  
          String str17 = "34567ghjkkld";  
          boolean flag19 = str17.matches("//d{2,7}?//w{8,11}");  
          System.out.println(flag19);  
            
          //占有模式(只举一例)  
          String str18 = "22222ddddd";  
          boolean flag20 = str18.matches("//d{2,5}+//w{6}");  
          System.out.println(flag20);  
            
          /*  
           * 字符边界  
           */  
          String str19 = "a444545rot44tm";  
          boolean flag21 = str19.matches("^a//w+m$");  
          System.out.println(flag21);  
            
            
          /*  
           * 选择表达式 xxx | xxx  
           */  
          String str20 = "abc123abc";  
          boolean flag22 = str20.matches("(abc|123){3}");  
          System.out.println(flag22);  
            
            
          /*  
           * 分组 ( ).  
           * 以上修饰符都是针对一个字符进行修饰.如果要对一组字符进行  
           * 修饰就要用到()  
           */  
          String str21 = "123qwe123qwe";  
          boolean flag23 = str21.matches("(123qwe){2}");  
          System.out.println(flag23);  
            
            
          /*  
           * []中的交集与并集  
           */  
          String str22 = "abcdefgh1234567";  
          boolean flag24 = str22.matches("[a-z1-9]+");        //并集  
          System.out.println(flag24);  
            
          boolean flag25 = str22.matches("[a-z1-9&&[a-h1-7]]+"); //交集  
          System.out.println(flag25);  
      }
}
