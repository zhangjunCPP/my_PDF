/*
我在想
搞个set是不是就结束了？

啊，不是的
set是O(nmlogn)的

n很小，我们可以直接用队列维护
时间O(nm)

所以现在要考虑如何利用1~i-1的答案算出i的

我们不妨尝试一下这个思路
给原数组去重
对于a[i]，如果a[i-k]~a[i-1]之间没有等于它的
就给答案累加1的贡献
利用双指针也可以做到O(nm)

考虑优化这个过程
记录每个数离前面和自己相等的数的最近距离
我们就可以在k变化时均摊O(logm)计算答案 

有问题
如果我前面的某个数没有新开空间
那我其实可以多往前面拓展一步

所以需要维护原数组
一旦某个数对答案没有贡献了
就需要把在它后面的所有权值-1
我感觉可能不容易t 

不知道为什么实现错了啊
很怪，打暴力吧

都说wc是好地方
我也这么觉得啊
3 5
3 1 2 1 3
这组数据，答案应该是
5 4 3
我输出了
5 4 4

究其原因
其实我们“对于a[i]，如果a[i-k]~a[i-1]之间没有等于它的，就给答案累加1的贡献” 
这句话分析错了
因为这其中可能会有重复的数字出现，而它们只会占一个位置
所以我们预处理时记录的应该是两个相等的位置之间有多少个不同的数字 
*/ 
#include<bits/stdc++.h>
using namespace std;
inline int re(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
void wr(int x){
	if(x>9)wr(x/10);
	putchar(x%10|48);
}
const int N=5e5+10;
int i,n,las[N],len,a[N],m;
priority_queue<int,vector<int>,greater<int> >q;
struct B{
	int l,r;
}ask[N];
int blo[N],vis[N],ans;
bool cmp(B x,B y){
	return blo[x.l]==blo[y.l]?blo[x.l]&1?x.r<y.r:x.r>y.r:blo[x.l]<blo[y.l];
}
void add(int x){
	x=a[x];
	if(!vis[x])++ans;
	++vis[x];
}
void del(int x){
	x=a[x];
	--vis[x];
	if(!vis[x])--ans;
}
void prework(){
	for(i=1;i<=n;++i)las[i]=-1e9;
	int num=max((int)sqrt(len),1);
	for(i=1;i<=len;++i){
		if(las[a[i]]==-1e9)q.push((int)1e9),ask[i]={0,0};
		else ask[i]={las[a[i]]+1,i};
		las[a[i]]=i;
		blo[i]=(i+num-1)/num;
	}
	sort(ask+1,ask+1+len,cmp);
	int l=1,r=0;
	for(i=1;i<=len;++i){
		if(ask[i].l==0||ask[i].r==0)continue;
		while(l>ask[i].l)add(--l);
		while(r<ask[i].r)add(++r);
		while(l<ask[i].l)del(l++);
		while(r>ask[i].r)del(r--);
//		printf("ask[i]={%d,%d} ans=%d\n",ask[i].l,ask[i].r,ans);
		q.push(ans);
	}
}
int main(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
	n=re();
	m=re();
	for(i=1;i<=m;++i)a[i]=re();
	len=unique(a+1,a+1+m)-a-1;
//	for(i=1;i<=len;++i)printf("%d ",a[i]);putchar(10);
	prework();
	for(i=1;i<=n;++i){
		while(!q.empty()&&q.top()<=i)q.pop();
		wr(q.size());
		putchar(32);
	}
	return 0;
}

