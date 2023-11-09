#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll rd(ll x=0){scanf("%lld",&x);return x;}
ll n;
const int N=1e6;
ll f[N],k[N];
void solve(){
	n=rd();
	printf("%lld\n",f[n]);
}
ll phi[N],sum[N];
void get_phi(ll x){
	ll phi=x;ll tmp=x;
	for(int i=2;i*i<=x;i++)if(x%i==0){
		phi-=phi/i;
		while(x%i==0)x/=i;
	}if(x>1)phi-=phi/x;
	::phi[tmp]=phi;
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(n=1;n<=200000;n++){
		get_phi(n);
		f[n]=f[n-1];
		for(ll i=1;i*i<=n;i++){
			if(n%i==0){
				f[n]+=k[i]*2;
				if(i!=n/i)f[n]+=k[n/i]*2;
			}
		}
		for(ll i=1;i*i<=n;i++){
			if(n%i==0){
				if(n==1)continue;
				f[n]+=phi[n/i]*2*i;
				k[n/i]+=phi[n/i];
				if(i==1||n/i==i)continue;
				f[n]+=phi[i]*2*n/i;
				k[i]+=phi[i];
			}
		}
		f[n]+=2*n-1;
	}
	int t=rd();
	while(t--)solve(); 
	return 0;
}
/*
6
1
12
123
1234
12345
123456
*/
