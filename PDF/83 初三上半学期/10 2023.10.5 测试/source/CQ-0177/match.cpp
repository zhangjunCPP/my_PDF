#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
#define pb push_back
const ll N=1e6+10;
using namespace std;

ll n,m,flag;
ll in[N],vis[N],fa[N];
vector<ll>e[N];

void dfs(ll x){
	vis[x]=1;
	for(ll y:e[x]){
		if(vis[y]){
			if(y==fa[fa[x]])flag=1;
			continue;
		}
		fa[y]=x;
		dfs(y);
	}
}

void mian(){
	
	scanf("%lld%lld",&n,&m);
	For(i,1,m){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		++in[x],++in[y];
		e[x].pb(y),e[y].pb(x);
	}
	For(i,1,n)if(!vis[i])dfs(i);
	ll ans=flag?3:0;
	For(i,1,n)ans=max(ans,in[i]);
	printf("%lld\n",ans);
	
	flag=0;
	For(i,1,n)in[i]=vis[i]=fa[i]=0,e[i].clear();
	
}

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T=1;
	scanf("%d",&T);
	while(T--)mian();
	return 0;
}
