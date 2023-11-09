#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=2e5+5;
int n,m,k;vector<int> can;
int d[N],f=1;
using ll=long long;
ll dis[N];int vis[N];
struct pt{
	int v;ll dis;
	bool friend operator<(const pt&a,const pt&b){return a.dis>b.dis;}
};
priority_queue<pt> q;
vector<pair<int,int> > E[N];
void solve1(){
	q.push({1,0});for(int i=2;i<=n;i++)dis[i]=2e9;
	while(q.size()){
		int u=q.top().v;q.pop();
		if(vis[u]++)continue;
		for(auto V:E[u]){
			int v=V.first;
			if(dis[u]+V.second<dis[v]){dis[v]=dis[u]+V.second;q.push({v,dis[v]});}
		}
	}ll ans=2e9;for(int v:can)ans=min(ans,dis[v]);
	printf("%lld\n",ans);
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	n=rd(),m=rd(),k=rd();for(int i=1;i<=k;i++)can.push_back(rd());
	for(int i=1;i<=n;i++)d[i]=rd(),f&=!d[i];
	for(int i=1;i<=m;i++){
		int u=rd(),v=rd(),w=rd();
		E[u].push_back({v,w});E[v].push_back({u,w});
	}
	if(f)return solve1(),0;
	
	return 0;
}
/*
5 8 1
3
0 0 0 0 0
1 2 1
2 3 2
3 4 5
2 5 3
4 5 2
5 1 3
3 5 2
4 1 1

*/
