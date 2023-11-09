/*
B 01序列
好家伙，重题是吧？
AB题你给我出同一个性质，那这不是搞人心态吗？
看看这题啊，首先第一档是暴力2^20*20=2e7
（不对我好像没法O(n)求解） 
注意到题目非常的有趣，尤其是数据范围，正解甚至只有10pts
那么最基础的应该有一个状态压缩的想法，但是很显然这样的时间是2^n，会炸掉
考虑分成两半，这样每一半都是2^20，可以有很大的优化空间
假设现在单边处理完了，我们两边各自会有2^20种情况
简单考虑合并，此时左右两边需要枚举才可以合并，这不优
而且就算枚举，我们也需要推一波式子，这非常的难受
先把式子整出来，没准非常不错就可以直接切了呢？
是这样的，如果式子推出来了就可以直接分治解决，但是问题是我推不出来，这样连鲍丽芬都拿不到
我现在突然看出来，T1和T2是 Data.ver 和 Judge.ver 是吧 
你行，会玩，但我更疑惑的是T1的SPJ怎么写的...
按照T2这个数据范围来看，T1的SPJ根本没法写啊？
发现还是有差别，如果只是Judge，那只需要O(n)计算本质不同串，这是SAM
？SAM...
第一档暴力是SAM！我去...
那如果考场上打出来了，再凑一下T4，就能有200pts了
哎不行，先打再说，时间不够了，想不出正解的
*/
#include<bits/stdc++.h>
using namespace std;
const int N=300;
class SAM
{
private:
	int trans[N][2];
	int len[N],link[N];
	int tot,last;
	int cnt[N],a[N],siz[N];
public:
	inline void init(){memset(trans,0,sizeof trans);tot=0,link[0]=-1,last=0;return;}
	inline void emplace(bool c)
	{
		int cur=++tot;
		siz[cur]=1;
		int p=last;
		last=cur;
		len[cur]=len[p]+1;
		while(p&&!trans[p][c])trans[p][c]=cur,p=link[p];
		if(!p&&!trans[p][c]){trans[0][c]=cur,link[cur]=0;return;}
		int q=trans[p][c];
		if(len[q]==len[p]+1){link[cur]=q;return;}
		int clone=++tot;
		memcpy(trans[clone],trans[q],sizeof trans[q]);
		link[clone]=link[q],len[clone]=len[p]+1;
		trans[p][c]=clone;
		while(p&&trans[p][c]==q)trans[p][c]=clone,p=link[p];
		link[cur]=link[q]=clone;
		return;
	}
	inline int sub()
	{
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=tot;i++)cnt[len[i]]++;
		for(int i=1;i<=tot;i++)cnt[i]+=cnt[i-1];
		for(int i=1;i<=tot;i++)a[i]=cnt[len[i]]--;
		int ans=0;
		for(int i=tot;i;i--)
		{
			siz[link[i]]+=siz[i];
			ans+=siz[i];
		}
		return ans;
	}
}zgy;
int ans[N];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<(1<<n);i++)
	{
		zgy.init();
		for(int j=0;j<n;j++)zgy.emplace((i>>j)&1);
		int sub=zgy.sub();
		ans[sub>k?k+1:sub]++;
	}
	for(int i=1;i<=k;i++)printf("%d ",ans[k]);
	return 0;
}
