/*
t4非常简单
裸的A*

我们利用启发式搜索
当第k次搜到n
这条路就是第k短路

具体做法
先以n为起点跑一遍dijkstra计算最短路
然后从1开始搜索
每次优先搜索最优的决策点
类似while跑bfs
路上随时用数组记录先前状态，方便输出答案

值得注意的是，图上有环
而题目要求则明确指出不允许路径存在环
因此我们还需把环排掉 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int cnt,first[N],cn,firs[N];
struct Edge{
	int u,v,w,nex;
}a[N],b[N];
void add(int u,int v,int w){
	a[++cnt]={u,v,w,first[u]};
	first[u]=cnt;
}
void ad(int u,int v,int w){
	b[++cn]={u,v,w,firs[u]};
	firs[u]=cn;
}
struct node{
	int id,x;
	bool operator < (const node &b)const{
		return x>b.x;
	}
};
struct B{
	int u,dis,dep;
	bool operator < (const B &b)const{
		return dis==b.dis?u==b.u?dep>b.dep:u>b.u:dis>b.dis;
	}
};
int dis[N];
bool vis[N];
void dijkstra(int s){
	priority_queue<node>q;
	memset(dis,63,sizeof dis);
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().id;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=firs[u];i;i=b[i].nex){
			int v=b[i].v,w=b[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
int s[N];
void print(int ans){
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i)printf("%d ",s[i]);
}
int n,m,k,i,x,y,z,tot,mx,las;
priority_queue<B>q;
string none;
struct C{
	int d;
	string all;
};
vector<C>al;
void dfs(int u,int dep,int d){
	vis[u]=1;
	s[dep]=u;
	if(u==n){
		C now;
		now.d=d;
		for(int i=1;i<=dep;++i)now.all+=s[i];
		al.push_back(now);
		vis[u]=0;
		return;
	}
	for(int i=first[u];i;i=a[i].nex){
		int v=a[i].v,w=a[i].w;
		if(!vis[v]&&dis[v]<dis[0])dfs(v,dep+1,d+w);
	}
	vis[u]=0;
}
bool cmp(C x,C y){
	return x.d==y.d?x.all<y.all:x.d<y.d; 
}
int main(){
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);//崇明
	for(i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		ad(y,x,z);
	} 
	dijkstra(n);
//	for(i=1;i<=n;++i)printf("dis[%d]=%d\n",i,dis[i]);
	for(i=1;i<=n;++i)vis[i]=0;
	if(dis[1]<dis[0])dfs(1,1,0);
//	if(dis[1]<dis[0])q.push({1,dis[1],1});
//	while(!q.empty()){
//		int u=q.top().u,dep=q.top().dep;q.pop();
//		if(las==n)for(int i=mx;i>=dep;--i)vis[s[i]]=0;
//		las=u;
//		s[dep]=u;
//		vis[u]=1;
//		if(u==n){
//			string now=none;
//			for(int i=1;i<=dep;++i)now+=s[i];
//			all.push_back(now);
//			mx=dep;
//			las=n;
//			continue;
//		}
//		for(int i=first[u];i;i=a[i].nex){
//			int v=a[i].v,w=a[i].w;
//			if(vis[v])continue;
//			q.push({v,dis[v],dep+1});
//		}
//	}
	if(al.size()<k)return puts("-1"),0;
	sort(al.begin(),al.end(),cmp);
	printf("%d\n",al[k-1].size()-1);
	for(i=1;all[k-1][i];++i)printf("%d ",al[k-1][i]);
	return 0;
}

