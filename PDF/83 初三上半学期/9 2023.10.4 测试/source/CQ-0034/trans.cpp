#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
#define pb push_back
const ll N=100+10;
const ll p=1e9+7;
using namespace std;
ll ksm(ll a,ll b){ll bns=1;for(;b;b>>=1,a=a*a%p)if(b&1)bns=bns*a%p;return bns;}

struct node{
	ll x,y,z1,z2;
}edge[N];

ll n,m,k;
pair<ll,ll>e[N][N];
struct NODE{
	ll y;
	pair<ll,ll>z;
};
vector<NODE>g[N];

namespace sub1{
	ll ans;
	ll a[N];
	void calc(){
		ll res=1;
		For(i,1,m){
			ll x=edge[i].x,y=edge[i].y,z1=edge[i].z1,z2=edge[i].z2;
			if(a[x]!=a[y])res=res*z1%p;
			else res=res*z2%p;
		}
		ans=(ans+res)%p;
	}
	void dfs(ll x){
		if(x==n+1)return calc();
		For(i,1,k)a[x]=i,dfs(x+1);
	}
	void solve(){
		dfs(1);
		printf("%lld\n",ans);
	}
}

namespace sub2{
	ll dp[N];
	void dfs(ll x,ll fa){
		for(auto i:g[x]){
			ll y=i.y;
			if(y==fa)continue;
			dfs(y,x);
		}
		For(i,0,(ll)g[x].size()-1){
			ll y=g[x][i].y;
			if(y==fa){
				g[x].erase(g[x].begin()+i);
				break;
			}
		}
		if(!g[x].size())return;
		dp[x]=0;
		ll lim=(1<<g[x].size())-1;
		For(s,0,lim){
			ll res=1;
			For(i,0,(ll)g[x].size()-1){
				ll y=g[x][i].y;
				pair<ll,ll>z=g[x][i].z;
				if((s>>i)&1)res=res*dp[y]%p*z.second%p;
				else res=res*dp[y]%p*(k-1)%p*z.first%p;
			}
			dp[x]=(dp[x]+res)%p;
		}
	}
	void solve(){
		For(i,1,n)dp[i]=1;
		dfs(1,0);
		printf("%lld\n",dp[1]*k%p);
	}
}

void mian(){
	
	scanf("%lld%lld%lld",&n,&m,&k);
	For(i,1,n)For(j,1,n)e[i][j]={0,0};
	For(i,1,n)g[i].clear();
	For(i,1,m){
		ll x,y,z1,z2;
		scanf("%lld%lld%lld%lld",&x,&y,&z1,&z2);
		e[x][y]={e[x][y].first+z1,e[x][y].second+z2};
		e[y][x]={e[y][x].first+z1,e[y][x].second+z2};
		edge[i]={x,y,z1,z2};
	}
	For(i,1,n)For(j,1,n)if(e[i][j]!=make_pair(0ll,0ll))g[i].pb({j,e[i][j]});
	if(k<=13){
		sub1::solve();
		return;
	}
	if(m==n-1){
		sub2::solve();
		return;
	}
	sub1::solve();
	
}

int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	int T=1;
	scanf("%d",&T);
	while(T--)mian();
	return 0;
}
