#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
#define pb push_back
const ll N=1e6+10;
using namespace std;

ll n;



void mian(){
	
	ll ans=0;
	scanf("%lld",&n);
	For(i,1,n){
		For(j,1,n){
			ll t=i*j;
			For(k,1,n){
				if(t%k==0&&t/k<=n)++ans;
			}
		}
	}
	printf("%lld\n",ans);
	
}

int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int T=1;
	scanf("%d",&T);
	while(T--)mian();
	return 0;
}
