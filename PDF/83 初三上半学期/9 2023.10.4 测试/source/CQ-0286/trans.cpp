#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll P=1e9+7,N=2e2+2;
ll n,m,k,fac[N],inv[N],dp[N][2],f1[N][N],f2[N][N],T;
set<ll>e[N];
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}
void pre(ll n){
	fac[0]=inv[0]=1;
	for(ll i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%P;
	}
	inv[n]=qpow(fac[n],P-2);
	for(ll i=n;i>=1;i--){
		inv[i]=inv[i+1]*(i+1)%P;
	}
}
ll C(ll n,ll m){
	if(n<m)return 0;
	return fac[n]*inv[m]%P*inv[n-m]%P;
}
ll A(ll n,ll m){
	if(n<m)return 0;
	return fac[n]*inv[n-m]%P;
}
void DP(ll x,ll fa){
	for(ll y:e[x]){
		if(y==fa)continue;
		DP(y,x);
		(dp[x][0]+=(dp[y][0]+dp[y][1])%P*f1[x][y]%P)%=P;
		(dp[x][1]+=(dp[y][0]+dp[y][1])%P*f2[x][y]%P)%=P;
	}
	if(!dp[x][0]&&!dp[x][1])dp[x][0]=dp[x][1]=1;
}
void clear(){
	for(ll i=1;i<=n;i++){
		e[i].clear();
		for(ll j=1;j<=n;j++){
			f1[i][j]=1;
			f2[i][j]=1;
		}
	}
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	scanf("%lld",&T);
	pre(N-2);
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);
		//点数 边数 集合数 
		clear();
		bool B=1,D=0;
		for(ll i=1,x,y,z1,z2;i<=m;i++){
			scanf("%lld%lld%lld%lld",&x,&y,&z1,&z2);
			if(z1!=1||z2!=0)B=0;
			f1[x][y]*=z1;f1[y][x]*=z1;
			f2[x][y]*=z2;f2[y][x]*=z2;
			if(!z1&&!z2)D=1;
			e[x].insert(y);
			e[y].insert(x);
		}
		if(D){
			printf("0\n");
			continue;
		}
		if(B){//每个集合只能有一个点 
			printf("%lld\n",A(k,n));
			continue;
		}
	}	
	return 0;
}

