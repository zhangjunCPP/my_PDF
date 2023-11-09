#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
inline ll qpow(ll a,ll b){
	ll ret=1ll;
	for( ; b; b>>=1ll){
		if(b&1ll) ret=ret*a%mod;
		a=a*a%mod;
	}
	return ret;
}
int n;
const int maxn=1e6+5;
vector<int> G[maxn];
ll dep[maxn];
inline void dfs(int x,int fa){
	for(auto v:G[x]){
		if(v!=fa){
			dep[v]=dep[x]+1;
			dfs(v,x);
		}
	}
}
priority_queue < pair<ll,int> > q;
int vis[maxn];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout); 
	scanf("%d",&n); 
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dep[1]=1; dfs(1,1);
	int x=1;
	for(int i=1;i<=n;i++) if(dep[x]<dep[i]) x=i;
	dep[x]=1; dfs(x,x);
	int y=1;
	for(int i=1;i<=n;i++) if(dep[y]<dep[i]) y=i;
	for(int i=1;i<=n;i++) if(i!=y && i!=x) q.push(make_pair(dep[i]-1,i));
	ll ans=(dep[y]-1)*qpow(2,n-1)%mod;
	dep[y]=1; dfs(y,y);
	for(int i=1;i<=n;i++) if(i!=x && i!=y) q.push(make_pair(dep[i]-1,i));
	int cnt=2;
	while(!q.empty()){
		pair<ll,int> v=q.top(); q.pop();
		ll x=v.first;
		int y=v.second;
		vis[y]++;
		if(vis[y]==1){
			ans=(ans+qpow(2,n-cnt)*x)%mod; 
			cnt++; 
		}
		else{
			ans=(ans+qpow(2,n-cnt+1)*x)%mod;
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}
