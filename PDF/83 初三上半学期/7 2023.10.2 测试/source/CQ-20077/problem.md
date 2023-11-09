# problem

$$
\mathrm{K Mn O_4} \xrightarrow{\text{加热}} \mathrm{K_2 Mn O_4 + MnO_2 + O_2}
\\
\mathrm{K Cl O_3} \xrightarrow[\text{加热}]{\mathrm{MnO_2}} \mathrm{K Cl + O_2}
\\
\mathrm{H_2 O_2} \xrightarrow{\mathrm{Mn O_2}} \mathrm{H_2 O + O_2}
$$

给我程序多吸点氧！:dog:

## 棋局（a）

$7$ 秒 $\mathrm{1024MiB}$ 是什么刁钻题。:cry:

不会。

很显然这道题并不简单。

感觉像是 CDQ 分治这类的题（因为需要用到类似于二维树状数组的东西），但是显然不会。

直接模拟。

## 报数（b）

如果没记错这个是给初二暑假考试的第二题。

记得是个前缀和二分什么的题。

给 $a$ 数组排序再前缀和然后二分平均值。:happy:

## 熙攘市场今何在 ~ Immemorial Marketeers（marketeers）

肯定是先把最大字典序找出来。

所以每次先找小于当前最小数的最大数，找不到则找小于当前次小数……以此类推。

先把每个 $S_i$ 中的最小值在 `set` 中找到严格小于的，然后再把这个严格小于的数查找第一个大数。

没有满足要求的就选最大的。

嗯，已经找到最大字典序的方案了。

然后求 $B$ 数组即求逆序对。

$B$ 数组也找到了。

接下来该怎么做？

$n=2000$ 时跑得飞快，$n=5000$ 爆满。

~~捆绑测试还是别想骗分了。~~

## 熙攘市场今何在 ~ Bustling Marketplace（marketplace）

不管了闪击部分分吧。

~~出题人怎么给部分分给的这么少。~~