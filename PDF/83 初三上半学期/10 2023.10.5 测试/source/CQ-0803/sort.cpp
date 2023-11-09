#include<bits/stdc++.h>
using namespace std; 
inline void read(int &x){
	x=0;
	bool f=0;
	char c=getchar();
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
#define ll long long
const int maxn=7e5+5;
int n;
int a[maxn],pos[maxn];
int root[maxn];
struct Tree{
	int lc,rc;
	int sum;
}T[maxn*25];
int tot=0;
inline void build(int &rt,int l,int r){
	rt=++tot;
	if(l==r) return ;
	int mid=(l+r)>>1;
	build(T[rt].lc,l,mid);
	build(T[rt].rc,mid+1,r);
}
inline void up_data(int p,int &q,int l,int r,int val){
	q=++tot;
	T[q].sum=T[p].sum+1;
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(val<=mid) T[q].rc=T[p].rc,up_data(T[p].lc,T[q].lc,l,mid,val);
	else T[q].lc=T[p].lc,up_data(T[p].rc,T[q].rc,mid+1,r,val);
}
inline int query(int p,int q,int l,int r,int k){//第 k 小 
	if(l==r) return l;
	int cnt=T[T[q].lc].sum-T[T[p].lc].sum;
	int mid=(l+r)>>1;
//	cout<<l<<" "<<r<<" "<<cnt<<" "<<k<<" czc\n";
	if(k>cnt) return query(T[p].rc,T[q].rc,mid+1,r,k-cnt);
	return query(T[p].lc,T[q].lc,l,mid,k);
}
ll ans=0;
inline void my_sort(int l,int r){
	if(l>r) return ;
	if(l==r) return ;
	ans=ans+(ll)(r-l+1ll);
	int num=(r-l+1)/2+(r-l+1)%2; 
	int p=query(root[l-1],root[r],1,n,num);
//	cout<<l<<" "<<r<<" "<<p<<" "<<a[p]<<" "<<num<<endl;
//	system("pause");
	my_sort(l,a[p]-1);
	my_sort(a[p]+1,r);
}
int main(){
	freopen("sort.in","r",stdin); 
	freopen("sort.out","w",stdout); 
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]); 
		pos[a[i]]=i;
	}
	build(root[0],1,n);
	for(int i=1;i<=n;i++){
		up_data(root[i-1],root[i],1,n,pos[i]);
	}
	my_sort(1,n);
	printf("%lld",ans);
	return 0;
}
/*
傻鸟出题人，代码写这么抽象，不会用C++吗？
就是这个快排？
这是模拟题？
直接模拟会被卡到 n^2 吧，快速排序。
感觉不难的样子。 
观察一下，发现答案是递归参与排序的区间之和除去单元素的集合。 

3e3 以及随机生成模拟即可。
ai=i是一个正序的排列，模拟还是一个 nlogn
直接模拟有 40/50 pts?
不是很理解。
那些特殊性质真的离谱，感觉像是在送分。
直接想正解吧，现在 16:10
统计 cnt 可以很快，现在的问题是如果不模拟，我不知道下一层的序列。
第一层也许知道，第二层在第一层不做的情况下没法知道。
现在不清楚的是每一曾的pivot
为什么要给 1e5 分一档分。
不很离谱吗？
是卡分块算法吗？
不知道。
该不会这题用个Splay什么整吧。
甚至可以卡满三个缓存器，实现 1 s 1e11
我不知道递归的上一层，我用头算下一层啊？
能不能用什么怪糟糟的玩意优化一波，比如bitset。
好像不是很行，我要维护相对顺序。
考虑我不改变他们的顺序递归。
我相当于递归的每一层是一个区间。
我需要在这么多个数中找到排名最中间的那个数。
该不会可以基于值来做一些事情吧。
用莫队，尼玛莫队，莫队要离线。
把值反过来，我相当于找值域在 l~r 中，位置最靠中间的那位。
显然我用查找第k大吗？
直接写一个主席树？
我今天为什么满脑子主席树？
但是他是对的，哥哥。
我在搞些什么飞机。 
空间给的挺多的，我觉得就是主席树。 
水题一枚，真就主席树，6。
写个暴力对拍吧。 
*/ 
