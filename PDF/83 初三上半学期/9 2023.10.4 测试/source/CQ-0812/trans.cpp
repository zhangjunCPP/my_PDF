#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=110,mod=1e9+7;
ll n,m,k,i,d,s,x,y,z,o;
//ll cnt,first[N];
//struct Edge{
//	ll u,v,
//};
void work(){
	scanf("%lld%lld%lld",&n,&m,&k);
//	for(i=1;i<=n;++i)first[i]=0;
//	cnt=0;
	d=s=1;
	for(i=1;i<=m;++i){
		scanf("%lld%lld%lld%lld",&x,&y,&z,&o);
		d=d*z%mod;
		s=s*o%mod;
	}
	printf("%lld\n",((k*k%mod-k+mod)%mod*d%mod+k*s%mod)%mod);
}
ll T;
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	scanf("%lld",&T);
	while(T--)work();
	return 0;
}

