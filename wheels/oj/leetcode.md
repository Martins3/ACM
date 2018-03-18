
# java 
## 数值操作

1. 整数 和 浮点数的转换
```
int(3.99)
math.round(3.99)
```
## String 操作
1. basic
    1. substring
    2. spilt string https://stackoverflow.com/questions/3481828/how-to-split-a-string-in-java
    :需要仔细的查看:
    3. concat
    4. contains
    5. match
    6. string to int: Integer.prasInt()
    7. string 去除中间的多个空格 , 使用regex https://stackoverflow.com/questions/2932392/java-how-to-replace-2-or-more-spaces-with-single-space-in-string-and-delete-lead
    8. 字符串 和字符数组的之间的转换 String.valueOf() s.toCharArray()
    9. http://javadevnotes.com/java-integer-to-string-examples  整数转化为 string
    10. string 和 null 类型
2. regex
## 数组的操作

1. subarray with copy => Arrays.copy
2. without copy => 没有的
3. 数组的内置的算法是什么 ?
4. Arrays 和 Array 的使用的区别是什么
5. 检查是否含有该元素 https://stackoverflow.com/questions/1128723/how-can-i-test-if-an-array-contains-a-certain-value
6. 从array 到达 list
7. 如果想要copy 整个数组, 如何处理: System.arraycopy( src, 0, dest, 0, src.length ); 或者 clone()

## 数据结构的架构是什么东西 ?

### Map
1. TreeMap 含有分割map的方法 返回结果是 interface SortedMap
2. 对于一个map 需要按照 value 进行排序 https://stackoverflow.com/questions/109383/sort-a-mapkey-value-by-values-java
3. ???? 不知道上面的方法是不是可以直接使用内部类的方法
4. https://stackoverflow.com/questions/46898/how-to-efficiently-iterate-over-each-entry-in-a-map

### vector 是什么
1. 需要查看大家对于 vector的看法, 了解 vector的实现方法, 以后尽量不要使用 LinkedList

### stack
1. stack 的 add 和 push 的区别是什么

### LinkedList 
1. 不可以使用 int ,但是可以包括 Integer 的类型
2. 添加多个元素, 只有addAll(Arrays.asList()的操作) 

### Queue 
1. 整体的架构是什么


### Comparator and Comparable
1. 区分好像是 class implement comparable 但是可以传入的comparator
2. 不知道为什么是使用的

### 常用操作
LinkedList ll = new LinkedList(Arrays.asList(sa));
int[] array = list.stream().mapToInt(i->i).toArray();
System.out.println(Arrays.toString(tree.entrySet().toArray()));
Arrays.copyOfRange(Object[] src, int from, int to) // 复制,和原来的没有关系

返回值是 List<List<String>> 的时候如何处理, 定义的时候就是应该处理好的
```
https://stackoverflow.com/questions/8180430/how-to-override-equals-method-in-java

@Override
public boolean equals(Object obj) {
    if (obj == null) {
        return false;
    }
    if (!Person.class.isAssignableFrom(obj.getClass())) {
        return false;
    }
    final Person other = (Person) obj;
    if ((this.name == null) ? (other.name != null) : !this.name.equals(other.name)) {
        return false;
    }
    if (this.age != other.age) {
        return false;
    }
    return true;
}

```




# algorithm




## edge case
1. 细节
    1. 初始化的条件是什么, 需要什么变量
    2. 结束的条件是什么
    3. 数组(字符串)的两个边界
    4. 数组(字符串)的长度为0
    5. 数值为0 ,含有正数 和负数

2. 错误
    1. 变量的状态变化不清晰
    2. 写完程序没有检查, 写之前没有规划,应该是按照规划的路径进行的,始终确保自己在路径之中

3. 常用算法
    1. sqrt
    2. 平方数
    3. 

4. misc
    1. 问题是 检查的边界条件是随着使用的操作而产生的, 所有的操作都是含有局限性, 每一步写下去都是可以导致其他的问题的


5. two pointer 的 核心是什么 ? 

6. 在一个递增的数组中间查找 离目标数值 最近的元素的算法是什么 ?



6. 微算法 => 
    1. while 的边界控制, while 总是保证保证自己的入口是正确的,但是如果在while 的中间对于变量修改(b ++ 导致 b == arr.length), 请小心的处理越界的为题

## 回文
1. [最长回文子序列](https://en.wikipedia.org/wiki/Longest_palindromic_substring)
2. longest palidromic subsequence



# some question
1. java 如何返回多个类型的数值, 比如map和 int
2. java 为什么没有赋值函数   
3. 导致 null pointer exception 的原因是啥 ?
4. 为什么会导致出现 辅助的递归函数, 什么时候本体就是递归函数的


# 错误的类型是什么:
    1. 某些数值没有考察
        1. 0
        2. 数组边界
        3. 循环的边界
        4. 数值溢出
    2. 算法设计出现问题
    3. 


# todo
1. stack over flow 高分问题的处理 ?
2.   