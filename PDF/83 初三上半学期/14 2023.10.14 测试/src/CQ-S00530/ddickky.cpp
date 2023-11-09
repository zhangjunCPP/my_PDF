/*
9pts非常好拿
dfs即可


*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,q,ask[20][20],a[20];
ll gcd(ll x,ll y){
	if(!x)return y;
	if(!y)return x;
	while(y^=x^=y^=x%=y);
	return x;
}
void dfs(ll now,ll s,ll l,ll r){
	if(now>n){
		if(!r)return;
		for(ll i=l;i;--i)for(ll j=r;j<=n;++j)(ask[i][j]*=s)%=mod;
		return;
	}
	dfs(now+1,gcd(s,a[now]),!l?now:l,now);
	dfs(now+1,s,l,r);
}
ll i,j,x,y;
int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(i=1;i<=n;++i){
		scanf("%lld",a+i);
		for(j=i;j<=n;++j)ask[i][j]=1;
	}
	dfs(1,0,0,0);
	while(q--){
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",ask[x][y]);
	}
	return 0;
}
/*
3 1
2 4 3
1 3
*/
/*
5 2
8 2 8 8 9
1 5
2 4
*/
