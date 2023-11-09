#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
inline void wr(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wr(x/10);
	putchar(x%10+'0');
}
inline void FRE(){
	freopen("umi.in","r",stdin);
	freopen("umi.out","w",stdout);
}
const int N=1e5+5;
const int mod=998244353;
int n,m,id;
int s[N];
int dep[N];
int fa[N][20];
bool vis[N],mark[N];
int ans;
int a[N],b[N];
vector<int> G[N];
inline void add(int u,int v){
	G[u].push_back(v);
}
inline void dfs(int u,int FA){
	dep[u]=dep[FA]+1;
	for(int v:G[u]){
		if(v==FA)continue;
		fa[v][0]=u;
		for(int i=1;i<20;++i)fa[v][i]=fa[fa[v][i-1]][i-1];
		dfs(v,u);
	}
}
inline int Get(int x,int y){
	for(int i=19;i>=0;--i){
		if(dep[fa[x][i]]>=y)x=fa[x][i];
	}
	return x;
}
inline int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	x=Get(x,dep[y]);
	for(int i=19;i;--i){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i],y=fa[y][i];
		}
	}
	if(x!=y)return fa[x][0];
	return x;
}
inline int dist(int u,int v){
	return dep[u]+dep[v]-2*dep[LCA(u,v)]+1;
}
inline void find(int aa,int bb,int pos,int vl,int S){
	if(vl+m-pos<S){
		return;
	}
	if(vl==S){
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;++i){
			if(vis[i])a[++cnt1]=i;
			if(mark[i])b[++cnt2]=i;
		}
		int lca=LCA(aa,bb);
		int x=aa,y=bb;
		int cnt=0;
		while(x!=fa[lca][0]){
			cnt++;
			if(s[x]==1){
				if(a[cnt]<b[cnt])return;
			}
			else{
				if(a[cnt]>b[cnt])return;
			}
			x=fa[x][0];
		}
		cnt=S;
		while(y!=lca){
			if(s[x]==1){
				if(a[cnt]<b[cnt])return;
			}
			else{
				if(a[cnt]>b[cnt])return;
			}
			y=fa[y][0];
			cnt--;
		}
		ans++;
		return;
	}
	for(int i=pos+1;i<=m;++i){
		if(vis[i])continue;
		mark[i]=1;
		find(aa,bb,i,vl+1,S);
		mark[i]=0;
	}
}
inline void cho1(int x,int y,int pos,int vl,int S){
	if(vl+m-pos<S){
		return;
	}
	if(vl==S){
		find(x,y,0,0,S);
		return;
	}
	for(int i=pos+1;i<=m;++i){
		vis[i]=1;
		cho1(x,y,i,vl+1,S);
		vis[i]=0;
	}
}
int main(){
	FRE();
	n=read(),m=read(),id=read();
	for(int i=1;i<=n;++i)s[i]=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0);
	int Q=read();
	while(Q--){
		ans=0;
		int x=read(),y=read();
		if(dist(x,y)*2>=m){
			puts("0");
			continue;
		}
		int s=dist(x,y);
		for(int i=1;i<=n;++i)vis[i]=0,mark[i]=0;
		cho1(x,y,0,0,s);
		wr(ans);putchar('\n');
	}
}
