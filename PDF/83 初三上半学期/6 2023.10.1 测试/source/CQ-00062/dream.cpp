#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=1e5+5;
int n,m,Q,k,id;
using ll=long long;
struct pt{
	int u;ll dis;
	bool operator<(const pt&b)const{return dis>b.dis;}
};
priority_queue<pt> q;
vector<pt> E[N];
const ll mod=1e9+7;
ll ans[N],dis[N];int vis[N];
ll dij(int s,int t){
	for(int i=1;i<=n;i++)vis[i]=ans[i]=0,dis[i]=998244353114514ll;
	q.push({s,0});dis[s]=0;ans[s]=1;
	while(q.size()){
		int u=q.top().u;q.pop();
		if(vis[u]++)continue;
		for(pt V:E[u]){
			int v=V.u;
			if(dis[u]+V.dis<dis[v]){
				ans[v]=ans[u];dis[v]=dis[u]+V.dis;
				q.push({v,dis[v]});
			}else if(dis[u]+V.dis==dis[v])ans[v]=(ans[v]+ans[u])%mod;
		}
	}return ans[t];
}
void solve0(){
	for(int i=1;i<=m;i++){
		int u=rd(),v=rd(),w=rd();
		E[u].push_back({v,w});
		E[v].push_back({u,w});
	}while(Q--){
		int u=rd(),v=rd();
		printf("%lld\n",dij(u,v));
	}
}ll d[1002][1002],cnt[1002][1002];
void small(){
	for(int i=1;i<=m;i++){
		int u=rd(),v=rd(),w=rd();
		E[u].push_back({v,w});
		E[v].push_back({u,w});
	}for(int i=1;i<=n;i++){
		dij(i,1);
		for(int j=1;j<=n;j++)d[i][j]=dis[j],cnt[i][j]=ans[j];
	}
	while(Q--){
		int u=rd(),v=rd();
		ll sum=0;
		for(int i=1;i<=n;i++){
			if(v==i)continue;
			if(d[u][i]+d[i][v]==d[u][v]){
				int ct=0,id=0;
				for(pt j:E[i]){
//					if(j.u==v)continue;
					if(d[u][i]+j.dis+d[j.u][v]==d[u][v]){
						ct++,id=j.u;
					}
					sum=(sum+cnt[u][i]*cnt[j.u][v]%mod)%mod;
				}if(ct==1)sum=(sum+mod-cnt[u][i]*cnt[id][v]%mod)%mod;
			}
		}printf("%lld\n",sum%mod);
	}
}
int main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	n=rd(),m=rd(),Q=rd(),k=rd(),id=rd();
	if(k==0)return solve0(),0;
	if(n<=1000)return small(),0;
	return 0;
}
/*
4 5 2 0 0
1 2 1
2 3 1
1 3 2
2 4 5
3 4 2
1 3
1 4
*/
/*
7 12 1 1 0
1 2 2
2 3 2
3 4 2
4 5 2
5 6 2
6 1 2
1 7 1
2 7 3
3 7 1
4 7 3
5 7 1
6 7 3
3 6
*/
