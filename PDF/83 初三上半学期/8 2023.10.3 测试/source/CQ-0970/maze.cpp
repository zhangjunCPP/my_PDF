#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; bool f=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
const int N=2e5+5;
struct node{ int to,val; };
vector<node> e[N];
int n,m,k;
int s[N],d[N];
int dis[N];
bool vis[N];
namespace sub1{//d=0
	bool check(){
		for(int i=1;i<=n;i++) if(d[i]) return 0;
		return 1;
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	void dijkstra(int s){
		for(int i=1;i<=n;i++) dis[i]=INT_MAX;
		dis[s]=0;
		memset(vis,0,sizeof vis);
		q.emplace(make_pair(0,s));
		while(!q.empty()){
			int u=q.top().second; q.pop();
			if(vis[u]) continue;
			vis[u]=1; 
			for(auto i:e[u]){
				int v=i.to,w=i.val;
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					q.emplace(make_pair(dis[v],v));
				}
			}
		}
	}
	void work(){
		dijkstra(1);
		int ans=INT_MAX;
		for(int i=1;i<=k;i++) ans=min(ans,dis[s[i]]);
		printf("%d",ans==INT_MAX?-1:ans);
	}
}
//namespace sub2{//n,m<=15
//	int ans=0;
//	bool tag[N];
//	void dfs(int u,int fa,int val){
//		if(s[i])
//		if(d[u]>=e[u].size()-1) return ;
//		for(auto i:e[u]){
//			int v=i.to,w=i.val;
//			if(v!=fa) dfs(v,u,val+w);
//		}
//	}
//	void work(){
//		for(int i=1;i<=k;i++) tag[s[i]]=1;
//		dfs(1,0,0);
//		printf("%d",ans);
//	}
//}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	_(n),_(m),_(k);
	for(int i=1;i<=k;i++) _(s[i]);
	for(int i=1;i<=n;i++) _(d[i]);
	for(int i=1;i<=m;i++){
		int u,v,w; _(u),_(v),_(w);
		e[u].emplace_back((node){v,w}),e[v].emplace_back((node){u,w});
	}
	if(sub1::check()) sub1::work();
//	else sub2::work();
	return 0;
}
/*
6 7 1
6
0 0 0 0 0 0
1 2 2
1 3 4
2 3 3
3 5 5
3 4 8
5 6 2
4 6 6
11

*/
