#include<bits/stdc++.h>
#define int long long
const int mod=1e9+7;
const int QWQ=2e5+5;
using namespace std;
inline int read(){
	char ch=getchar(); int x=0,f=1;
	while (ch<'0'||ch>'9'){ if (ch=='-') f=-1; ch=getchar(); }
	while ('0'<=ch&&ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
struct node{ int to,next; } E[QWQ<<1];
int n,cnt,head[QWQ],dep[QWQ];
namespace LCA{
	int son[QWQ],siz[QWQ];
	int top[QWQ],father[QWQ];
	void init(int u,int fa){
		siz[u]=1;
		father[u]=fa;
		dep[u]=dep[fa]+1;
		for (int i=head[u];i;i=E[i].next){
			int v=E[i].to;
			if (v==fa) continue;
			init(v,u);
			siz[u]+=siz[v];
			if (siz[son[u]]<siz[v])
				son[u]=v;
		} 
	}
	void dfs(int u,int fa){
		top[u]=fa;
		if (!son[u]) return ;
		dfs(son[u],fa);
		for (int i=head[u];i;i=E[i].next){
			int v=E[i].to;
			if (v!=father[u]&&v!=son[u])
				dfs(v,v);
		}
	}
	inline int lca(int x,int y){
		while (top[x]!=top[y]){
			if (dep[top[x]]<dep[top[y]])
				swap(x,y);
			x=father[top[x]];
		} if (dep[x]>dep[y])
			swap(x,y);
		return x;
	}
	inline int get_len(int x,int y){
		return dep[x]+dep[y]-(dep[lca(x,y)]<<1);
	}
}
inline void append(int x,int y){
	E[++cnt].to=y;
	E[cnt].next=head[x];
	head[x]=cnt;
}
int kkk(int a,int b){
	int res=1;
	for (;b;b>>=1,a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}
int v[15],c[15],res,p[15];
void dfs(int k){
	if (k>n){
		int p1=0,p2=0;
		for (int i=1;i<=n;i++)
		if (!c[i])
		for (int j=i;j<=n;j++)
		if (!c[j]) p1=max(p1,LCA::get_len(i,j));
		for (int i=1;i<=n;i++)
		if (c[i])
		for (int j=i;j<=n;j++)
		if (c[j]) p2=max(p2,LCA::get_len(i,j));
		p[max(p1,p2)]++;
		res=(res+max(p1,p2))%mod;
		return ;
	} c[k]=0;
	dfs(k+1);
	c[k]=1;
	dfs(k+1);
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read(); int li=0,fl=1;
	for (int i=1,x,y;i<n;i++){
		x=read(),y=read();
		append(x,y),append(y,x);
		if (x==1||y==1) li++;
		if (x!=i||y!=i+1) fl=0;
	} LCA::init(1,0); 
	LCA::dfs(1,1);
	if (n<=10){ dfs(1); printf("%lld",res); return 0; }
	if (li==n-1){ printf("%lld\n",kkk(2,n)%mod*2%mod); return 0; }
	if (fl){
		int ic=n,out,lt;
		res=kkk(2,(n-1))%mod,out=res*(--ic),lt=n-4;
		out=(out+3*kkk(2,lt+1)%mod*(--ic)%mod)%mod;
		while (lt>=2){
			lt-=2;
			out=(out+3*kkk(2,lt+1)%mod*(--ic)%mod)%mod;
		} if (lt==1) out=(out+(--ic)*4%mod)%mod;
		if (lt==0) out=(out+(--ic)*2%mod)%mod;
		printf("%lld",out);
		return 0;
	}  
	return 0;
}
/*
9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
*/
