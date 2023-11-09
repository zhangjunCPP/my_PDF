#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
const int N=2e5+10,mod=998244353;
void File(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
}
struct G{
	int l,r,id;
}a[N];
int v[N];
int n,m;
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int dp[501][501];
ll ans;
vector<pii >f[N];
void dfs(int x,int r,vector<int> p){
	if(x>r) {
		int u=1;
		if(p.size()==1) u=p[0];
		if(p.size()>=2) u=gcd(p[0],p[1]);
		for(int i=2;i<p.size();i++) u=gcd(u,p[i]);
		ans=ans*u%mod;
		return;
	}
	dfs(x+1,r,p);
	p.pb(v[x]);
	dfs(x+1,r,p);
}
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	File();
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		a[i]={l,r,i};
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(gcd(v[i],v[j])!=1) f[i].pb({j,gcd(v[i],v[j])});
		}
	}
	for(int i=1;i<=m;i++){
		int l,r;
		l=a[i].l,r=a[i].r;
		ans=1;
		vector<int>p;
		dfs(l,r,p);
		cout<<ans<<endl;
	}
}
