/*
B 追梦人
巧妙利用Dij应该能过，这题可能Dij的变形
从 $k = 0$ 的部分思考，很容易得到Dij的做法来解决这部分问题，直接求解最短路方案数即可
但此时我们可能出现一次偏航，偏航之后会重新搜索最短路，这时候就出现了问题
我们需要得到这里的最短路方案数，那么我们自然而然想到从终点建反图来做这个点
紧接着我们最大的难点在于偏航计数
其实也没什么难的，我们只是正着再来一遍Dij，中间加入一点魔改，把所有可能的偏航都给您算上
这里有细节了，当我们有多个可扩展节点的时候，很显然另一个可能会被 “偏航 ”，所以需要处理这部分 
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7,N=100010;
struct edge{
	int v,w,nex;
}e[N*4];
int fir[N],ent;
inline void add(int u,int v,int w){
	e[++ent]={v,w,fir[u]};
	fir[u]=ent;
	return;
}
ll dis[N],way[N];
priority_queue<pair<int,int>>q;
queue<int>b;
int main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	int n,m,Q,k,id;
	scanf("%d%d%d%d%d",&n,&m,&Q,&k,&id);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	while(Q--){
		ll ans=0;
		int s,t;
		scanf("%d%d",&s,&t);
		memset(dis,0x7f,sizeof dis);
		memset(way,0,sizeof way);
		dis[t]=0,way[t]=1;
		q.push(make_pair(0,t));
		while(!q.empty()){
			int u=q.top().second,d=-q.top().first;q.pop();
			if(dis[u]!=d)continue;
			for(int i=fir[u];i;i=e[i].nex){
				int v=e[i].v;
				if(dis[v]>dis[u]+e[i].w){
					way[v]=way[u];
					dis[v]=dis[u]+e[i].w;
					q.push(make_pair(-dis[v],v));
				}
				else if(dis[v]==dis[u]+e[i].w)way[v]=(way[v]+way[u])%mod;
			}
		}
		if(k==0){printf("%lld\n",way[s]);continue;}
		if(way[s]==0){puts("0");continue;}
		b.push(s);
		while(!b.empty()){
			int u=b.front();b.pop();
			if(u==t)continue;
			int pos=0;
			for(int i=fir[u];i;i=e[i].nex){
				int v=e[i].v;
				if(dis[u]==dis[v]+e[i].w){
					b.push(v);
					if(pos>0&&pos<=n)ans=(ans+way[pos]+way[v])%mod,pos=n+1;
					else if(pos>n)ans=(ans+way[v])%mod;
					else pos=v;
				}
				else ans=(ans+way[v])%mod;
			}
		}
		while(!b.empty())b.pop();
		printf("%lld\n",ans);
	}
	return 0;
}
