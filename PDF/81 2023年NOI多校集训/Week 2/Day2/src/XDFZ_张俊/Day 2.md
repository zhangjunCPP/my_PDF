### Day 2

#### T1

题都没读懂，这个$Q(p)$是怎么构造的？

$Q(p)=i$，$Q$是一个序列，$i$是一个数，怎么等于？

$p_i<Q(p_i)$，$Q(p_i)$怎么求？

下一道

-----------

原来题面有误……

为什么题目中有一个$p_j=Q(p_j)$ ？

好像这句话很有道理

暴力算了

-------------

考虑dp

$dp[i]$ 表示长度为$i$的个数

如何转移？

打一下表，找一下规律

`int a[14]={0,0,0,1,7,47,322,2404,19778,180130,1809652,19940552,239430724};`

前13个

有一点希望，但不多

假设一个长度为$i-1$的序列$p$是优秀的，那么，我们直接在后面加上一个$i$，那么此时，这个长度为$i$的序列$p'$也是优秀的

因此，$dp[i]\ +=dp[i-1]$

有没有$dp[i-2]$的情况？

看样子多半是有的

怎么转？

先不考虑$dp[i-2]$的情况，看看新增的数量怎么求

考虑较前一种情况多出来的数$i$，肯定不能放在1号位

所以1号就只有$i-1$中可能

发现，只要$Q$序列中的1号和2号所构成的序列是优秀的，剩下的就能随便排列（好像表述的不太对，反正我理解了）



也就是说，$dp[i]\ +=(i-1)\times(i-2)\times(i-2)!$

很明显没写完全

似乎只差$dp[i-2]$的情况

---------


以我的直觉，多半是$dp[i-2]$乘上一个整数的形式

用程序除了一下，发现不是整数倍

开始乱搞

发现有一个问题，就是我如果写成$dp[i]\ +=(i-1)\times(i-2)\times(i-2)!\times 2^{-1}$的话，那么就是整数倍了，而且为 $i-1$

注意到$mod$为质数，所以可以直接求逆元

也就是说：

$$
dp[i]=dp[i-1]+dp[i-2]\times (i-1)\ +(i-1)\times (i-2)\times (i-2)!\times 2^{-1}
$$





#### T2

$n\le 10$ 乱做

$n \le 10^3$ 但是一条链，怎么做？

想看看大样例找点规律，结果，大样例死哪了？？？

由于节点是任意染色，所以黑色和白色对答案的影响都是一样的

因此，我们可以只计算黑色点对答案的贡献，然后乘以2即可

不会
