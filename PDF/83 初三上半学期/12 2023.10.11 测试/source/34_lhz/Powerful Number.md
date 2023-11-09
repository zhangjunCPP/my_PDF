如何算出 $h(x)$，首先因为 $x$ 是积性函数，所以对于 $x = \prod p_i^{c_i}(p_i\in \text{P}, c_i\ge 2)$，$h(x) = \prod h(p_i^{c_i})$，所以只用解决 $h(p^m)(p\in \text{P}, m\ge 2)$。

因为 $f(p^m) = \sum\limits_{i = 0}^m g(p^{m  - i})\times h(p^i)$，于是就有 $h(p^m) = g(1)h(p^m) = f(p^m) - \sum\limits_{i = 0}^{m - 1} g(p^{m - i})\times h(p^i)$ 。  
可以 $m$ 按从小到大的顺序来求出 $h(p^m)$，因为这样 $h(p^i)(0\le i\le m - 1)$ 都已经算出来了。  

时间复杂度应该是 $(\text{calc}(f) + \text{calc}(g))\times \sum\limits_{p \in \text{P}}^{\sqrt{n}} \log_{p} n +  \sum\limits_{p \in \text{P}}^{\sqrt{n}} \log_{p}^2 n$，对于某些 $g$ 例如 $g = I / id$ 可以线性维护，时间复杂度 $(\text{calc}(f) + \text{calc}(g))\times \sum\limits_{p \in \text{P}}^{\sqrt{n}} \log_{p} n$。

