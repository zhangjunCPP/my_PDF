#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10,INF=0x3f3f3f3f3f3f3f3f;
int n,m,p,q,r,id,len,ans,mk,to[N],ne[N],head[N],deg[N],b[N],c[N],vis[N];
void add(int x,int y) {to[++id]=y,ne[id]=head[x],head[x]=id;}
void dfs(int u,int stat)
{
	for(int i=head[u];i;i=ne[i])
	{
		int v=to[i];
		if((stat&(1<<v-1))&&!vis[v]) vis[v]=1,dfs(v,stat);
	}
}
signed main()
{
	freopen("subgraph.in","r",stdin),freopen("subgraph.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&n,&m,&p,&q,&r);for(int i=1,x,y;i<=m;i++) scanf("%lld%lld",&x,&y),add(x,y),add(y,x);
	for(int i=(1<<n)-1;i;i--)
	{
		int fg=1,s=0,cnt1=0,cnt2=0,cnt3=0;
		for(int j=1;j<=n;j++) deg[j]=vis[j]=0;
		for(int j=1;j<=n;j++)
			if(i&(1<<j-1))
				for(int k=head[j];k;k=ne[k])
					if(i&(1<<to[k]-1)) deg[j]++,cnt1++;
		for(int j=1;j<=n;j++)
			if(i&(1<<j-1)) {s=j;break;}
		vis[s]=1,dfs(s,i);int mn=INF;
		for(int j=1;j<=n;j++)
			if((i&(1<<j-1))&&!vis[j]) fg=0;
		if(!fg) continue;
		for(int j=1;j<=n;j++)
			if(i&(1<<j-1)) cnt2++,mn=min(mn,deg[j]);
		for(int j=1;j<=len;j++)
			if((b[j]&i)==i&&c[j]>=mn) fg=0;
		if(!fg) continue;
		for(int j=1;j<=n;j++)
			if(i&(1<<j-1))
				for(int k=head[j];k;k=ne[k])
					if(!(i&(1<<to[k]-1))) cnt3++;
		int val=(p*cnt1>>1)-q*cnt2+r*cnt3;
		if(ans<val) ans=val,mk=mn;
		else if(ans==val&&mn>mk) mk=mn;
		b[++len]=i,c[len]=mn;
	}
	printf("%lld %lld",mk,ans);
}
/*
3 3
1 1 2
1 2
2 3
3 1
*/
