#include<bits/stdc++.h>
using namespace std;
int n,mod;
long long ans,dp1=1,dp2=2,inv2,pre=2,now;
long long power(long long a,long long b){
	long long res=1%mod;
	for(;b;b>>=1){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
	}
	return res;
}
int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	
	scanf("%d%d",&n,&mod);
	if(n<=2){
		printf("0");
		return 0;
	}
	inv2=power(2,mod-2);
	for(int i=3;i<=n;i++){
		pre=1ll*i*pre%mod;
		now=(dp2+1ll*(i-1)*dp1%mod)%mod;
		ans^=(((pre-now+mod)%mod)*inv2%mod);
		dp1=dp2;
		dp2=now;
	}
	printf("%lld",ans);
	return 0;
}
