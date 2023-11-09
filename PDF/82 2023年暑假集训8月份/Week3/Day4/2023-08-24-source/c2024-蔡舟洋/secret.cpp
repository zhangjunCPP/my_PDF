/*
get only 13pts.iam sb.
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=(1<<16)-1;
int k;
ll pos[56],n;
ll ksm(ll a,ll b){
	ll r=1;while(b){
		if(b&1)r=r*a%mod;
		a=a*a%mod,b>>=1;
	}return r;
}
ll cnt;
void solve(){
	scanf("%d",&k);n=0;cnt=1;
	for(int i=1;i<=k;i++){
		int x,l;scanf("%d%d",&x,&l);
		ll ps=1;
		for(int o=1;o<=l;o++)pos[++n]=x,ps=ps*o;
		cnt=cnt*ps;
	}
	ll ans=1;
	do{
		ll ths=0;
		for(int i=1;i<=n;i++)ths=(ths*256%mod+pos[i])%mod;
		ths=ksm(ths,cnt);
		ans=ans*ths%mod;
	}while(next_permutation(pos+1,pos+1+n));
	printf("%lld\n",ans);
}
int main(){
	freopen("secret.in","r",stdin);
	freopen("secret.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--)solve();
	return 0;
}
/*
1
4
3 2
4 2
5 3
6 3
*/
