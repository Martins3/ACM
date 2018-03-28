## STL
1. lower_bound
```
 std::vector<int> data = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };
 
    auto lower = std::lower_bound(data.begin(), data.end(), 4);
    auto upper = std::upper_bound(data.begin(), data.end(), 4);
 
    std::copy(lower, upper, std::ostream_iterator<int>(std::cout, " "));
 
    
    auto j = lower_bound(num.cbegin(), num.cend(), t);
    if(*j == t){
        printf("%d found at %d\n", t, (int)distance(num.cbegin(), j) + 1);
```
2. transform

3. swap 
    1. 如果的使用swap 的对象是局部的对象， 会有问题吗 ？
        void clear( std::queue<int> &q ){
            std::queue<int> empty;
            std::swap( q, empty );
        }
    2. 

4. pair
    1. There is no difference between using make_pair and explicitly calling the pair constructor with specified type arguments. std::make_pair is more convenient when the types are verbose because a template method has type deduction based on its given parameters.
    2. Aside from the implicit conversion bonus of it, if you didn't use make_pair you'd have to do
    ```
    one = pair<int,int>(10,20)
    ```
    3. Pair can be assigned, copied and compared. The array of objects allocated in a map or hash_map are of type ‘pair’ by default in which all the ‘first’ elements are unique keys associated with their ‘second’ value objects.
    4. pair and set:
    ```
    map<int, int> m;
    m.insert(pair<int, int>(1, 2));
    ```

5. copy

## priority_queue
1. 默认为最大堆
2. std::priority_queue<int, std::vector<int>, std::greater<int> > my_min_heap; 

## set
1. 添加的元素是对象
    1. 对于对象排序
    2. 对象的equal的比较
    如果在class 中间的重载了运算符 < 那么就是可以保证 如果两者没有大小关系， 那么不会出现
    只有第一个元素会被添加， 比较关系也是的排序的基准。
    
2. 查询是否含有
    find(x) == set.end()


## vector
1. how to initialize a vector
```
vector<int> a;
 
vector<int> a(12, 100);

vector<int> a{12, 100};


int arr[] = { 10, 20, 30 };
int n = sizeof(arr) / sizeof(arr[0]);
vector<int> a(arr, arr + n);

vector<int> vect1{ 10, 20, 30 };
vector<int> vect2(vect1.begin(), vect.end());
```
2. 


## map
1. 对于key 会实现默认的排序
2. erase 删除　可以使用的指针，也可以使用　 key

# iterator
// map::begin/end
```
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}
```

##　使用find 而不是　strstr 