#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,k,s[N],d[N];
vector<pair<int,int> >E[N]; 
int vis[N],dis[N];
void dij(int s){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	memset(vis,0,sizeof(vis));memset(dis,127,sizeof(dis));
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;q.pop();
		vis[u]=1;
		for(pair<int,int>i:E[u]){
			int v=i.first,w=i.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v])q.push({dis[v],v});
			}
		}
	}
}
void sol1(){
	dij(1);
	int ans=1e9;
	for(int i=1;i<=k;i++){
		ans=min(ans,dis[s[i]]);
	}
	if(ans==1e9)ans=-1;
	printf("%d",ans);
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&s[i]);
	}
	int fl=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]); 
		if(d[i]!=0)fl=0;
	}
	for(int i=1;i<=n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		E[x].push_back({y,z});
		E[y].push_back({x,z});
	}
	if(fl)sol1();
	else{
		cout<<-1;
	}
	return 0;
}

