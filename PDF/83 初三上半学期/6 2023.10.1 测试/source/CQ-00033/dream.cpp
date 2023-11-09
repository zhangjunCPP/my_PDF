#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; bool f=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
#define int long long
const int p=1e9+7;
const int N=1e5+5;
int n,m,q,k,id;
struct node{ int to,val; };
vector<node> e[N];
namespace sub1{//k=0
	bool check(){ return k==0; }
	priority_queue<pair<int,int> > q;
	int dis[N],cnt[N];
	bool vis[N];
	void dijkstra(int s){
		memset(cnt,0,sizeof cnt),cnt[s]=1;
		memset(dis,0x3f,sizeof dis),dis[s]=0;
		memset(vis,0,sizeof vis);
		q.emplace(make_pair(0,s));
		while(!q.empty()){
			int u=q.top().second; q.pop(),vis[u]=0;
			for(auto i:e[u]){
				int v=i.to,w=i.val;
				if(dis[v]>dis[u]+w){
					cnt[v]=cnt[u];
					dis[v]=dis[u]+w;
					if(!vis[v])	q.emplace(make_pair(-dis[v],v)),vis[v]=1;
				}else if(dis[v]==dis[u]+w) cnt[v]=(cnt[v]+cnt[u])%p;
			}
		}
	}
	void work(){
		while(::q--){
			int s,t; _(s),_(t);
			dijkstra(s);
			printf("%lld\n",cnt[t]);
		}
	}
}
namespace sub2{//Á´
	bool check(){
		for(int i=1;i<=n;i++) if(e[i].size()>2) return 0;
		return 1;
	}
	int dfn[N],tt;
	void dfs(int u,int fa){
		dfn[u]=++tt;
		for(auto i:e[u]) if(i.to!=fa) dfs(i.to,u);
	}
	void work(){
		int ss=0;
		for(int i=1;i<=n;i++) if(e[i].size()==1){ ss=i; break; }
		dfs(ss,0);
		while(q--){
			int s,t; _(s),_(t);
			int ans=0;
			if(dfn[s]<dfn[t]){
				ans=dfn[t]-dfn[s]-1;
				if(dfn[s]!=1) ans++;
			}else{
				ans=dfn[s]-dfn[t]-1;
				if(dfn[s]!=n) ans++;
			}
			printf("%lld\n",ans);
		}
	}
}
//namespace sub3{//Ê÷
//	bool check(){ return m==n-1; }
//	int fa[N],deep[N],son[N],sz[N],top[N],dfn[N],rev[N],tt;
//	void dfs1(int u,int fath){
//		fa[u]=fath,sz[u]=1,deep[u]=deep[fa]+1;
//		for(auto i:e[u]) if(i.to!=fath){
//			dfs1(i.to,u);
//			sz[u]+=sz[v];
//			if(sz[son[u]]<sz[v]) son[u]=v;
//		}
//	}
//	void dfs2(int u,int tp){
//		top[u]=tp,dfn[u]=++tt,rev[tt]=u;
//		if(son[u]) dfs(son[u],tp);
//		for(auto i:e[u]) if(i.to!=fa[u]&&i.to!=son[u]) dfs2(v,v);
//	}
//	#define ls (rt<<1)
//	#define rs (rt<<<1|1)
//	#define mid ((l+r)>>1)
//	int sum[N<<2];
//	void push_up(int rt){ sum[rt]=sum[ls]+sum[rs]; }
//	void build(int rt,int l,int r){
//		if(l==r){
//			sum[rt]=e[rev[l]].size();
//			return ;
//		}
//		build(ls,l,mid),build(rs,mid+1,r);
//		push_up(rt);
//	}
//	int query(int rt,int l,int r,int L,int R){
//		if(L<=l&&r<=R) return sum[rt];
//		int res=0;
//		if(L<=mid) res+=query(ls,l,mid,L,R);
//		if(mid<R) res+=qeury(rs,mid+1,r,L,R);
//		return res;
//	}
//	#undef ls
//	#undef rs
//	#undef mid
//	int QUERY(int u,int v){
//		for(;top[u]!=top[v];u=fa[top[u]]){
//			if()
//		}
//	}
//	void work(){
//		dfs1(1,0);
//		dfs2(1,0);
//		build(1,1,n);
//		while(q--){
//			int s,t; _(s),_(t);
//			
//		}
//	}
//}
signed main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	_(n),_(m),_(q),_(k),_(id);
	for(int i=1;i<=m;i++){
		int u,v,w; _(u),_(v),_(w);
		e[u].emplace_back((node){v,w}),e[v].emplace_back((node){u,w});
	}
	if(sub1::check()) sub1::work();
	else if(sub2::check()) sub2::work();
//	else if(sub3::check()) sub3::work();
	return 0;
}
/*
6 5 4 1 156156
1 2 56
2 3 51
3 4 56
4 5 68
5 6 65
2 5
5 2
4 6
6 4
*/
