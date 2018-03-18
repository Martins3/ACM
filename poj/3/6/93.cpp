/**
 * 找到循环次数最多的子串, 转化为lcp(longest common substring 问题
 * 1.
 *
 * 枚举开始求解: 枚举长度, 然后求解含有最大重复子串开始的位置
 *
 * 为什么需要含有数值为m, 由于使用基数排序, 使用两个数组分别为x, y,数值的长度为的2 ,基数排序
 * 为什么长度总是向右边移动一位, 由于使用的时候, 表示对于位置实现依次比较, 注意的
 *
 * 在哪一个位置需要使用最后的一个位置设置为0,
 *
 * 计算后缀数组的时候, 为什么会计算rank 数组
 *
 * 解释一下基数排序是什么:
 * 1. 保持原来的相对顺序不变, 然后每次使用其中一个字符实现排序: 宛如智障的操作
 * 2. 计算所有字符的出现个数,
 * 3. 基数排序需要要求数值从1开始,
 *
 *
 * http://dongxicheng.org/structure/suffix-array/
 *
 *
 *
 */

#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
const int MAXN = 100005;

class RadixSort{
public:
    int * arr;
    int range; // 最大值, inclusive
    int len; // arr 的长度
    vector<int> frequency;


    RadixSort(int * arr, int len, int range): arr(arr), range(range) , frequency(range + 1), len(len){}

    /**
     * 排名连续的, 如果排名是连续, 那么只是需要统计到底含有多少个字母为空就是可以的
     */
    void sort(){
        // 1. 统计数值出现的次数
        for (int i = 0; i < len; ++i) {
            frequency[i] ++;
        }

        // 2. 对于 frequency 数组进行累加, 统计每一个数值前面有多少排名
        for (int j = 1; j < frequency.size(); ++j) {
            frequency[j] += frequency[j - 1];
        }

        // 3. 计算字符的排名是什么, 保证前面出现的含有更高排名
        for (int k = len - 1; k >= 0; k--) {
            // rank[k] = --frequency[arr[k]];
            arr[--frequency[arr[k]]] = k;
        }
    }
};

/**
 * 基于ST表 最小值的
 * 1. 和线段树有什么关系, 使用主席树连区间第几个都是可以查询的
 * 2.
 *
 * 基本的操作的方法:
 * 1. 需要二维的数组, 大小分别为
 * 2. dp[i,j] 表
 */
//rnk从0开始
//sa从1开始,因为最后一个字符(最小的)排在第0位
//height从1开始,因为表示的是sa[i - 1]和sa[i]

class SuffixArray {
public:
    int wa[MAXN], wb[MAXN], wv[MAXN], ws_[MAXN];
//为了方便比较大小,可以在字符串后面添加一个字符,这个字符没有在前面的字符中出现过,而且比前面的字符都要小
//同上,为了函数操作的方便,约定除r[n-1]外所有的r[i]都大于0,r[n-1]=0
//函数结束后,结果放在sa数组中,从sa[0]到sa[n-1];

    void Suffix(const int *r, int *sa, int n, int m);
    void calHeight(const int *r, const int *sa, int n);
};
/**
 *
 * @param r     r 等待排序的元素
 * @param sa    suffix 数组
 * @param n     n 数组的长度
 * @param m     m 字符取值的范围
 */
void SuffixArray::Suffix(const int *r, int *sa, int n, int m) {
    int i, j, k, *x = wa, *y = wb, *t;

    /**
     * 对于第一个每一个字母排序, 计算每一个字符位置的排名
     * 实际上将 ws_ 初始化这么大, 简直暴殄天物
     * 同时, 原来数组复制到 x 中间, 这一个基数排序的操作宛如智障
     * 首先, x[i] 表示为 元素, ws_[] 表示元素前面的元素个数, 也就是该元素的位置,
     * 可以保证和元素的顺序也是有关的,
     * 也就是后缀数组: 对于字符串排序数组
     */
    for(i = 0; i < m; ++i) ws_[i] = 0; // 静态初始化, 为什么初始化为0
    for(i = 0; i < n; ++i) ws_[ x[i] = r[i]]++;//统计所有字母的个数字符的个数
    for(i = 1; i < m; ++i) ws_[i] += ws_[i - 1];//统计不大于字符i的字符个数,
    for(i = n - 1; i >= 0; --i) sa[--ws_[x[i]]] = i;//计算字符排名, 简直有病, 为什么不适用 r , 而是使用 x



    //基数排序
    //x数组保存的值相当于是rank值

    /**
     * 1. 总是含有两个变量, 第一个初始化之后, 然后可以得到第二个数值, 所以需要前面最开始排序
     * 2. 终结的时间是什么:
     * 3. 使用一次
     *
     * 对于第二个关键字进行排序的时候, j = j * 2, 利用之前已经比较出来的部分的
     */
    for(j = 1, k = 1; k < n; j *= 2, m = k) {
        //j是当前字符串的长度,数组y保存的是对第二关键字排序的结果
        //第二关键字排序
        for(k = 0, i = n - j; i < n; ++i) y[k++] = i;//第二关键字为0的排在前面
        for(i = 0; i < n; ++i) if(sa[i] >= j) y[k++] = sa[i] - j;//长度为j的子串sa[i]应该是长度为2 * j的子串sa[i] - j的后缀（第二关键字）,对所有的长度为2 * j的子串根据第二关键字来排序
        for(i = 0; i < n; ++i) wv[i] = x[y[i]];//提取第一关键字

        // wv 是用来搞什么的,
        //按第一关键字排序 (原理同对长度为1的字符串排序)
        for(i = 0; i < m; ++i) ws_[i] = 0;
        for(i = 0; i < n; ++i) ws_[wv[i]]++;
        for(i = 1; i < m; ++i) ws_[i] += ws_[i - 1];
        for(i = n - 1; i >= 0; --i) sa[--ws_[wv[i]]] = y[i];//按第一关键字,计算出了长度为2 * j的子串排名情况
        //此时数组x是长度为j的子串的排名情况,数组y仍是根据第二关键字排序后的结果
        //计算长度为2 * j的子串的排名情况,保存到数组x

        /**
         * 交换两个数组
         * x
         */
        t = x;
        x = y;
        y = t;
        for(x[sa[0]] = 0, i = k = 1; i < n; ++i)
            x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + j] == y[sa[i] + j]) ? k - 1 : k++;
        //若长度为2 * j的子串sa[i]与sa[i - 1]完全相同,则他们有相同的排名
    }
}


