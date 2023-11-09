#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int N=110;
int T,n,m,ans,k,dif[N],sam[N],f[N][15],head[N],to[N<<1],nxt[N<<1],id[N<<1],tot,mp[N][N],cnt,dfn[N],x[N],xc,C[N],ccnt,col[N],sum[N];
bool b[N],intr[N<<1];
void add(int x,int y,int i)	
{
	nxt[++tot]=head[x];
	to[tot]=y;
	id[tot]=i;
	head[x]=tot;
}
void pre(int u,int fa)
{
	dfn[u]=++cnt;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa)continue;
		if(dfn[v]>dfn[u])
			b[u]=1;
		else
			if(!dfn[v])
			{
				intr[i]=1;
				pre(v,u);
			}
	}
	if(b[u])
		x[++xc]=u;
}
void dfs2(int u,int fa)
{
	for(int i=head[u];i;i=nxt[i])
		if(intr[i])
			dfs2(to[i],u);
	for(int i=0;i<=ccnt;i++)
		f[u][i]=!b[u]||i==col[u];
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i],s=sam[id[i]],d=dif[id[i]];
		if(v==fa)continue;
		if(!intr[i])
		{
			if(dfn[u]>dfn[v])
				for(int j=0;j<=ccnt;j++)
					f[u][j]=1ll*f[u][j]*((j==col[v])?s:d)%MOD;
		}
		else
		{
			for(int j=0;j<=ccnt;j++)
				f[u][j]=1ll*f[u][j]*((1ll*((sum[v]-f[v][j]+MOD)%MOD)*d%MOD+1ll*f[v][j]*s%MOD)%MOD)%MOD;
		}
	}
	sum[u]=1ll*(k-ccnt)*f[u][0]%MOD;
	for(int i=1;i<=ccnt;i++)
		sum[u]=(sum[u]+f[u][i])%MOD;
}
void dfs1(int xx)
{
	if(xx==xc+1)
	{
		dfs2(1,0);
		
		ans=(ans+1ll*sum[1]*C[ccnt]%MOD)%MOD;
		return ;
	}
	for(int i=1;i<=ccnt&&i<=k;i++)
	{
		col[x[xx]]=i;
		dfs1(xx+1);
		col[x[xx]]=0;
	}
	if(ccnt<k)
	{
		ccnt++;
		col[x[xx]]=ccnt;
		dfs1(xx+1);
		col[x[xx]]=0;
		ccnt--;
	}
}
int main()
{
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		memset(mp,0,sizeof(mp));
		memset(intr,0,sizeof(intr));
		ccnt=cnt=tot=xc=0;
		scanf("%d%d%d",&n,&m,&k);
		C[0]=1;
		for(int i=0;i<n;i++)
			C[i+1]=1ll*C[i]*(k-i)%MOD;
		for(int i=1;i<=n;i++)
		{
			dfn[i]=0;b[i]=0;head[i]=0;col[i]=0;
		}
			
		for(int i=1;i<=m;i++)
		{
			int x,y,a,b;
			scanf("%d%d%d%d",&x,&y,&a,&b);
			if(!mp[x][y])
			{
				add(x,y,i);add(y,x,i);
				dif[i]=a;sam[i]=b;
				mp[x][y]=mp[y][x]=i;
			}
			else
			{
				dif[mp[x][y]]=1ll*dif[mp[x][y]]*a%MOD;
				sam[mp[x][y]]=1ll*sam[mp[x][y]]*b%MOD;
			}
		}
		pre(1,0);
		dfs1(1);	
		printf("%d\n",ans);
	}
	return 0;
}
