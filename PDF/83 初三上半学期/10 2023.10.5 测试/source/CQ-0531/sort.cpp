#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=7e5+5;
ll n;
ll dp[N];
vector<ll> s;
ll ans;
void solve(vector<ll> a){
	ll len=a.size();
	if(len<=1) return;
	ll mid=a[(len-1)/2];
	vector<ll> al,ag;
	for(ll i=0;i<len;i++){
		ans++;
		if(a[i]<mid) al.push_back(a[i]);
		if(a[i]>mid) ag.push_back(a[i]);
	}
	solve(al);solve(ag);
}
ll a[N];
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%lld",&n);
	ll flag=1;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s.push_back(a[i]);
		if(a[i]!=i) flag=0;
	}
	if(flag){
		for(ll i=2;i<=n;i++){
			if(i&1) dp[i]=i+dp[i/2]*2;
			else dp[i]=i+dp[i/2-1]+dp[i/2];
		}
		printf("%lld",dp[n]);
		return 0;
	}
	solve(s);
	printf("%lld",ans);
	return 0;
}
