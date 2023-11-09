#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,s[200001],d[200001],vis[200001],out[200001];
multiset <int> dis[200001];
vector <pair<int,int> > G[200001];
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++) scanf("%d",&s[i]);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++) dis[s[i]].insert(0),q.push({0,s[i]}),out[s[i]]=1;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto y:G[x]){
			if(out[y.first]||(int)G[y.first].size()<=d[y.first]) continue;
			dis[y.first].insert(*dis[x].rbegin()+y.second);
			if((int)dis[y.first].size()>d[y.first]+1) dis[y.first].erase(dis[y.first].find(*dis[y.first].rbegin()));
			if((int)dis[y.first].size()==d[y.first]+1) q.push({*dis[y.first].rbegin(),y.first});
		}
	}
	if((int)dis[1].size()>d[1]) printf("%d",*dis[1].rbegin());
	else printf("-1");
	return 0;
}
