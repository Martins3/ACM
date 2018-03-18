# Three
## 正则表达式
1. \d \D \w \W \s
2. ? []  . $ -
3. \* {} +
4. a(?!b) (?i) (?s) (?m)
5. use // to get special character original meaning
    ```
          String pn = "12|12|34|2345|2345|2345|2345|333";
          Pattern pattern = Pattern.compile("\\|");
          Matcher matcher = pattern.matcher(pn);
          matcher.find();
          System.out.println(matcher.start());
            
          matcher.find();
          System.out.println(matcher.start());
    ```
6. 
    1. matcher.find() 查找
    2. matcher.matches() 匹配 
    3. matcher.lookingAt() 

Pattern.compile(patternString, Pattern.CASE_INSENSITIVE);
```
            Pattern p = Pattern.compile("\\* .+");
            Matcher m = p.matcher("\\*  ");
            System.out.println(m.matches());
            System.out.println(m.find());
```
7. 使用中括号 和 转义:
    1. 表示数值的三个符号 * + ? 在[] 中间直接就是对应的字符
    2. 如果在[]的外面, 同时需要就是为了表示该字符, 使用\\\\(两\斜杠)
    3. 特殊字符集需要使用两个斜杠



## 熟悉常用字符串算法
    1. 解析地址
    2. 解析字符串
    3. string 匹配
    4. 最长回文串(2)

## misc
4. spilt

## scanner
1. readLine 有没有读取到 \n
2. readInt 之后,不要立刻使用for readLine, 会导致读取空行的情况

## String
1. readLine()自动忽略括号
2. trim 删除 white space, 但是white space的含义为: regex 中的\t
3. replace 表示替换字母 replaceAll 才是正则表达式, 如果替换第一个使用 replaceFirst

## trick
1. read form right to left
2. java switch 自动状态机 + 之前的状态集合
3. 对于结尾的 空格 CCF 检查与否

## infinite state machine
1. 状态的总数目
2. 状态的识别
3. 状态的转换


# Four
1. GeeksForGeeks 上面的所有的代码实现一遍
    1. BFS DFS
        1. 有向图的全连通的分量 和 拓扑排序
        2. bridge
        3. Euler
    2. 最短路径
    3. 最小生成树
    4. 最大流

2. 图算法需要使用的标准的组件为

details:
1. 有向图: 创建Edge类
2. 如果含有重复的边如何处理: 输入的时候, 应该不会这样的恶心
3. 数组泛型的问题 : LinkedList<Integer>[] a = new LinkedList[Num];
4. 创建之后立刻 初始化 !
5. 当使用递归的时候, 操作语句放置在 递归语句的前面还是后面需要仔细的分析
    1. visited 语句的位置, mostly 在前面
    2. 拓扑排序, 在后面
6. 什么时候标记 visited[x] = true 绝对不可以dfs 的外面添加, 如果一次就是解决了 ???   


10. 


# Five


# MIS
1. 对于多少可以使用 遍历
2. 有时候使用两个数组处理第二题
3. what is the key point to check !
 