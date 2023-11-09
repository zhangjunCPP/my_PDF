#include<bits/stdc++.h>
using namespace std;
namespace io{
	template<typename T> void read(T &x){
		x=0; bool f=0; char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()){
			if(ch=='-'){
				f=1;
			}
		}
		for(;ch>='0'&&ch<='9';ch=getchar()){
			x=(x<<1)+(x<<3)+(ch^48);
		}
		if(f){
			x=-x;
		}
	}
	template<typename T> void write(T x){
		if(x<0){
			x=-x,putchar('-');
		}
		if(x>9){
			write(x/10);
		}
		putchar(x%10+'0');
	}
}
using ll=long long;
const int N=1e6+5;
const ll p=1e9+7;
int h[N],cnt;
struct edge{
	int to,nex;
}e[N*2];
void add(int u,int v){
	e[++cnt]=(edge){v,h[u]},h[u]=cnt;
}
void add_edge(int u,int v){
	add(u,v),add(v,u);
}
int deep[N],top[N],fa[N],dfn[N],in[N],son[N],sz[N],tt;
void dfs1(int u,int fath){
	deep[u]=deep[fath]+1,fa[u]=fath,sz[u]=1;
	for(int i=h[u];i;i=e[i].nex){
		int v=e[i].to;
		if(v!=fath){
			dfs1(v,u);
			sz[u]+=sz[v];
			if(sz[son[u]]<sz[v]){
				son[u]=v;
			}
		}
	}
}
void dfs2(int u,int tp){
	top[u]=tp,dfn[u]=++tt,in[tt]=u;
	if(son[u]){
		dfs2(son[u],tp);
	}
	for(int i=h[u];i;i=e[i].nex){
		int v=e[i].to;
		if(v!=fa[u]&&v!=son[u]){
			dfs2(v,v);
		}
	}
}
int LCA(int u,int v){
	for(;top[u]!=top[v];u=fa[top[u]]){
		if(deep[top[u]]<deep[top[v]]){
			swap(u,v);
		}
	}
	return deep[u]<deep[v]?u:v;
}
int dist(int u,int v){
	return deep[u]+deep[v]-deep[LCA(u,v)]*2;
}
int n;
namespace n_10{
	int col[N],ans;
	int calc(){
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(col[i]==col[j]){
					res=max(res,dist(i,j));
				}
			}
		}
		return res;
	}
	void dfs(int step){
		if(step==n+1){
			ans=(ans+calc())%p;
//			for(int i=1;i<=n;i++){
//				printf("%d ",col[i]);
//			}
//			printf("\n");
			return ;
		}
		col[step]=1;
		dfs(step+1);
		col[step]=0;
		dfs(step+1);
	}
}
ll ksm(ll a,ll b){
	ll res=1;
	for(;b;a=a*a%p,b>>=1){
		if(b&1){
			res=res*a%p;
		}
	}
	return res;
}
namespace A{
	ll ans=0;
	void work(){
		if(n==2){
			ans=2;
			return ;
		}
		if(n==3){
			ans=12;
			return ;
		}
		if(n==4){
			ans=38;
			return ;
		} 
		ans=(ans+ksm(2,n-2)*(n-1)%p)%p;
		printf("%lld\n",ksm(2,n-2)*(n-1)%p);
//		ans=(ans+ksm(2,n-3)*(n-2)*2%p)%p;
		printf("%lld\n",ksm(2,n-3)*(n-2)*2%p);
		for(int i=(n-1)/2;i<=n-2;i++){//i:×îÔ¶¾àÀë 
			ans=(ans+i%p)%p;
		}
		ans=(ans+ans)%p;
	}
}
namespace B{
	ll ans=0;
	void work(){
		ans=(n-1)*(n-2)%p*ksm(2,n-2)*2%p;
	}
}
int de[N];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	bool flagA=1;
	io::read(n);
	for(int i=1;i<n;i++){
		int u,v;
		io::read(u),io::read(v);
		add_edge(u,v);
		if(u!=i||v!=i+1){
			flagA=0;
		}
		de[u]++,de[v]++;
	}
	dfs1(1,0);
	dfs2(1,1);
	if(n<=10){
		n_10::dfs(1);
		io::write(n_10::ans);
	}else if(de[1]==n-1){
		B::work();
		printf("%lld",B::ans);
	}else if(flagA){
		A::work();
		printf("%lld",A::ans);
	}else{
		n_10::dfs(1);
		io::write(n_10::ans);
	}
	
	return 0;
}
