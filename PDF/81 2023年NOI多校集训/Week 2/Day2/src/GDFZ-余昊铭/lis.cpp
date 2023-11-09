#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
const int maxn=4010;
const int inf=1e18;
inline int read(){
	int x=0,fl=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fl=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*fl;
}
int n,ans,res=inf;
int head[maxn],tot;
struct nd{
	int nxt,to;
}e[maxn<<1];
void add(int u,int v){
	e[++tot]={head[u],v};
	head[u]=tot;
}
int a[maxn],f[maxn];
int st[maxn],tp;
void dfs(int u,int fa){
	st[++tp]=a[u];
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v!=fa)dfs(v,u);
	}
	if(!e[head[u]].nxt){
		for(int i=1;i<=tp;i++){
			f[i]=1;
			for(int j=1;j<i;j++)if(a[j]<a[i])f[i]=max(f[i],f[j]+1);
			ans=max(ans,f[i]);
		}
	}
	tp--;
}
void dfs1(int u,int fa){
	st[++tp]=a[u];
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v!=fa)dfs1(v,u);
	}
	if(!e[head[u]].nxt){
		for(int i=1;i<=tp;i++){
			f[i]=1;
			for(int j=1;j<i;j++)if(a[j]>a[i])f[i]=max(f[i],f[j-1]+1);
			ans=max(ans,f[i]);
		}
	}
	tp--;
}

signed main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);

	n=read();
	for(int i=1;i<n;i++){
		int u,v;
		u=read();v=read();
		add(u,v);add(v,u);
	}
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		ans=0;
		a[i]=inf;dfs(i,i);
		a[i]=-inf;dfs1(i,i);
		res=min(res,ans);
	}
	printf("%lld\n",res);
}
/*
5
1 2
2 3
3 4
4 5
1 2 3 4 5
*/
