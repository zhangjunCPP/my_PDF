#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;
	char c=getchar();
	bool f=0;
	while(c<'0' || c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar(); 
	}
	if(f) x=-x;
}
const int maxn=1e5+5;
int a[maxn],n,m,tim[maxn];
queue< pair<int,int> > q;
int main(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout); 
	read(n),read(m);	
	for(int i=1;i<=m;i++){
		read(a[i]);
	}
	for(int k=1;k<=n;k++){
		int ans=0;
		for(int i=1;i<=n;i++) tim[i]=0;
		while(!q.empty()) q.pop();
		int siz=0;
		for(int i=1;i<=m;i++){
			if(!tim[a[i]]){
				if(siz==k){
					int x,y;
					while(!q.empty()){
						x=q.front().first;
						y=q.front().second;
						q.pop();
						if(tim[x]==y) break;
					}
					siz--;
					tim[x]=0;
				}
				q.push(make_pair(a[i],i));
				tim[a[i]]=i;
				ans++;
				siz++;
			}
			else{
				q.push(make_pair(a[i],i));
				tim[a[i]]=i;
			}
		}
		printf("%d",ans);
		if(k!=n) putchar(' ');
	}
	return 0;
}
/*
如果只有一种 k 就是模拟题。
可以模拟，用 set
最优性证明：
一个元素删了，后面还会加所以尽量不删
考虑填满了的时候，删最先访问过的那个应该更优
因为后面肯定会有个其他比他后出现的再加入。
如果删了，就会浪费一次加入，大概是这样的   。
显然不大可能做 k 次。
先做第一次。 
考虑能不能递推答案。
会出现影响的位置时，刚好满 k,从k上来说须要删一个，k+1上来说不需要。 
知道下一次满载，如果那个元素就是第一次满载的元素，不管他。
否则肯定需要再删一个元素。
但是我们这样讨论 k 时删除的那个元素会有影响吧。
都是些啥?
离谱
感觉像我这样讨论没问题。
但是复杂度很明显不大对，我也不是很理解这种操作。
感觉不是正解。
要不考虑答案的实际意义。
4 6
2 1 2 2 1 4
5 3 3 3

第一次是颜色段的个数。 
最后一次就是颜色出现的个数。
第二次相当于适当的将颜色段合并少一些。
|          ||       || || || || ||   |
最后一次相当于有 n 段，每段元素为 1 种颜色
相当于第一段出现的颜色个数+段数-1
第一次段中颜色个数为 1
每次段中颜色个数不超过 k
相邻两端之间只会有一种颜色只差
不是很会算，感觉如果能直接这样做的复杂度是：
\sum_i=1 ^ n n/i
不对感觉不能这样搞
就是感觉有问题，这样搞如果每次只有第一段能合并，那么复杂度不久很大吗？
1 2 3 4 5 .... n 这样构造就可以。
感觉合并这样做也不是很行。
感觉就是没法推答案换个思路。
我统计答案<=k的个数。
我可以二分出一个数表示有这么多个位置是可以满足。
那么复杂度是 m log n n log n
看着有点大啊。
模拟过程可以用双端队列优化吧。
个屁。
没有个 log 级别的数据结构不能做。
答案的种类数大不大啊，毛估估一下，感觉不大。
能不能卡到 n ，也感觉不行。
但是人不要相信自己的感觉。
真的离谱。
刚才想到个啥？
感觉贪心的统计每个元素插入的次数。
我优先让大的把位置占了。
也不是，因为删除的按照他那么sb的做法来。
考虑一个事情，第一次不用插入的元素，第二次会不会去插入。
感觉不会，事实上也不太会吧。
想到了一种线性扫描的做法。
对于每个元素维护最后出现的时间，然后把元素扔队列模拟。
真的不是很好做。
感觉T3也不是很好做，还是做T2。
看着这递减的答案这明显感觉就是维护那些位置不用再插了。
把他们删了就行了。
对于一个元素你怎么知道他还插不插。
如果只维护插入序列，你就不知道删除序列。
所以就不能确定元素集合。
如果对于每个插的我维护对应的删的。
就可以线性的去做。
可以线性的模拟，那复杂度就是答案数。
现在的问题是快速维护转移。
我对于一个序列，我二分出他的。。。。
二分木琴哪。
很显然，。。。。。
没思路。
正着不好做，倒着吧。
首先我肯定不能求太多次答案。
这样很有问题。
如果要求n次必须快速求。
递推考虑了很久也不是很行。
考虑能不能把答案用什么数据结构维护一波。
线段树。
表示把这树上段区间的点全。。。。
不可以做。
你总不可能给我说我可以矩阵乘法吧！
首先这个东西我不能用转移来表示是一个很严重的问题。
这个说明我不大可能加速计算贡献。
他的那个删除机制太恶心了，确定了唯一的序列。
先打一下暴力吧。 
真就想不出正解。
今天有点脑抽。
已经优化到了线性了。
 
*/ 
