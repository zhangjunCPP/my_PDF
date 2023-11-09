#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n;
map<ll,ll>c;
int main(){//30
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(ll i=1;i<=n*n;i++){
			c[i]=0;
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i;j<=n;j++){
				if(i==j)c[i*j]++;
				else c[i*j]+=2;
			}
		}
		ll sum=0;
		for(ll i=1;i<=n*n;i++){
			sum+=c[i]*c[i];
		}
		printf("%lld\n",sum);
	}
	return 0;
}

