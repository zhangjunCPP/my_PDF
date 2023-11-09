#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e3+2,INF=1e18;
ll n,ans,val,c[N],f[N][N],g[N],a[N],tot;
struct ROSE{ll l,r,c;}t[N];
set<ll>e[N];
void dfs(ll pos){
	if(pos>n){
		ans=max(ans,val);
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(g[i])continue;
		g[i]=1;
		ll cnt=0;
		for(ll j=t[i].l;j<=t[i].r;j++){
			if(g[j])continue;
			cnt+=t[i].c;
		}
		val+=cnt;
		dfs(pos+1);
		val-=cnt;
		g[i]=0;
	}
}
bool dfs1(ll pos){
	if(pos>n){
		if(val==ans)return 1;
		return 0;
	}
	bool res=0;
	for(ll i=1;i<=n;i++){
		if(g[i])continue;
		g[i]=1;
		ll cnt=0;
		for(ll j=t[i].l;j<=t[i].r;j++){
			if(g[j])continue;
			cnt+=t[i].c;
		}
		val+=cnt;
		if(dfs1(pos+1)){
			a[pos]=i;
			res=1;
		}
		val-=cnt;
		g[i]=0;
	}
	return res;
}
void getans(ll pos){
	if(pos>n)return ;
	ll i=a[pos];g[i]=1; 
	ll cnt=0;
	for(ll j=t[i].l;j<=t[i].r;j++){ 
		if(g[j])continue;
		cnt+=t[i].c;
	}
	val+=cnt;
	getans(pos+1);
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld",&n);
	bool A=1;
	for(ll i=1;i<=n;i++){
		scanf("%lld%lld%lld",&t[i].l,&t[i].r,&t[i].c);
		if(t[i].l!=i||t[i].r!=i)A=0;
	}
	if(A){//10
		for(ll i=1;i<=n;i++){
			ans+=t[i].c;
		}
		printf("%lld",ans);
		return 0;
	}
	if(n<=10){//10
		dfs(1);
		printf("%lld",ans);	
		return 0;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=t[i].l;j<=t[i].r;j++){
			if(i==j)continue;
			e[j].insert(i);
			f[i][j]=t[i].c;
		}
	}
	queue<ll>q;
	ll sum=n;
	while(sum){
		for(ll i=1;i<=n;i++){
			if(!e[i].size()&&!g[i]){
				q.push(i);
				sum--;
				g[i]=1;
				a[++tot]=i;
			}
		}
		if(q.empty()){
			sum--;
			ll mx=0,id=0;
			for(ll i=1;i<=n;i++){
				if(g[i])continue;
				ll res=0;
				for(ll j=1;j<=n;j++){
					res+=f[i][j];
				}
				for(ll x:e[i]){
					res-=f[x][i];
				}
				if(res>mx){
					mx=res;
					id=i;
				}else if(res==mx){
					if(f[i][id]>f[id][i])id=i;
				}
			}
			for(ll x:e[id]){
				f[x][id]=0;
			}
			e[id].clear();
			g[id]=1;
			a[++tot]=id;
			q.push(id);
		}
		while(!q.empty()){
			ll x=q.front();q.pop();
			for(ll y=1;y<=n;y++){
				if(!f[x][y])continue;
				e[y].erase(x);
				f[x][y]=0;
			}
		}
	}
	for(ll i=1;i<=n;i++){
		g[i]=0;
	}
	getans(1);
	printf("%lld",val);
	return 0;
}

