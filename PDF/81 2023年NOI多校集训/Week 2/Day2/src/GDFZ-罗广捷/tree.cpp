#include<bits/stdc++.h>
using namespace std;
namespace my_std
{
	typedef long long ll;
	const ll inf=0x3f3f3f3f;
	#define fir first
	#define sec second
	#define MP make_pair
	#define fr(i,x,y) for(ll i=(x);i<=(y);++i)
	#define pfr(i,x,y) for(ll i=(x);i>=(y);--i)
	#define space putchar(' ')
	#define enter putchar('\n')
	inline ll read()
	{
		ll sum=0,f=1;char ch=0;
		while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
		while(isdigit(ch)) sum=sum*10+(ch^48),ch=getchar();
		return sum*f;
	}
	inline void write(ll x)
	{
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	inline void writesp(ll x){write(x),space;}
	inline void writeln(ll x){write(x),enter;}
}
using namespace my_std;
const ll N=1e6+50,M=100,mod=1e9+7;
ll n,inv2=(mod+1)/2,head[N],dep[N],deg[N],cnt,len,flag1=1,flag2=1,flag3=1,tot;
struct edge{ll to,nxt;}e[N<<1];
inline void addedge(ll u,ll v){e[++cnt]=(edge){v,head[u]},head[u]=cnt;}
inline ll ksmod(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod,b>>=1;
	}
	return ans;
}
void dfs(ll u,ll fa)
{
	dep[u]=dep[fa]+1;
	if(deg[u]==1&&len!=0&&dep[u]!=len) flag3=0;
	if(deg[u]==1) len=dep[u],++tot;
	for(ll i=head[u];i;i=e[i].nxt)
	{
		ll v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
	}
}
namespace Subtask1
{
	ll a[N],ans[N],dep[N],dis[M][M];
	vector<ll> vec[N];
	inline void dfs(ll u,ll fa)
	{
		vec[u].emplace_back(u),dep[u]=dep[fa]+1;
		for(ll i=head[u];i;i=e[i].nxt)
		{
			ll v=e[i].to;
			if(v==fa) continue;
			dfs(v,u);ll sz1=vec[u].size(),sz2=vec[v].size();
			fr(j,0,sz1-1) fr(k,0,sz2-1) dis[vec[u][j]][vec[v][k]]=dis[vec[v][k]][vec[u][j]]=dep[vec[u][j]]+dep[vec[v][k]]-2*dep[u];
			fr(j,0,sz2-1) vec[u].emplace_back(vec[v][j]);
		}
	}
	inline void solve()
	{
		dfs(1,0);
		fr(i,0,(1<<n)-1)
		{
			fr(j,0,n-1) a[j]=(i>>j)&1;
			ll cur=0;
			fr(j,0,n-1) fr(k,j+1,n-1) if(a[j]==a[k]) cur=max(cur,dis[j+1][k+1]);
			++ans[cur];
		}
		ll res=0;
		fr(i,1,n) res=(res+i*ans[i]%mod)%mod;
		writeln(res);
	}
}
namespace Subtask10
{
	ll f[N],g[N],anss,ans[2],dis[2][N],vis[N],a[N],b[N];
	void dfs1(ll u,ll fa)
	{
		ll maxn[2]={0,0},pos[2]={u,u};f[u]=1,g[u]=u;
		for(ll i=head[u];i;i=e[i].nxt)
		{
			ll v=e[i].to;
			if(v==fa) continue;
			dfs1(v,u); 
			if(f[v]+1>=maxn[0]) maxn[1]=maxn[0],pos[1]=pos[0],maxn[0]=f[v]+1,pos[0]=g[v];
			else if(f[v]+1>maxn[1]) maxn[1]=f[v]+1,pos[1]=g[v];
		}
		if(maxn[1]+maxn[0]-(maxn[1]!=0)>anss) anss=maxn[1]+maxn[0]-(maxn[1]!=0),ans[0]=pos[0],ans[1]=pos[1];
		if(maxn[0]>f[u]) f[u]=maxn[0],g[u]=pos[0];
	}
	void dfs2(ll u,ll fa,ll id)
	{
		dis[id][u]=dis[id][fa]+1;
		for(ll i=head[u];i;i=e[i].nxt)
		{
			ll v=e[i].to;
			if(v==fa) continue;
			dfs2(v,u,id);
		}
	}
	inline void solve()
	{
		dfs1(1,0);
//		printf("ans1=%d ans2=%d anss=%d\n",ans[0],ans[1],anss);
		iota(a+1,a+n+1,1),iota(b+1,b+n+1,1),dis[0][0]=dis[1][0]=-1;
		dfs2(ans[0],0,0),dfs2(ans[1],0,1);
		sort(a+1,a+n+1,[&](ll x,ll y){return dis[0][x]>dis[0][y];});
		sort(b+1,b+n+1,[&](ll x,ll y){return dis[1][x]>dis[1][y];});
		ll pos1=1,pos2=1,res=0,cur=ksmod(2,n),qwq=0;
		while(pos1<=n&&pos2<=n)
		{
//			printf("cur %d %d\n",a[pos1],b[pos2]);
			if(dis[0][a[pos1]]>dis[1][b[pos2]]) 
			{
				if(a[pos1]==ans[1]&&qwq){++pos1;continue;}
				else if(a[pos1]==ans[1]) qwq=1;
				if(vis[a[pos1]]){res=(res+cur*dis[0][a[pos1]]%mod)%mod;break;}
				else
				{
//					printf("1 add %d * %d\n",cur*inv2%mod,dis[0][a[pos1]]);
					vis[a[pos1]]=1,res=(res+cur*inv2%mod*dis[0][a[pos1]]%mod)%mod,cur=cur*inv2%mod;
				}
				++pos1;
			}
			else
			{
				if(b[pos2]==ans[0]&&qwq){++pos2;continue;}
				else if(b[pos2]==ans[0]) qwq=1;
				if(vis[b[pos2]]){res=(res+cur*dis[1][b[pos2]]%mod)%mod;break;}
				else
				{
//					printf("2 add %d * %d\n",cur*inv2%mod,dis[1][b[pos2]]);
					vis[b[pos2]]=1,res=(res+cur*inv2%mod*dis[1][b[pos2]]%mod)%mod,cur=cur*inv2%mod;
				}
				++pos2;
			}
		}
		writeln(res);
	}
}
int main(void)
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	fr(i,1,n-1)
	{
		ll u=read(),v=read();
		addedge(u,v),addedge(v,u),++deg[u],++deg[v];
		if(!((u==i&&v==i+1)||(u==i+1&&v==i))) flag1=0;
		if(u!=1&&v!=1) flag2=0;
	}
	flag3&=(deg[1]>2),dfs(1,0);
	if(flag1) 
	{
		if(n==1) puts("0");
		else if(n==2) puts("2");
		else if(n==3) puts("12");
		else
		{
			ll cur=(n&1)?4:2,ans=0,t=(n-1)/2;
			fr(i,t,n-2) ans=(ans+cur*i%mod)%mod,cur=cur*(i==t?3:4)%mod;
			ans=(ans+(n-1)*ksmod(2,n-1)%mod)%mod;
			writeln(ans);
		}
	}
	else if(flag2)
	{
		if(n==3) puts("12");
		else writeln(2*ksmod(2,n)%mod);
	}
	else if(flag3) writeln((len-1)*2*ksmod(2,n)%mod);
	else if(n<=10) Subtask1::solve();
	else Subtask10::solve();
	return 0;
}
/*
6
1 2
2 3
3 4
4 5
3 6
*/
