#include<bits/stdc++.h>
using namespace std;
int p,k;
int ans=1,P=1;
const int maxn=2e3+5;
set<int> to[maxn];
int val[maxn];
inline bool dfs(int now,int v){
	val[now]=v;
	if(now==p){
		for(int i=1;i<=p;i++){
			printf("%d ",val[i]);
		}
		puts("");
		for(int i=1;i<=p;i++){
			for(int j=i+1;j<=p;j++){
				to[val[i]].erase(val[j]);
			}
		}
		return true;
	} 
	for(auto TO:to[v]){
		bool f=1;
		for(int i=1;i<=now;i++){
			if(to[val[i]].find(TO)==to[val[i]].end()){
				f=0;
				break;
			}
		}
		if(!f) continue;
		if(dfs(now+1,TO)) return true;
	}
	return false;
} 
int main(){
	freopen("chess.in","r",stdin); 
	freopen("chess.out","w",stdout); 
	scanf("%d%d",&p,&k);
	for(int i=1;i<k;i++) P*=p,ans+=P;
	ans*=P;
	printf("%d\n",ans);
	P*=p;
	for(int i=0;i<P;i++){
		for(int j=i+1;j<P;j++){
			to[i].insert(j);
		}
	}
	for(int i=0;i<P;i++){
		while(dfs(1,i));
	}
	return 0;
} 
/*
答案上借一定是下取整：
p^k(p^k-1)/p(p-1)
因为每分一组会消耗 p/(p-1) 个无序对
应该能构造出来这种解
而且还能因式分解，证明出他是一个整数为：
p^(k-1) (p^(k-1)+p^(k-2)+....+p+1)
从理论上来说，我是不是乱找都能找到。
因为我每分出一个组，产生的贡献都是内部的，和外部没关系。
2e3*2e3 大概有4e6组。 
怪糟糟的，也没使用 p 是一个质数这个条件。
过了30min，检查15min吧。
好像我这样搞不是很行。 
应该和质数这个条件有关。 
我感觉我这个上界做不到。
但他必须得做到，不然这题还能怎么做？
想到个新的构造方法。
直接平推分成 p^k-1 组
选取每组的第一个数出来，平推 p^k-2 组。
这样可以直接分出 p^k-1+.....p+1 组，如果能推 p^k-1 次，答案就成立
同理我们可以选出每一组的第二个，往下推，感觉是对的。
就是一个分治的过程。
C(p^k)=p^k-1+C(p^k-1)*p^(p^k-1)
感觉就是正解，之前想偏了。
好像还是不对。
0 1 / 2 3 / 4 5 / 6 7
0246 1357
0 2 / 4 6 / 1 3 / 5 7
0 4 / 2 6 / 1 5 / 3 7

0347 1256
0 3 / 4 7 / 1 2 / 5 6
0 4 / 3 7 / 1 5 / 2 6

这样构造也不是很行。
真就无语了。

换一种构造
p^k-1+p^k-2.........1
p^k 
0 [ ] [ ] [ ] [ ]......
1 []-1 []-1 []-1 []-1..
2 []-2 []-2 []-2 []-2.. 
这次感觉也是对的。 
不，好像重复了。
caonima
0 1234 5678
0 1 5
0 2 6
0 3 7
0 4 8
1 2 7
1 3 8
1 4 6
2 3 4
2 5 8
3 5 6

1 2 7
1 3 8
1 4 6
1 5 0//

2 4 3
2 5 8
2 6 0//
2 7 1//

3 8 1//
3 2 4//
3 5 6
3 7 0//
构造出来是个等差数列递减的。 
剩下的可能会因为前面的产生莫名的关系。
 
 从理论上来说这题 k>2 只有 p 10种取值 
 该不会是打表题？ 也打不出表。
 或者搜索？
 离谱。
 我觉得搜索可以乱搞。
 只要不搜索出重复的不就行了吗？ 
 
有点毒，爆搜甚至会 Wa 只能构造。 
真的难，T1. 

期望的分 30 pts. 
*/
