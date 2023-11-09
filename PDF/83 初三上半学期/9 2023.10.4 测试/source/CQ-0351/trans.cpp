#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
using ll=long long;
const int Mod=1e9+7;
int u[105],v[105],w[105][2];
int col[105];
ll quickly_power(ll a,int b){
	ll res=1;
	for(;b;b>>=1,(a*=a)%=Mod)if(b&1)(res*=a)%=Mod;
	return res;
}
inline ll mulfac(int st,int ed){
	ll res=1;
	for(int i=st;i<=ed;++i)(res*=i)%=Mod;
	return res;
}
inline ll C(int n,int m){
	return mulfac(n-m+1,n)*quickly_power(mulfac(2,m),Mod-2)%Mod;
}
void dfs(int x,int c,int n,int m,int p,int k,ll &ans){
	if(x>n){
		ll val=1;
		for(int i=1;i<=m;++i)
			(val*=w[i][col[u[i]]==col[v[i]]])%=Mod;
//		for(int i=1;i<=n;++i)cout<<col[i]<<' ';cout<<'\n';
//		cout<<val<<' '<<C(k,p)<<'\n';
//		cout<<"----------\n";
		(ans+=val*mulfac(k-c+1,k)%Mod)%=Mod;
		return ;
	}
	for(int i=1;i<=c;++i)col[x]=i,dfs(x+1,c,n,m,p,k,ans);
	if(c<p)col[x]=++c,dfs(x+1,c,n,m,p,k,ans);
}
void solve(){
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=m;++i)cin>>u[i]>>v[i]>>w[i][0]>>w[i][1];
	ll ans=0;
	dfs(1,0,n,m,min(n,k),k,ans);
	cout<<ans<<'\n';
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}
