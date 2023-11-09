/*
t3
±©Á¦ 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10,mod=998244353;
ll i,n,mx[N],j,key[N];
vector<ll>a[N],more[N];
void get_key(){
	for(i=1;i<=n;++i)mx[i]=*a[i].rbegin();
	for(i=1;i<n;++i){
		ll l=0,r=a[i].size()-1,id;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(a[i][mid]<=mx[i])id=mid,l=mid+1;
			else r=mid-1;
		}
		mx[i]=a[i][id];
		for(j=i+1;j<=n;++j){
			if((*a[j].begin())<mx[i]){
				++key[i];
				mx[j]=min(mx[i]-1,mx[j]);
				more[i].push_back(j);
			}
		}
	}
}
ll m,x,ans,b[N];
void dfs(ll now){
	if(!now){
//		for(ll i=1;i<=n;++i)printf("%lld ",b[i]);putchar(10);
		(++ans)%=mod;
		return;
	}
	ll mx=0;
	for(ll i:more[now])mx=max(mx,b[i]);
	for(ll j=a[now].size()-1;~j;--j){
		ll x=a[now][j];
		if(x<=mx)return;
		b[now]=x;
		dfs(now-1);
	}
}
int main(){
	freopen("marketeers.in","r",stdin);
	freopen("marketeers.out","w",stdout);
	scanf("%lld",&n);
	for(i=1;i<=n;++i){
		scanf("%lld",&m);
		for(j=1;j<=m;++j){
			scanf("%lld",&x);
			a[i].push_back(x);
		}
		sort(a[i].begin(),a[i].end());
	}
	get_key();
//	puts("finish");
//	printf("key:");for(i=1;i<=n;++i)printf("%lld ",key[i]);putchar(10);
	dfs(n);
	printf("%lld",ans);
	return 0;
}
/*
4
2
2 1 
3
5 1 6 
1
3
3
6 5 7
*/
