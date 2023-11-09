#include<bits/stdc++.h>
using namespace std;
int n,m,q,k,id,s,t,w,vis[100001],cnt[2][100001];
long long dis[2][100001];
vector <pair<int,int> > G[100001];
map <pair<pair<int,int>,int>,bool> has;
priority_queue <pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > Q;
const int mod=1e9+7;
void solve(int p,int s){
	for(int i=1;i<=n;i++) vis[i]=cnt[p][i]=0,dis[p][i]=1e16;
	dis[p][s]=0,cnt[p][s]=1;
	Q.push({0,s});
	while(!Q.empty()){
		int x=Q.top().second;
		Q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto y:G[x]){
			if(dis[p][y.first]>dis[p][x]+y.second) dis[p][y.first]=dis[p][x]+y.second,cnt[p][y.first]=0,Q.push({dis[p][y.first],y.first});
			if(dis[p][y.first]==dis[p][x]+y.second) cnt[p][y.first]=(cnt[p][y.first]+cnt[p][x])%mod;
		}
	}
}
int main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);

	scanf("%d%d%d%d%d",&n,&m,&q,&k,&id);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&s,&t,&w);
		if(has[{{s,t},w}]) continue;
		has[{{s,t},w}]=has[{{t,s},w}]=1;
		G[s].push_back({t,w});
		G[t].push_back({s,w});
	}
	while(q--){
		scanf("%d%d",&s,&t);
		solve(0,s);
		solve(1,t);
		if(k==0) printf("%d\n",cnt[0][t]);
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				if(i==t||dis[0][i]+dis[1][i]!=dis[0][t]) continue;
				int n1=0,n2=0,n3=0;
				for(auto j:G[i]){
					if(dis[0][i]+j.second+dis[1][j.first]==dis[0][t]) n1++,n2=(n2+cnt[1][j.first])%mod;
					else n3=(n3+cnt[1][j.first])%mod;
				}
				ans=(ans+1ll*cnt[0][i]*(min(1,n1-1)*n2+n3)%mod)%mod;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
