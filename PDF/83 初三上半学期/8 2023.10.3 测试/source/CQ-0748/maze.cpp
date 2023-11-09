#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
inline void Freopen(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
}
template <typename T>
inline void read(T &x){
	bool f=0; x=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
}
template <typename T,typename ...Args>
inline void read(T &x,Args &...args){read(x); read(args...);}
int n,m,k;
struct node{
	int to,nxt,w;
}edge[MAXN<<1],tmp[MAXN];
int s[MAXN],d[MAXN],head[MAXN],tot;
inline void add(int u,int v,int w){
	edge[++tot]={v,head[u],w}; head[u]=tot;
	return ;
}
bool can[MAXN],flag,Flag;
int du[MAXN],ans,ansu;
inline bool cmp(node x,node y){
	if(can[x.to] && can[y.to]) return x.w<y.w;
	if(can[x.to]) return true;
	if(can[y.to]) return false;
	return x.w<y.w;
}
void dfs(int u,int fa){
	ansu=u;
	if(flag) return ;
	if(Flag) return ;
	if(can[u]) return Flag=true,void();
	if(du[u]<=d[u]) return flag=true,void();
	int len=0;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to,w=edge[i].w;
		tmp[++len]={v,0,w};
	}
	sort(tmp+1,tmp+len+1,cmp);
	for(int i=d[u]+1;i<=len;i++){
		if(tmp[i].to==fa) continue;
		ans+=tmp[i].w;
		dfs(tmp[i].to,u);
		if(flag) return ;
		if(Flag) return ;
	}
}
int main(){
	Freopen();
	read(n,m,k);
	for(int i=1;i<=k;i++) read(s[i]),can[s[i]]=true;
	for(int i=1;i<=n;i++) read(d[i]);
	for(int i=1;i<=m;i++){
		int u,v,w; read(u,v,w);
		du[u]++; du[v]++;
		add(u,v,w); add(v,u,w);
	}
	dfs(1,0);
	if(flag) return puts("-1"),0;
	if(can[ansu]) printf("%d",ans);
	else puts("-1");
	return 0;
} 
/*
5 8 3
2 3 5
2 0 1 1 2
1 2 1
2 3 2
3 4 5
2 5 3
4 5 2
5 1 3
3 5 2
4 1 1
*/
