#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
#define pb push_back
const ll N=2e5+10;
const ll p=998244353;
using namespace std;
ll ksm(ll a,ll b){ll bns=1;for(;b;b>>=1,a=a*a%p)if(b&1)bns=bns*a%p;return bns;}

ll n,q;
ll a[N];
ll ANS[18][18];

void init_1(){
	For(l,1,n){
		For(r,l,n){
			ANS[l][r]=1;
			ll t=(1<<r)-(1<<(l-1));
			For(i,1,(1<<n)-1){
				if((i&t)!=i)continue;
				ll res=0;
				For(j,1,n){
					if((1<<(j-1))&i){
						res=__gcd(res,a[j]);
					}
				}
				ANS[l][r]=ANS[l][r]*res%p;
			}
		}
	}
}

void mian(){
	
	ll flag=1;
	scanf("%lld%lld",&n,&q);
	For(i,1,n){
		scanf("%lld",&a[i]);
		if(a[i]>450)flag=0;
	}
	if(n<=17)init_1();
	while(q--){
		ll l,r;
		scanf("%lld%lld",&l,&r);
		if(n<=17){
			printf("%lld\n",ANS[l][r]);
			continue;
		}
	}
	
}

int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	int T=1;
//	scanf("%d",&T);
	while(T--)mian();
	return 0;
}
/*
Long ago, people prayed for a wish,
to a star who floated in the sky.
Only artifacts can be seen there,
no matter how much we try.
Instead of natural scintillation,
they always mechanically blink.
No one believes fairytales anymore,
but the two hearts in sync,
to wish upon a satellite.
*/
