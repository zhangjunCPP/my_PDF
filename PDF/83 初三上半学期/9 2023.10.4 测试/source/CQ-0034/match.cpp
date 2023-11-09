#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
#define pb push_back
const ll N=1e6+10;
using namespace std;

ll n,m,k,q;
char s[N],t[N];



void mian(){
	
	scanf("%lld",&k);
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%lld",&q);
	while(q--){
		scanf("%s",t+1);
		m=strlen(t+1);
		ll ans=0;
		For(i,1,n-m+1){
			ll l=i,r=i+m-1;
			while(s[l]==t[l-i+1]&&l<=r)++l;
			while(s[r]==t[r-i+1]&&l<=r)--r;
			if(r-l<k)++ans;
		}
		printf("%lld\n",ans);
	}
	
}

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T=1;
	while(T--)mian();
	return 0;
}
