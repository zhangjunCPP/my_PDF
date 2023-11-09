#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[200005];
int n,q;
long long ans;
long long gcd(long long u,long long v){
	while(v!=0ll){
		long long tmp=v;
		v=u%v;
		u=tmp;
	}
	return u;
}
long long two(int x){
	long long p=2ll,c=1ll;
	while(x){
		if(x&1ll) c=(c*p)%MOD;
		x>>=1,p=(p*p)%MOD;
	}
	return c;
}
void dfs(int l,int r,long long now){
	if(l==r+1){
		if(now) ans=(ans*now)%MOD;
		return;
	}
	if(now==1ll)
		return;
	if(now) dfs(l+1,r,gcd(now,a[l]));
	else dfs(l+1,r,a[l]);
	dfs(l+1,r,now);
}
int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		ans=1ll;
		dfs(l,r,0ll);
		cout<<ans<<endl;
	}
	return 0;
} 
