//sb 
#include<bits/stdc++.h>
using namespace std;
namespace IO{
	template<typename T> void Read(T &x){
		x=0; bool f=0; char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
		if(f) x=-x;
	}
	template<typename T,typename ...Args> void Read(T &x,Args &...args){
		Read(x),Read(args...);
	}
	void Write(char x){ putchar(x); }
	template<typename T> void Write(T x){
		if(x<0) x=-x,putchar('-');
		int stk[50],top=0;
		do stk[++top]=x%10,x/=10; while(x);
		for(;top;top--) putchar(stk[top]^48);
	}
	template<typename T,typename ...Args> void Write(T x,Args ...args){
		Write(x),Write(args...);
	}
}
const int N=2e5+5;
vector<int> tw[N],ct[N];
int n,k;
int sz[N],top[N],deep[N],fa[N],son[N],rev[N],dfn[N],tt;
void dfs1(int u,int fath){
	sz[u]=1,deep[u]=deep[fath]+1,fa[u]=fath;
	for(auto v:tw[u]) if(v!=fath){
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int tp){
	top[u]=tp,dfn[u]=++tt,rev[tt]=u;
	if(son[u]) dfs2(son[u],tp);
	for(auto v:tw[u]) if(v!=son[u]&&v!=fa[u]) dfs2(v,v);
}
//int LCA(int u,int v){
//	for(;top[u]!=top[v];u=fa[top[u]]) if(deep[top[u]]<deep[top[v]]) swap(u,v);
//	return deep[u]<deep[v]?u:v;
//}
//int dist(int u,int v){ return deep[u]+deep[v]-2*deep[2*LCA(u,v)]; }
bool tag[105],tg[105];
void cvr(int u,int v){
//	printf("u:%d v:%d\n",u,v);
	for(;top[u]!=top[v];u=fa[top[u]]){
//		printf("u:%d\n",u);
		if(deep[top[u]]<deep[top[v]]) swap(u,v);
//		cout<<dfn[top[u]]<<" "<<dfn[u]<<"\n";
//		printf("top:%d,u:%d\n",top[u],u);
		for(int i=dfn[top[u]];i<=dfn[u];i++) tag[i]=1;
	}
	if(deep[u]>deep[v]) swap(u,v);
//	if(u==1&&v==3) printf("dfn:u,v,%d,%d\n",dfn[u],dfn[v]);7
	for(int i=dfn[u];i<=dfn[v];i++) tag[i]=1;
}
int c[N];
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	IO::Read(n,k);
	for(int i=1;i<n;i++){
		int u,v; IO::Read(u,v);
		tw[u].emplace_back(v),tw[v].emplace_back(u);
	}
	for(int i=1;i<=n;i++){
		IO::Read(c[i]);
		ct[c[i]].emplace_back(i);
	}
	dfs1(1,0);
	dfs2(1,1);
//	for(int i=1;i<=n;i++) printf("dfn[%d]=%d\n",i,dfn[i]);
//	for(int i=1;i<=n;i++) printf("top[%d]=%d\n",i,top[i]);
	int ans=0x3f3f3f3f;
	for(int i=1;i<=k;i++){
		memset(tag,0,sizeof tag);
		memset(tg,0,sizeof tg);
		int len=ct[i].size(),cnt=-1;
		for(int j=0;j<len;j++) for(int l=j+1;l<len;l++) cvr(ct[i][j],ct[i][l]);
		for(int j=1;j<=n;j++) if(tag[j]) if(!tg[c[j]]) cnt++,tg[c[j]]=1;
//		if(cnt==1) printf("%d\n",i);
		ans=min(ans,cnt);
	}
	IO::Write(ans);
	return 0;
}

