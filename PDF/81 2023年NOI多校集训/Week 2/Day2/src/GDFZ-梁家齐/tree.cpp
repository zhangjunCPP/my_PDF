#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10,Mod=1e9+7;
int n,id,mx,ans,to[N<<1],ne[N<<1],head[N],deg[N],a[N],dep[N];
void add(int x,int y) {to[++id]=y,ne[id]=head[x],head[x]=id;}
int chkA()
{
	if(deg[1]!=1||deg[n]!=1) return 0;
	for(int i=2;i<n;i++)
		if(deg[i]!=2) return 0;
	return 1;
}
void dfs1(int u,int fa,int rt,int dep)
{
	if(a[u]==a[rt]) mx=max(mx,dep);
	for(int i=head[u];i;i=ne[i])
	{
		int v=to[i];if(v==fa) continue;
		dfs1(v,u,rt,dep+1);
	}
}
void dfs2(int u,int fa)
{
	dep[u]=dep[fa]+1;
	for(int i=head[u];i;i=ne[i])
	{
		int v=to[i];if(v==fa) continue;
		dfs2(v,u);
	}
}
int power(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%Mod;
		b>>=1,a=a*a%Mod;
	}
	return ans;
}
void solve1()
{
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=1;j<=n;j++) a[j]=(i&(1<<j-1))?1:0;
		mx=0;for(int j=1;j<=n;j++) dfs1(j,0,j,0);ans=(ans+mx)%Mod;
	}
}
void solveA()
{
	for(int i=(n-1>>1);i<n;i++)
	{
		if(i==n-1) ans=(ans+power(2,n-1)*i%Mod)%Mod;
		else if(i==(n-1>>1)) ans=(ans+(i<<1))%Mod;
		else ans=(ans+6*power(4,i-(n+1>>1))%Mod*i%Mod)%Mod;
	}
}
void solveB()
{
	if(n==2) ans=2;
	else if(n==3) ans=12;
	else ans=power(2,n+1);
}
void solveC()
{
	dfs2(1,0);int md=0;
	for(int i=1;i<=n;i++) md=max(md,dep[i]);ans=(md-1)*power(2,n+1)%Mod;
}
signed main()
{
	freopen("tree.in","r",stdin),freopen("tree.out","w",stdout);
	scanf("%lld",&n);for(int i=1,x,y;i<n;i++) scanf("%lld%lld",&x,&y),add(x,y),add(y,x),deg[x]++,deg[y]++;
	if(n<=10) solve1();
	else if(chkA()) solveA();
	else if(deg[1]==n-1) solveB();
	else solveC();
	printf("%lld ",ans);
}
