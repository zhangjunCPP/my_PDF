#include<bits/stdc++.h>
using namespace std;
namespace my_std
{
	typedef long long ll;
	const int inf=0x3f3f3f3f;
	#define fir first
	#define sec second
	#define MP make_pair
	#define fr(i,x,y) for(int i=(x);i<=(y);++i)
	#define pfr(i,x,y) for(int i=(x);i>=(y);--i)
	#define space putchar(' ')
	#define enter putchar('\n')
	inline int read()
	{
		int sum=0,f=1;char ch=0;
		while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
		while(isdigit(ch)) sum=sum*10+(ch^48),ch=getchar();
		return sum*f;
	}
	inline void write(int x)
	{
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	inline void writesp(int x){write(x),space;}
	inline void writeln(int x){write(x),enter;}
}
using namespace my_std;
const int N=4050;
int n,len,a[N],b[N],head[N],cnt,vis[N],f[N][N],g[N][N],curmax,ans=inf,cur;
struct edge{int to,nxt;}e[N<<1];
inline void addedge(int u,int v){e[++cnt]=(edge){v,head[u]},head[u]=cnt;}
void dfs(int u,int fa)
{
	if(u==cur) return ;
	vis[u]=f[u][a[u]]=g[u][a[u]]=1;
	int m1=0,m2=0,m3=0,m4=0,pos1=0,pos2=0,pos3=0,pos4=0;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa||v==cur) continue;
		dfs(v,u),f[u][a[u]]=max(f[u][a[u]],f[v][a[u]-1]+1),g[u][a[u]]=max(g[u][a[u]],f[v][a[u]+1]+1);
		if(f[v][a[u]-1]+1>=m1) m2=m1,pos2=pos1,pos1=v,m1=f[v][a[u]-1]+1;
		else if(f[v][a[u]-1]+1>m2) m2=f[v][a[u]-1]+1,pos2=v;
		if(g[v][a[u]+1]+1>=m3) m4=m3,pos4=pos3,pos3=v,m3=g[v][a[u]+1]+1;
		else if(g[v][a[u]+1]+1>m4) m4=g[v][a[u]+1]+1,pos4=v;
	}
	fr(i,a[u]+1,len) f[u][i]=max(f[u][i],f[u][i-1]);
	pfr(i,a[u]-1,0) g[u][i]=max(g[u][i],g[u][i+1]);
	int qwq=max(1,max(m1,m3));
	if(pos1!=pos3) qwq=max(m1+m3-1,qwq);
	if(pos1!=pos4) qwq=max(m1+m4-1,qwq);
	if(pos2!=pos3) qwq=max(m2+m3-1,qwq);
	if(pos2!=pos4) qwq=max(m2+m4-1,qwq);
	curmax=max(curmax,qwq); 
}
int main(void)
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	n=read();int u,v;
	fr(i,2,n) u=read(),v=read(),addedge(u,v),addedge(v,u);
	fr(i,1,n) b[i]=a[i]=read();
	sort(b+1,b+n+1),len=unique(b+1,b+n+1)-b-1;
	fr(i,1,n) a[i]=lower_bound(b+1,b+len+1,a[i])-b;
	fr(i,2,2)
	{
		cur=i,curmax=0,memset(vis,0,sizeof(int)*(n+1));
		fr(x,1,n) fr(y,0,len+1) f[x][y]=g[x][y]=-inf;
		fr(j,1,n) if(!vis[j]) dfs(j,0);
		ans=min(ans,curmax);
	}
	return writeln(ans),0;
}
/*
12
1 2
1 3
1 4
3 5
3 6
4 7
4 8
5 9
9 10
9 11
10 12
1 5 8 3 4 2 9 7 7 3 1 4
*/
