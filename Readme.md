# My ACM Journey
[poj profile](http://poj.org/userstatus?user_id=huxueshiOne)

# todo list
## POj
1. http://poj.org/problem?id=3276
2. http://poj.org/problem?id=3684
## Leetcode
1. 367
2. https://leetcode.com/problems/palindrome-pairs/description/
3. https://leetcode.com/problems/self-crossing/description/
4. 397
5. 456 并不知道如何使用stack 解决


# leetcode 错误总结
1. 840 审题错误， distinct number from 0 to 20
2. 605 没有分析flowerbed 边缘情况
2. 190 乖乖， 反转数据还可以错
3. 807 静态数组没有memset
4. 675 没有处理数组最后面的一个数值
5. 504 注意到事情没有log, 导致0 没有分析到
6. 202 逻辑没有分析完全
7. 845 分析错误，应该使用two points 来处理才可以
8. 306
    1. 递归函数　没有处理完成所有的情况
    2. 题目意思理解错误
9. 494
    1. 当元素的个数只有一个的时候，没有处理正数和负数的情况
    2. 输出过量
10. 703
    1. 对于go 的interface的理解含有问题
    2. You may assume that nums' length ≥ k-1 and k ≥ 1.


| Num | Title             | Reason                                                                                                                                |
|-----|-------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| 31  | next permutation  | 从右向左，找到一个数值 i(下标 i_index), 在其右边存在数字 j, j > i, 将两者替换之后，在 i_index 后面的数值**应该排序**                  |
| :star: 40  | ombination sum ii | 使用 sort unique erase 来清新相同的项目，但是可以在深度搜索的时候限制，限制方法是 : 分析和上一次深度搜索的关系，如果上一次深度搜索的时候没有使用重复的数值，那么这一次也一定是不需要的 |
| 1615| maximal network rank| find_if 使用。对于数据排序之后，数组下标已经不是数据节点了。 |
| 1371| find-the-longest-substring-containing-vowels-in-even-counts|题目看错了，将包含偶数个看做了包含 2 个，即使在这个思路下，也是简单问题复杂化了, 后面写了好几种错误的接法，实际上，思想是，记录a e i o u 数量组合的 index ，然后做差值|

## leetcode 尚未尝试的
1. https://leetcode.com/problems/task-scheduler/description/ 
2. https://leetcode.com/problems/largest-rectangle-in-histogram

## 总结
945 : 积分


