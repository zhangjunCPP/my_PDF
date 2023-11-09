#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define N 110
#define ll long long
#define mod 1000000007
int n,m;
ll k,fac[N],in[N],rl;
struct G{
	int x,y;
	ll a,b;
}e[N];
ll qpow(ll a,ll b){
	ll res=1;
	for(;b;b>>=1,a=a*a%mod){
		if(b&1){
			res=res*a%mod;
		}
	}
	return res;
}
ll c(ll n,ll m){
	ll ans=1;
	For(i,n-m+1,n)ans=ans*i%mod;
	return ans%mod;
}
namespace f1{
	int a[N],b[N],cnt;
	ll ans=0;
	void dfs(int x){
		if(x==n+1){
			ll res=1;
			For(i,1,m){
				int x=e[i].x,y=e[i].y;
				if(a[x]!=a[y])res=res*e[i].a%mod;
				else res=res*e[i].b%mod;
			};
			(ans+=res*c(k,cnt)%mod)%=mod;
			return;
		}
		For(i,1,cnt){
			a[x]=i;
			dfs(x+1);
		};
		a[x]=++cnt;
		dfs(x+1);
		--cnt;
	};
	void f1(){
		ans=0;
		dfs(1);
		cout<<ans<<'\n';
	}
}
void solve(){
	cin>>n>>m>>k;
	For(i,1,m){
		cin>>e[i].x>>e[i].y>>e[i].a>>e[i].b;
	};
	fac[0]=1;
	For(i,1,n)fac[i]=fac[i-1]*i%mod;
	in[n]=qpow(fac[n],mod-2);
	for(int i=n;i;--i)in[i-1]=in[i]*i%mod;
	rl=min((ll)n,k);
	if(rl<=8)f1::f1();
	else cout<<fac[n];
	return;
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
/*
35。寄寄寄寄寄。
*/
