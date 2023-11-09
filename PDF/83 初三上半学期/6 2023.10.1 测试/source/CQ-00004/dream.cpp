#include<bits/stdc++.h>
#define int long long
const int mod=1e9+7;
const int QWQ=2e5+5;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	return x*f;
} int s1,s2,xl,yl; vector<int> e[QWQ]; bool vis[QWQ];
struct node{ int to,next,val; } E[QWQ<<1];
int n,m,q,k,id,cnt,head[QWQ],dis[QWQ],f[QWQ],in[QWQ];
inline void append(int x,int y,int z){
	E[++cnt].to=y;
	E[cnt].val=z;
	E[cnt].next=head[x];
	head[x]=cnt;
}
void ggt(int u,int fa,int st){
	for (int i=head[u];i;i=E[i].next){
		int v=E[i].to;
		if (v==fa) continue;
		if (u==xl) s2++;
		if (v==yl) s1=st+1;
		ggt(v,u,st+1);
	}
}
void get_12(){
	while (q--){
		xl=read(),yl=read();
		s1=s2=0; ggt(xl,xl,0);
		if (s2==1) printf("%lld\n",s1);
		else printf("%lld\n",s1+1);
	}
}
void dij(int st){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,st}); dis[st]=0;
	while (!q.empty()){
		int u=q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=head[u];i;i=E[i].next){
			int v=E[i].to;
			if (dis[v]>dis[u]+E[i].val){
				dis[v]=dis[u]+E[i].val;
				q.push({dis[v],v});
			}
		}
	}
}
void dfs(int u,int fa){
	for (int i=head[u];i;i=E[i].next){
		int v=E[i].to;
		if (v==fa) continue;
		if (dis[u]==dis[v]+E[i].val){
			e[v].push_back(u),in[u]++;
			dfs(v,u);
		}
	}
}
void get_28(){
	while (q--){
		xl=read(),yl=read();
		dij(xl);
		for (int i=1;i<=n;i++)
			e[i].clear(),f[i]=in[i]=0;
		dfs(yl,0);
//		for (int i=1;i<=n;i++)
//			printf("%lld ",in[i]); puts("");
		f[1]=1; queue<int> q; q.push(1);
		while (!q.empty()){
			int u=q.front(); q.pop();
			for (auto v:e[u]){
				f[v]=(f[v]+f[u])%mod;
				if (!--in[v]) q.push(v);
			}
		} printf("%lld\n",f[yl]);
	}
}
inline bool cheak1(int x){
	if (x==7||x==19||x==20) return true;
	return false;
}
inline bool cheak2(int x){
	if (x==5||x==6||(x>=12&&x<=16)) return true;
	return false;
}
signed main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	n=read(),m=read(),q=read(),k=read(),id=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		append(x,y,z),append(y,x,z);
	}
	if (cheak1(id)){ get_12(); return 0; }
	if (cheak2(id)){ get_28(); return 0; }
	
	return 0;
}
/*
11 1 -2
*/