int Rank[MAXN], height[MAXN], sa[MAXN], r[MAXN];

/**
 * height[i] = suffix(sa[i-1])和 suffix(sa[i]) 的最长公共前缀
 * h[i]=height[rank[i]]
 * 理解 height[i] 数组 和 h[i] 数组:
 * 1. height[i] 表示排名为i 和 排名为 i - 1 公共前缀的最大长度
 * 2. rank[i] 的操作: 获取第 i 号元素的
 * 3.
 *
 * @param  数组
 * @param sa 后缀数组
 * @param n 字符串的长度
 */
void SuffixArray::calHeight(const int *r, const int *sa, int n) {
    int i,j,k = 0;
    for(i = 1; i <= n; i++) Rank[sa[i]]=i;

    for(i=0; i<n; height[Rank[i++]]=k)
        for(k ? k--:0,j = sa[Rank[i]-1]; r[i+k] == r[j+k]; k++);
}




int n,minNum[MAXN][17];

class RMQ{
public:
    void rangeMinQuery();
    int Ask_MIN(int a, int b);
    int calPrefix(int a, int b);
};

void RMQ::rangeMinQuery(){
    int i,j;

    int m=(int)(log(n*1.0)/log(2.0));
    for(i=1;i <= n;i++)
        minNum[i][0] = height[i];

    for(j=1;j <= m;j++)
        for(i=1;i+(1 << j)-1 <= n;i++)
            minNum[i][j]=min(minNum[i][j-1],minNum[i+(1<<(j-1))][j-1]);
}



int RMQ::Ask_MIN(int a,int b){
    int k = int(log(b-a+1.0) / log(2.0));
    return min(minNum[a][k] , minNum[b- (1 << k) + 1][k]);
}

// 获取排名的数值, 有小到大
int RMQ::calPrefix(int a, int b){
    a = Rank[a], b=Rank[b];
    if(a>b)
        swap(a,b);
    return Ask_MIN(a+1,b);
}


char s[MAXN];
int q[MAXN];

int main() {
    int i,j,k,ans,Max,cnt,p=1;
    bool flag;


    freopen("input.txt", "r", stdin);
    while(scanf("%s",s)&&s[0]!='#') {
        n = strlen(s);
        Max=0;

        // 保证数值取值范围是从 1 到 27 , lower case numbers !
        for(i=0;s[i]!='\0';i++) r[i]=s[i]-'a'+1;
        r[i]=0;

        // 获取sa 和 rank 数组

        //  首先, 计算出来后缀数组
        SuffixArray suffixArray;
        suffixArray.Suffix(r,sa,n+1,27);

        // 计算出来高度数组
        suffixArray.calHeight(r, sa, n);

        RMQ rmq;
        rmq.rangeMinQuery();


        // 读入数值, 然后加以处理
        for(i=1;i<=n;i++)
        {
            for(j=0;j+i<n;j+=i)
            {
                ans= rmq.calPrefix(j, j + i);
                k=j-(i-ans%i);
                ans=ans/i+1;
                if(k >= 0 && rmq.calPrefix(k, k + i) >=i ) ans++;
                if(Max<ans)
                    Max=ans,cnt=0,q[cnt++]=i;
                else if(Max==ans&&i!=q[cnt-1])
                    q[cnt++]=i;
            }
        }
        for(flag = false, i=1;i<=n&&!flag;i++)
            for(j=0;j < cnt&&!flag;j++)
                if(rmq.calPrefix(sa[i], sa[i] + q[j])>=q[j]*(Max-1))
                {
                    s[sa[i] + q[j] * Max]='\0';
                    flag=true;
                    printf("Case %d: %s\n",p++,s+sa[i]);
                }
    }
    return 0;
}
