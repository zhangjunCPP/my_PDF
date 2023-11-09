#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define R register
#define LL long long
const int inf=0x3f3f3f3f;
const int MAXN=1e5+10;

inline int read() {
	char a=getchar(); int x=0,f=1;
	for(;a>'9'||a<'0';a=getchar()) if(a=='-') f=-1;
	for(;a>='0'&&a<='9';a=getchar()) x=x*10+a-'0';
	return x*f;
}

namespace Data {
	int tot=0;
	int sum[MAXN*50],ls[MAXN*50],rs[MAXN*50];
	class SegTree {
		private:
			int rt;
		public:
			SegTree() { rt=0; }
			inline void add(int &x,int l,int r,int ad,int k) {
				if(!x) 	x=++tot;
				sum[x]+=k;	
				if(l==r) return;
				int mid=l+r;mid>>=1;
				if(ad<=mid) add(ls[x],l,mid,ad,k);
				else add(rs[x],mid+1,r,ad,k);
			}
			inline int ask(int &x,int l,int r,int Le,int Ri) {
				if(!x) return 0;
				if(l>=Le&&r<=Ri) return sum[x];
				int mid=l+r;mid>>=1;
				int res=0;
				if(Le<=mid)  res+=ask(ls[x],l,mid,Le,Ri);
				if(Ri>mid) res+=ask(rs[x],mid+1,r,Le,Ri);
				return res;
			}
			inline void Add(int n,int pos,int k) { add(rt,0,n,pos,k); }
			inline int Ask(int n,int l,int r) { return ask(rt,0,n,l,r); }
	};
}
using Data::SegTree;

int n,m;
int val[MAXN];
struct edge { int to,next; } e[MAXN<<1];
int cnt,head[MAXN];
inline void add(int x,int y) { e[++cnt]={ y,head[x] }; head[x]=cnt; }

namespace Graph {
	int dep[MAXN],fa[MAXN],top[MAXN],siz[MAXN],son[MAXN];
	inline void dfs1(int x,int fx) {
		fa[x]=fx; dep[x]=dep[fx]+1; siz[x]=1;
		for(R int i=head[x];i;i=e[i].next) {
			int y=e[i].to; if(y==fx) continue;
			dfs1(y,x); siz[x]+=siz[y];
			if(siz[y]>siz[son[x]]) son[x]=y;
		}
	}
	inline void dfs2(int x,int topx) {
		top[x]=topx;
		if(son[x]) dfs2(son[x],topx);
		for(R int i=head[x];i;i=e[i].next) {
			int y=e[i].to; if(y==fa[x]||y==son[x]) continue;
			dfs2(y,y);
		}
	}
	inline int LCA(int x,int y) {
		while(top[x]!=top[y]) 
			if(dep[top[x]]>dep[top[y]]) x=fa[top[x]];
			else y=fa[top[y]];
		return dep[x]<dep[y]?x:y;
	}
	inline int dis(int x,int y) {
		return dep[x]+dep[y]-dep[LCA(x,y)]*2;
	}
	inline void build() {
		dfs1(1,0); dfs2(1,1);
	}
}

namespace Tree {
	int rt,total;
	int mx[MAXN],fa[MAXN],siz[MAXN],vis[MAXN];
	SegTree sm1[MAXN],sm2[MAXN];
	inline void getrt(int x,int fx) {
		siz[x]=1; mx[x]=0;
		for(R int i=head[x];i;i=e[i].next) {
			int y=e[i].to;
			if(y==fx||vis[y]) continue;
			getrt(y,x); siz[x]+=siz[y];
			mx[x]=max(mx[x],siz[y]);
		}
		mx[x]=max(mx[x],total-siz[x]);
		if(mx[x]<mx[rt]) rt=x;
	}
	inline void solve(int x) {
		vis[x]=1;
		for(R int i=head[x];i;i=e[i].next) {
			int y=e[i].to;
			if(vis[y]) continue;
			total=siz[y]; rt=0; getrt(y,0);
			fa[rt]=x; solve(rt);
		}
	}
	inline void build() {
		total=n; mx[0]=inf; getrt(1,0);
		getrt(rt,0); solve(rt);
	}
	inline void update(int x,int v) {
		for(R int i=x;i;i=fa[i]) {
			sm1[i].Add(Graph::siz[i],Graph::dis(x,i),v);
			if(fa[i])
				sm2[i].Add(Graph::siz[fa[i]],Graph::dis(x,fa[i]),v);
		}
	}
	inline int ask(int x,int k) {
		int res=0;
		int lst=0;
		for(R int i=x;i;i=fa[i]) {
			int d=Graph::dis(x,i);
			if(d>k) { lst=i; continue; }
			res+=sm1[i].Ask(Graph::siz[i],0,k-d);
			if(lst) res-=sm2[lst].Ask(Graph::siz[i],0,k-d);
			lst=i;
		}
		return res;
	}
};

inline void Init() {
	n=read(); m=read();
	for(R int i=1;i<=n;i++) val[i]=read();
	for(R int i=1;i<n;i++) {
		int x=read(), y=read();
		add(x,y); add(y,x);
	}
}

inline void Solve() {
	for(R int i=1;i<=n;i++) Tree::update(i,val[i]);
	int las=0;
	while(m--) {
		int op=read(),x=read(),y=read();
		x^=las; y^=las;
		if(op==0) printf("%d\n",las=Tree::ask(x,y));
		else Tree::update(x,y-val[x]),val[x]=y;
	}
}

int main() {
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	Init();
	Graph::build(); Tree::build();
	Solve();
	return 0;	
}

