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
const int maxn=1e3+5;
struct node{
	int l,r,c;
}a[maxn];
int n;
#define ll long long
ll dp[maxn][maxn];
inline ll calc(int l1,int r1,int l2,int r2){
	ll ans1=0,ans2=0;
	for(int i=l1;i<=r1;i++) ans1+=(ll)a[i].c*(ll)max((ll)min(r2,a[i].r)-max(l2,a[i].l)+1ll,0ll); 
	for(int i=l2;i<=r2;i++) ans2+=(ll)a[i].c*(ll)max((ll)min(a[i].r,r1)-max(a[i].l,l1)+1ll,0ll);
	return max(ans1,ans2);
}
ll q[maxn][maxn]; 
ll now[maxn];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout); 
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i].l),read(a[i].r),read(a[i].c);
	}
	for(int i=1;i<=n;i++){
		for(int j=a[i].l;j<=a[i].r;j++) now[j]+=(ll)a[i].c;
		for(int j=1;j<=n;j++) q[i][j]=q[i][j-1]+now[j];
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			for(int k=i;k<j;k++){
				ll sum1=(q[j][k]-q[j][i-1])-(q[k][k]-q[k][i-1]);
				ll sum2=(q[k][j]-q[k][k])-(q[i-1][j]-q[i-1][k]);
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+max(sum1,sum2));
			}
		}
	}
	printf("%lld",dp[1][n]);
	return 0;
}
/*
感觉是一个贪心问题。
跟区间有关。
先将区间按左端点从左到右排序，再扫描？
n<=1e3?
迷惑，正解冲一冲吧。
将问题转换一下。
考虑所有魔法都能收集。
但是不同的顺序会少收集多少魔法？
假设操作是反过来的。
最开始所有球都不能收集。
后来越来越多的球可以收集。
贪心没法做，该不会是区间dp吧？
设 dp l,r 表示 l,r 这些球被变为稳定后，收集了的最大价值。
只看这内部的，因为收集顺序是相对的。
dp l,r = dp l k + dp k r +max(calc r->l,l->r )
是对的吗？
石子合并不也是这样做的吗？
对的。 
直接暴力：
n^4
有点黑人。
但是求值的部分感觉可以处理一下。
怎么也是 n^3
该不会还可以用什么数据结构优化。
还是有单调性？
其实优化到 n^3 已经很牛逼了，至少过 9 个点，谁还要这 10pts 呐。
还不一定跑满，那不随便过。
处理贡献部分像一个2维偏序问题。
实在不行，我用主席树乱搞。。。（错误的）
不一定要对于每个点分开算贡献，可以对于一个区间整体算贡献。
用一个前缀和预处理一下，a[i][l][r] 表示以 i 为末端，对于区间 l,r 的贡献。
这空间不都G了？
我开个 n^2 的总行吧。
区间修改，单点查询。
有 n 个版本就很烦。
主席树！
用差分将区间修改转换成单点修改。
离谱，先写一下暴力吧。。。 
n^3 log n 刚好可以跑过 100 的点。
90pts。 
其实我感觉这个不是n^3
因为我访问到的东西，相当于区间和。
想错了，不管了，常数小，1000的数据大不了不过了。 
dp 正确性是对的。
现在写的 n^4 ，我该不会直接真的上主席树吧。
想一下，有没有线性的 n^3。 
CDQ 优化 2 维 dp?
6 太 6了。
没必要主席树，再转移过程中用两颗树状数组也能维护。
现在最小丑的一点是我是 n^3 log n。
想 A 题，但是 test 10 是 1000。
暴力肯定跑不过去。
dp 枚举都是一个 n^3 的，滑稽。
算了 90 pts 也不错。 
好像树状数组直接优化不了。
没关系，待修树状数组，反正 n 才 1e3。
我直接 memcpy 实现可持久化都可以。 
好像是区间修改区间查询，尼玛还要写线段树。
没关系，反正复杂度不爆炸，我直接暴力单点修改就好了。
逐渐专家化。 
我为什么不能写前缀和？
草，降智了。 
cnm 写错了。 
好了调过了。 
*/
