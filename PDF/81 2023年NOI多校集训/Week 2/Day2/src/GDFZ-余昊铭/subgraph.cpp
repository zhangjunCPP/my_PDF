#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
const int maxn=1000010;
const int inf=1e18;
inline int read(){
	int x=0,fl=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fl=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*fl;
}
int n,m,a,b,c;
int head[maxn],tot;
struct nd{
	int nxt,to;
}e[maxn<<1];
void add(int u,int v){
	e[++tot]={head[u],v};
	head[u]=tot;
}
int dep[maxn],d[maxn];
void dfs(int u,int fa){
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v!=fa){
			dep[v]=dep[u]+1;
			dfs(v,u);
		}
	}
}
int mx=-inf,mxk,lst;
struct poi{
	int id,num;
}p[maxn];
bool cmp(poi u,poi v){return u.num>v.num;}
int f[maxn],siz[maxn],t[maxn],g[maxn];
int st[maxn],tp;
bool vis[maxn];
int fd(int x){
	if(x==f[x])return x;
	return f[x]=fd(f[x]);
}

signed main(){
//	freopen("ex_data2.in","r",stdin);
	freopen("subgraph.in","r",stdin);
	freopen("subgraph.out","w",stdout);

	n=read();m=read();
	a=read();b=read();c=read();
	for(int i=1;i<=m;i++){
		int u,v;
		u=read();v=read();
		add(u,v);add(v,u);
		d[u]++;d[v]++;
	}
	for(int i=1;i<=n;i++)p[i].num=d[i],p[i].id=i;
	sort(p+1,p+n+1,cmp);lst=0;
	for(int i=1;i<=n;i++)f[i]=i,siz[i]=1;
	for(int k=p[1].num;k>=1;k--){
		for(int j=lst+1;j<=n;j++){
			if(p[j].num==k){
				lst=j;
				int u=p[j].id;
				for(int i=head[u];i;i=e[i].nxt){
					int v=e[i].to;
					if(vis[v]){
						if(!vis[u]){
							siz[fd(v)]++;
							t[fd(v)]++;
							g[fd(v)]--;g[fd(v)]+=g[fd(u)];
							f[u]=fd(v);
							vis[u]=1;
						}
						else{
							if(fd(u)==fd(v)){
								t[fd(u)]++;
								g[fd(u)]--;
							}
							else{
								siz[fd(u)]+=siz[fd(v)];
								t[fd(u)]+=t[fd(v)];
								g[fd(u)]--;g[fd(u)]+=g[fd(v)];
								f[fd(v)]=fd(u);
							}
						}
					}
					else g[fd(u)]++;
				}
				if(!vis[u]){
					vis[u]=1;
					st[++tp]=u;
				}
			}
			else break;
		}
		for(int i=1;i<=tp;i++){
			if(f[st[i]]==st[i]){
				if(mx<a*t[st[i]]-b*siz[st[i]]+c*g[st[i]]){
					mx=a*t[st[i]]-b*siz[st[i]]+c*g[st[i]];
					mxk=k;
				}
			}
		}
		if(lst==n)break;
	}
	printf("%lld %lld\n",mxk,mx);
}
