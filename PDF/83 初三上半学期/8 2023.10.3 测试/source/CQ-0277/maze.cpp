//ħ���������������뿪������ǰ��
//���Ե�������������ǰ��
//��������ô֪��ǰk�̵�·��ʲô?
//���ǿ϶�����dis<������Genshin��,����ֱ��dijkstra��sortһ��? 
//ά��ǰd+1С,Ȼ����С���Ǹ��϶����ܱ���.��! 
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,k,d[200010],vis[200010];
struct edge{int v,w;};
vector<edge>G[200010];
priority_queue<ll>cdis[200010];
ll dis[200010];
ll dijkstra(vector<int>src){
	priority_queue<pair<ll,int>>q;
	fill_n(dis+1,n,1e18);
	for(int u:src)q.emplace(dis[u]=0,u);
	for(int u;!q.empty();){
		u=q.top().second,q.pop();
		if(u==1)return dis[u];
		if(vis[u]++)continue;
		for(auto e:G[u]){
			int v=e.v,w=e.w;ll x;cdis[v].push(dis[u]+w);
			if(cdis[v].size()>d[v]+1)cdis[v].pop();
			if(cdis[v].size()>d[v]&&(x=cdis[v].top())<dis[v])
			q.emplace(-(dis[v]=x),v);
		}
	}return -1;
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	cin>>n>>m>>k;
	vector<int>s(k);
	for(int&u:s)scanf("%d",&u);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	for(int i=1,u,v,w;i<=m;i++)
	scanf("%d%d%d",&u,&v,&w),G[u].push_back({v,w}),G[v].push_back({u,w});
	cout<<dijkstra(s);
	return 0;
}
