#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn=2e5+5;
int d[maxn],dis[maxn],vis[maxn],s[maxn];
vector< pair<int,int> > G[maxn];
priority_queue< pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > q;
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&k);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=k;i++) scanf("%d",&s[i]);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	for(int i=1,x,y,w;i<=m;i++){
		scanf("%d%d%d",&x,&y,&w);
		G[x].push_back(make_pair(w,y));
		G[y].push_back(make_pair(w,x)); 
	}
	for(int i=1;i<=k;i++){
		d[s[i]]=0,dis[s[i]]=0;
		q.push(make_pair(0,s[i]));
	}
	while(!q.empty()){
		int rt=q.top().second;
		int dist=q.top().first;
		q.pop();
		if(d[rt]-->0) continue;
		if(vis[rt]) continue;
		dis[rt]=dist;
		vis[rt]=1;
		for(auto v:G[rt]){
			int to=v.second,w=v.first;
			if(dis[to]>dis[rt]+w){
				q.push(make_pair(dis[rt]+w,to));
			}
		}
	}
	if(dis[1]==0x3f3f3f3f) printf("-1");
	else printf("%d",dis[1]);
	return 0;
} 
