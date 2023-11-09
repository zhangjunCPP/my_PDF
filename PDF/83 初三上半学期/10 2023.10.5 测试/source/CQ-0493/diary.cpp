#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7,N=1e6+10;
char a[N],b[N];
ll pw(ll x,int cnt){
	ll ans=1;
	while(cnt){
		if(cnt&1)ans=ans*x%mod;
		x=x*x%mod;cnt>>=1;
	}
	return ans;
}
ll fac[N],inv[N];
ll C(int x,int y){
	if(x<y||x<0||y<0)return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	inv[n]=pw(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
int main(){
	freopen("diary.in","r",stdin);
	freopen("diary.out","w",stdout);
	scanf("%s%s",a+1,b+1);
	int la=strlen(a+1),lb=strlen(b+1);
	for(int i=1;i<=lb;i++)if(b[i]!='1'){
		printf("0");
		return 0;
	}
	init(1e6);
	int now=0;ll ans=0;
	for(int i=1;i<=la&&now<lb;i++)if(a[i]=='1'){
		ans=(ans+C(la-i,lb-now))%mod;
		now++;
	}
	printf("%lld",(ans+(now==lb))%mod);
	return 0;
}
