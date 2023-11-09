#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7+17;
ll n,mod;
ll jc[N],v[N];//,sum[N];
ll ans;
int main() {
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	scanf("%lld%lld",&n,&mod);
	jc[1]=1; ans=ans^0^0;
	for(int i=2;i<=n;i++) jc[i]=( jc[i-1]*i )%mod;
	for(int i=3;i<=n;i++) {
		
		v[i]=jc[i-2]*( (i-2)*(i-1)/2 )%mod;
		
		v[i]=( v[i]+( (i-1)*v[i-2] )%mod )%mod;
		
		v[i]=( v[i]+v[i-1] )%mod;
		
		//sum[i]=( sum[i-1]+v[i] )%mod;
		
		ans= ans^v[i] ;
		
		//cout<<v[i]<<" ";
	}
	printf("%lld",ans);
	return 0;
}
